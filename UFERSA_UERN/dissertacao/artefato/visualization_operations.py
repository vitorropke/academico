import folium
from cartopy import crs
from cartopy.io.img_tiles import OSM
from cartopy.mpl.geoaxes import GeoAxes
from folium import Map
from matplotlib import pyplot as plt
from matplotlib.figure import Figure
from pandas import DataFrame


def generate_interactive_map(instance: DataFrame, filepath: str) -> None:
    m: Map = folium.Map(
        location=(
            (instance['latitude'].max() + instance['latitude'].min()) / 2.0,
            (instance['longitude'].max() + instance['longitude'].min()) / 2.0
        ),
        zoom_start=13,
        control_scale=True
    )

    for index, latitude, longitude in zip(instance.index, instance['latitude'], instance['longitude']):
        folium.Marker(
            location=[latitude, longitude],
            tooltip=index,
            icon=folium.Icon()
        ).add_to(parent=m)

    m.save(outfile=filepath)


def generate_static_map(instance: DataFrame, filepath: str) -> None:
    imagery: OSM = OSM()
    fig: Figure = plt.figure()
    ax: GeoAxes = fig.add_subplot(projection=imagery.crs)
    ax.set_extent(
        extents=(
            instance['longitude'].min() - 0.01,
            instance['longitude'].max() + 0.01,
            instance['latitude'].min() - 0.01,
            instance['latitude'].max() + 0.01
        ),
        crs=crs.PlateCarree()
    )

    ax.add_image(imagery, 14)

    ax.plot(instance['longitude'], instance['latitude'], color='red', linestyle='', marker='o', markersize=1,
              transform=crs.PlateCarree())

    plt.savefig(fname=filepath, bbox_inches='tight', pad_inches=0.0)
