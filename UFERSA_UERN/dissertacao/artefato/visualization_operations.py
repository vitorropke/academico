import colorsys

import folium
from cartopy import crs
from cartopy.io.img_tiles import OSM
from cartopy.mpl.geoaxes import GeoAxes
from folium import Map, CustomIcon, Icon
from matplotlib import pyplot as plt
from matplotlib.figure import Figure
from pandas import DataFrame


def convert_point_names_to_coords(inst: DataFrame, hubs: list[str], cycles: list[list[list[str]]]) -> tuple[
    list[tuple[float, float]], list[list[list[tuple[float, float]]]]]:
    all_coords: dict[str, tuple[float, float]] = dict(zip(inst.index, zip(inst['latitude'], inst['longitude'])))
    hub_coords: list[tuple[float, float]] = [all_coords[hub] for hub in hubs]
    cycle_coords: list[list[list[tuple[float, float]]]] = [[[all_coords[point] for point in cycle] for cycle in cluster]
                                                           for cluster in cycles]

    return hub_coords, cycle_coords


def set_colors_for_points(cycles: list[list[list[tuple[float, float]]]]) -> dict[tuple[float, float], str]:
    colors: dict[tuple[float, float], str] = {}

    num_clusters: int = len(cycles)
    hue_step: float = 1.0 / num_clusters
    curr_hue: float = 0.0
    for cluster in cycles:
        num_cycles: int = len(cluster)
        saturation_step: float = 1.0 / num_cycles
        curr_saturation: float = 1.0
        for cycle in cluster:
            r: int
            g: int
            b: int
            r, g, b = (round(number=(component * 255)) for component in
                       colorsys.hsv_to_rgb(h=curr_hue, s=curr_saturation, v=1.0))

            for point in cycle[1:-1]:
                colors[point] = f'#{r:02x}{g:02x}{b:02x}'

            curr_saturation -= saturation_step
        curr_hue += hue_step

    return colors


def get_icon(point: str, latitude: float, longitude: float, major_hub: str, hubs: list[tuple[float, float]],
             colors: dict[tuple[float, float], str]) -> Icon | CustomIcon:
    if point == major_hub:
        return folium.CustomIcon(icon_image='https://static.thenounproject.com/png/hub-icon-2367012-512.png',
                                 icon_size=(50, 50))
    elif (latitude, longitude) in hubs:
        return folium.CustomIcon(
            icon_image='https://upload.wikimedia.org/wikipedia/commons/9/90/Simbolo_autostazione_-_1979.svg',
            icon_size=(50, 50))
    else:
        return folium.Icon(icon_color=colors[(latitude, longitude)], icon='bus-simple', prefix='fa')


def generate_interactive_map(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                             cycles: list[list[list[tuple[float, float]]]], colors: dict[tuple[float, float], str],
                             filepath: str) -> None:
    interactive_map: Map = folium.Map(location=((inst.loc[:, 'latitude'].max() + inst.loc[:, 'latitude'].min()) / 2.0, (
            inst.loc[:, 'longitude'].max() + inst.loc[:, 'longitude'].min()) / 2.0), tiles='CartoDB Positron',
                                      zoom_start=13, control_scale=True)

    for point, latitude, longitude in zip(inst.index, inst.loc[:, 'latitude'], inst.loc[:, 'longitude']):
        folium.Marker(location=(latitude, longitude), tooltip=point,
                      icon=get_icon(point=point, latitude=latitude, longitude=longitude, major_hub=major_hub, hubs=hubs,
                                    colors=colors)).add_to(parent=interactive_map)

    for i in range(len(cycles)):
        for j in range(len(cycles[i])):
            # Select any point on the cycle, except the first or the last, which are the hub. In this case, just the
            # second.
            color: str = colors[cycles[i][j][1]]
            folium.PolyLine(locations=cycles[i][j], color=color).add_to(interactive_map)
    for i in range(len(hubs)):
        folium.PolyLine(locations=(hubs[i], (inst.loc[major_hub, 'latitude'], inst.loc[major_hub, 'longitude'])),
                        color='grey', weight=8).add_to(interactive_map)

    interactive_map.save(outfile=filepath)


def generate_static_map(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                        colors: dict[tuple[float, float], str], filepath: str) -> None:
    imagery: OSM = OSM()
    fig: Figure = plt.figure()
    ax: GeoAxes = fig.add_subplot(projection=imagery.crs)
    ax.set_extent(
        extents=(inst['longitude'].min() - 0.01, inst['longitude'].max() + 0.01, inst['latitude'].min() - 0.01,
                 inst['latitude'].max() + 0.01), crs=crs.PlateCarree())

    ax.add_image(imagery, 14)

    for point, latitude, longitude in zip(inst.index, inst.loc[:, 'latitude'], inst.loc[:, 'longitude']):
        if point == major_hub:
            ax.plot(longitude, latitude, color='black', linestyle='', marker='*', markersize=5,
                    transform=crs.PlateCarree())
        elif (latitude, longitude) in hubs:
            ax.plot(longitude, latitude, color='black', linestyle='', marker='P', markersize=3,
                    transform=crs.PlateCarree())
        else:
            ax.plot(longitude, latitude, color=colors[(latitude, longitude)], linestyle='', marker='o', markersize=1,
                    transform=crs.PlateCarree())
    plt.savefig(fname=filepath, bbox_inches='tight', pad_inches=0.0)
