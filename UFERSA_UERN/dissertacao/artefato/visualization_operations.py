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


def get_icon(point: str, lat: float, lon: float, major_hub: str, hubs: list[tuple[float, float]],
             colors: dict[tuple[float, float], str]) -> Icon | CustomIcon:
    if point == major_hub:
        return folium.CustomIcon(icon_image='https://static.thenounproject.com/png/hub-icon-2367012-512.png',
                                 icon_size=(50, 50))
    elif (lat, lon) in hubs:
        return folium.CustomIcon(
            icon_image='https://upload.wikimedia.org/wikipedia/commons/9/90/Simbolo_autostazione_-_1979.svg',
            icon_size=(50, 50))
    else:
        return folium.Icon(icon_color=colors[(lat, lon)], icon='bus-simple', prefix='fa')


def generate_interactive_map(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                             cycles: list[list[list[tuple[float, float]]]], colors: dict[tuple[float, float], str],
                             filepath: str) -> None:
    interactive_map: Map = folium.Map(location=((inst.loc[:, 'latitude'].max() + inst.loc[:, 'latitude'].min()) / 2.0, (
            inst.loc[:, 'longitude'].max() + inst.loc[:, 'longitude'].min()) / 2.0), tiles='CartoDB Positron',
                                      zoom_start=13, control_scale=True)

    for point, lat, lon in zip(inst.index, inst.loc[:, 'latitude'], inst.loc[:, 'longitude']):
        folium.Marker(location=(lat, lon), tooltip=point,
                      icon=get_icon(point=point, lat=lat, lon=lon, major_hub=major_hub, hubs=hubs,
                                    colors=colors)).add_to(parent=interactive_map)

    for i in range(len(cycles)):
        for j in range(len(cycles[i])):
            # Select any point on the cycle, except the first or the last, which is the hub.
            # In this case is the second point of the cycle.
            color: str = colors[cycles[i][j][1]]
            folium.PolyLine(locations=cycles[i][j], color=color).add_to(interactive_map)
    for i in range(len(hubs)):
        folium.PolyLine(locations=(hubs[i], (inst.loc[major_hub, 'latitude'], inst.loc[major_hub, 'longitude'])),
                        color='grey', weight=8).add_to(interactive_map)

    interactive_map.save(outfile=f'{filepath}.html')


def plot_points(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                colors: dict[tuple[float, float], str], ax: GeoAxes) -> None:
    for point, lat, lon in zip(inst.index, inst.loc[:, 'latitude'], inst.loc[:, 'longitude']):
        if point == major_hub:
            ax.plot(lon, lat, color='black', linestyle='', marker='*', markersize=8, transform=crs.PlateCarree())
        elif (lat, lon) in hubs:
            ax.plot(lon, lat, color='black', linestyle='', marker='P', markersize=5, transform=crs.PlateCarree())
        else:
            ax.plot(lon, lat, color=colors[(lat, lon)], linestyle='', marker='o', markersize=1,
                    transform=crs.PlateCarree())


def plot_routes(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                cycles: list[list[list[tuple[float, float]]]], colors: dict[tuple[float, float], str],
                ax: GeoAxes) -> None:
    for i in range(len(cycles)):
        for j in range(len(cycles[i])):
            # Select any point on the cycle, except the first or the last, which is the hub.
            # In this case is the second point of the cycle.
            color: str = colors[cycles[i][j][1]]
            for orig, dest in zip(cycles[i][j], cycles[i][j][1:]):
                lon: list[float, float] = [orig[1], dest[1]]
                lat: list[float, float] = [orig[0], dest[0]]
                ax.plot(lon, lat, color=color, linewidth=1, transform=crs.PlateCarree())
    for i in range(len(hubs)):
        lon: list[float, float] = [hubs[i][1], inst.loc[major_hub, 'longitude']]
        lat: list[float, float] = [hubs[i][0], inst.loc[major_hub, 'latitude']]
        ax.plot(lon, lat, color='grey', linewidth=3, transform=crs.PlateCarree())


def generate_static_map(inst: DataFrame, major_hub: str, hubs: list[tuple[float, float]],
                        cycles: list[list[list[tuple[float, float]]]], colors: dict[tuple[float, float], str],
                        filepath: str) -> None:
    filepaths: list[str] = [f'{filepath}_points', f'{filepath}_routes', filepath]
    for i in range(3):
        imagery: OSM = OSM()
        fig: Figure = plt.figure()
        ax: GeoAxes = fig.add_subplot(projection=imagery.crs)
        ax.set_extent(
            extents=(inst['longitude'].min() - 0.01, inst['longitude'].max() + 0.01, inst['latitude'].min() - 0.01,
                     inst['latitude'].max() + 0.01), crs=crs.PlateCarree())
        ax.add_image(imagery, 14)

        if i == 0:
            plot_points(inst=inst, major_hub=major_hub, hubs=hubs, colors=colors, ax=ax)
        elif i == 1:
            plot_routes(inst=inst, major_hub=major_hub, hubs=hubs, cycles=cycles, colors=colors, ax=ax)
        else:
            plot_points(inst=inst, major_hub=major_hub, hubs=hubs, colors=colors, ax=ax)
            plot_routes(inst=inst, major_hub=major_hub, hubs=hubs, cycles=cycles, colors=colors, ax=ax)

        plt.savefig(fname=f'{filepaths[i]}.pdf', bbox_inches='tight', pad_inches=0.0)
        plt.close(fig=fig)
