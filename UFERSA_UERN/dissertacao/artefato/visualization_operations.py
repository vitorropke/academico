import colorsys

import folium
from cartopy import crs
from cartopy.io.img_tiles import OSM
from cartopy.mpl.geoaxes import GeoAxes
from folium import Map
from matplotlib import pyplot as plt
from matplotlib.figure import Figure
from pandas import DataFrame, Series


def get_colors(cycles: list[list[list[str]]]) -> list[list[str]]:
    number_of_clusters: int = len(cycles)
    colors: list[list[str]] = [['' for _ in range(len(cycles[i]))] for i in range(number_of_clusters)]

    current_hue: float = 0.0
    hue_step: float = 1.0 / number_of_clusters
    for i in range(number_of_clusters):
        number_of_subclusters: int = len(cycles[i])
        current_saturation: float = 1.0
        saturation_step: float = 1.0 / number_of_subclusters
        for j in range(number_of_subclusters):
            r: int
            g: int
            b: int
            r, g, b = (round(number=(component * 255)) for component in
                       colorsys.hsv_to_rgb(h=current_hue, s=current_saturation, v=1.0))
            colors[i][j] = f'#{r:02x}{g:02x}{b:02x}'
            current_saturation -= saturation_step
        current_hue += hue_step

    return colors


def generate_interactive_map(instance: DataFrame, central_point: Series, hubs: list[str], cycles: list[list[list[str]]],
                             colors: list[list[str]], filepath: str) -> None:
    interactive_map: Map = folium.Map(location=((instance['latitude'].max() + instance['latitude'].min()) / 2.0,
                                                (instance['longitude'].max() + instance['longitude'].min()) / 2.0),
                                      zoom_start=13, control_scale=True)

    for index, latitude, longitude, cluster, subcluster in zip(instance.index, instance['latitude'],
                                                               instance['longitude'], instance['cluster'],
                                                               instance['subcluster']):
        folium.Marker(location=[latitude, longitude], tooltip=index,
                      icon=folium.Icon(icon_color=colors[cluster][subcluster])).add_to(parent=interactive_map)
    folium.Marker(location=[central_point['latitude'], central_point['longitude']], tooltip=central_point.name,
                  icon=folium.Icon(color='black', icon='fa-brands fa-hubspot')).add_to(parent=interactive_map)

    coordinates_map: dict = instance[['latitude', 'longitude']].apply(func=tuple, axis='columns').to_dict()
    coordinates_map.update({central_point.name: (central_point['latitude'], central_point['longitude'])})
    coordinates_cycles = [[[coordinates_map[point] for point in cycle] for cycle in subcluster] for subcluster in
                          cycles]

    for i in range(len(cycles)):
        for j in range(len(cycles[i])):
            folium.PolyLine(locations=coordinates_cycles[i][j], color=colors[i][j]).add_to(interactive_map)

    for i in range(len(hubs)):
        folium.PolyLine(locations=[coordinates_map[hubs[i]], coordinates_map[central_point.name]], color="#FFA500",
                        weight=8).add_to(interactive_map)

    interactive_map.save(outfile=filepath)


def generate_static_map(instance: DataFrame, central_point: Series, hubs: list[str], cycles: list[list[list[str]]],
                        filepath: str) -> None:
    imagery: OSM = OSM()
    fig: Figure = plt.figure()
    ax: GeoAxes = fig.add_subplot(projection=imagery.crs)
    ax.set_extent(extents=(instance['longitude'].min() - 0.01, instance['longitude'].max() + 0.01,
                           instance['latitude'].min() - 0.01, instance['latitude'].max() + 0.01), crs=crs.PlateCarree())

    ax.add_image(imagery, 14)

    ax.plot(instance['longitude'], instance['latitude'], color='red', linestyle='', marker='o', markersize=1,
            transform=crs.PlateCarree())

    plt.savefig(fname=filepath, bbox_inches='tight', pad_inches=0.0)
