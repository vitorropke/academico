import colorsys

import folium
from cartopy import crs
from cartopy.io.img_tiles import OSM
from cartopy.mpl.geoaxes import GeoAxes
from folium import Map, CustomIcon
from matplotlib import pyplot as plt
from matplotlib.figure import Figure
from pandas import DataFrame, Series


def convert_point_names_to_coords(inst: DataFrame, hubs: list[str], cycles: list[list[list[str]]]) -> tuple[
    list[tuple[float, float]], list[list[list[tuple[float, float]]]]]:
    coords_dict: dict[str, tuple[float, float]] = dict(zip(inst.index, zip(inst['latitude'], inst['longitude'])))
    hub_coords: list[tuple[float, float]] = [coords_dict[hub] for hub in hubs]
    cycle_coords: list[list[list[tuple[float, float]]]] = [
        [[coords_dict[point] for point in cycle] for cycle in subclusters] for subclusters in cycles]

    return hub_coords, cycle_coords


def get_colors(cycles: list[list[list[str]]]) -> list[list[str]]:
    num_clusters: int = len(cycles)
    colors: list[list[str]] = [['' for _ in range(len(cycles[i]))] for i in range(num_clusters)]

    curr_hue: float = 0.0
    hue_step: float = 1.0 / num_clusters
    for i in range(num_clusters):
        num_subclusters: int = len(cycles[i])
        curr_saturation: float = 1.0
        saturation_step: float = 1.0 / num_subclusters
        for j in range(num_subclusters):
            r: int
            g: int
            b: int
            r, g, b = (round(number=(component * 255)) for component in
                       colorsys.hsv_to_rgb(h=curr_hue, s=curr_saturation, v=1.0))
            colors[i][j] = f'#{r:02x}{g:02x}{b:02x}'
            curr_saturation -= saturation_step
        curr_hue += hue_step

    return colors


def generate_interactive_map(inst: DataFrame, central_point: Series, hubs: list[tuple[float, float]],
                             cycles: list[list[list[tuple[float, float]]]], colors: list[list[str]],
                             filepath: str) -> None:
    interactive_map: Map = folium.Map(location=((inst.loc[:, 'latitude'].max() + inst.loc[:, 'latitude'].min()) / 2.0, (
            inst.loc[:, 'longitude'].max() + inst.loc[:, 'longitude'].min()) / 2.0), tiles='CartoDB Positron',
                                      zoom_start=13, control_scale=True)

    hub_icon: CustomIcon = folium.CustomIcon(
        icon_image='https://upload.wikimedia.org/wikipedia/commons/9/90/Simbolo_autostazione_-_1979.svg',
        icon_size=(50, 50))
    for index, latitude, longitude, cluster, subcluster in zip(inst.index, inst.loc[:, 'latitude'],
                                                               inst.loc[:, 'longitude'], inst.loc[:, 'cluster'],
                                                               inst.loc[:, 'subcluster']):
        folium.Marker(location=(latitude, longitude), tooltip=index, icon=(
            hub_icon if (latitude, longitude) in hubs else folium.Icon(icon_color=colors[cluster][subcluster],
                                                                       icon='bus-simple', prefix='fa'))).add_to(
            parent=interactive_map)

    folium.Marker(location=(central_point.loc['latitude'], central_point.loc['longitude']), tooltip=central_point.name,
                  icon=hub_icon).add_to(parent=interactive_map)

    for i in range(len(cycles)):
        for j in range(len(cycles[i])):
            folium.PolyLine(locations=cycles[i][j], color=colors[i][j]).add_to(interactive_map)

    for i in range(len(hubs)):
        folium.PolyLine(locations=(hubs[i], (central_point.loc['latitude'], central_point.loc['longitude'])),
                        color='grey', weight=8).add_to(interactive_map)

    interactive_map.save(outfile=filepath)


def generate_static_map(inst: DataFrame, central_point: Series, hubs: list[tuple[float, float]],
                        cycles: list[list[list[tuple[float, float]]]], filepath: str) -> None:
    imagery: OSM = OSM()
    fig: Figure = plt.figure()
    ax: GeoAxes = fig.add_subplot(projection=imagery.crs)
    ax.set_extent(
        extents=(inst['longitude'].min() - 0.01, inst['longitude'].max() + 0.01, inst['latitude'].min() - 0.01,
                 inst['latitude'].max() + 0.01), crs=crs.PlateCarree())

    ax.add_image(imagery, 14)

    ax.plot(inst['longitude'], inst['latitude'], color='red', linestyle='', marker='o', markersize=1,
            transform=crs.PlateCarree())

    plt.savefig(fname=filepath, bbox_inches='tight', pad_inches=0.0)
