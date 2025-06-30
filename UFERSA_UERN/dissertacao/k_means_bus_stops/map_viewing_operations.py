import colorsys
import networkx as nx
import numpy as np
from graphviz import Graph
from matplotlib import pyplot as plt
from pandas import DataFrame
from sklearn.manifold import MDS


def convert_color_from_hsv_to_rgb(hsv: str) -> tuple[float, float, float]:
    hue: float
    saturation: float
    value: float
    hue, saturation, value = map(float, hsv.split())

    return colorsys.hsv_to_rgb(h=hue, s=saturation, v=value)


def generate_cluster_map(instance: DataFrame, cycles: list[list[list[str | int]]]) -> None:
    plt.clf()
    colors: list[list[str]] = get_colors(cycles=cycles)

    instance['color'] = instance.apply(
        lambda row: convert_color_from_hsv_to_rgb(colors[row['cluster']][row['sub_cluster']]), axis=1)

    plt.scatter(x=instance['longitude'], y=instance['latitude'], c=instance['color'])

    hubs: DataFrame = instance[instance['hub'] == 1]
    plt.scatter(x=hubs['longitude'], y=hubs['latitude'], s=100, marker='X')

    plt.xlabel('Longitude')
    plt.ylabel('Latitude')

    plt.savefig(fname='outputs/clusters.pdf', transparent=True, bbox_inches='tight')


def generate_coordinates(instance: DataFrame) -> None:
    if not {'longitude', 'latitude'}.issubset(instance.columns):
        mds: MDS = MDS(random_state=42, dissimilarity='precomputed')
        coordinates: np.ndarray[np.float64] = mds.fit_transform(X=instance)

        instance[['longitude', 'latitude']] = coordinates

        plt.clf()
        plt.scatter(x=coordinates[:, 0], y=coordinates[:, 1])
        for i, (x, y) in enumerate(coordinates):
            plt.text(x=x, y=y, s=f'Loc {i}')
        plt.savefig(fname='outputs/map.pdf', transparent=True, bbox_inches='tight')


def generate_graph(instance: DataFrame, clusters_cycles: list[list[list[str | int]]],
                   hubs_trail: list[list[str | int]]) -> None:
    graph: Graph = Graph(engine='neato')

    # Nodes.
    colors: list[list[str]] = get_colors(cycles=clusters_cycles)
    for i, point in enumerate(instance.itertuples()):
        graph.node(name=str(point.Index), color=colors[point.cluster][point.sub_cluster],
                   label=f'{point.cluster}.{point.sub_cluster}',
                   pos=f'{point.longitude * 1000},{point.latitude * 1000}!', shape=('box' if point.hub else 'ellipse'))

    # Clusters cycle.
    for current_cluster_cycle in clusters_cycles:
        cluster: int = instance.loc[current_cluster_cycle[0][0], 'cluster']

        for current_sub_cluster_cycle in current_cluster_cycle:
            sub_cluster: int = instance.loc[current_sub_cluster_cycle[1], 'sub_cluster']

            for i in range(len(current_sub_cluster_cycle) - 1):
                graph.edge(tail_name=str(current_sub_cluster_cycle[i]), head_name=str(current_sub_cluster_cycle[i + 1]),
                           color=colors[cluster][sub_cluster], penwidth='1')
    # Hubs trail.
    for current_adjacency in hubs_trail:
        graph.edge(tail_name=str(current_adjacency[0]), head_name=str(current_adjacency[1]), penwidth='10')

    graph.render(filename='outputs/graphviz_graph', format='pdf')


def generate_map(instance: DataFrame, clusters_cycles: list[list[list[str | int]]],
                 hubs_trail: list[list[str | int]]) -> None:
    plt.clf()
    graph = nx.Graph()

    # Nodes.
    colors: list[list[str]] = get_colors(cycles=clusters_cycles)
    for i, point in enumerate(instance.itertuples()):
        graph.add_node(i, pos=(point.latitude, point.longitude))

    # Clusters cycle.
    # for cluster_cycle in cycles[0]:
    #     cluster: int = instance.loc[cluster_cycle[0], 'cluster']
    #     for i in range(len(cluster_cycle) - 1):
    #         graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
    #                    color=colors[cluster], penwidth='1')

    nx.draw(G=graph)
    plt.savefig(fname='outputs/networkx_graph.pdf', transparent=True, bbox_inches='tight')


def get_colors(cycles: list[list[list[str | int]]]) -> list[list[str]]:
    colors: list[list[str]] = []

    hue_step: float = 1.0 / (len(cycles))
    current_hue: float = 0.0
    for current_cluster in cycles:
        current_cluster_colors: list[str] = []

        saturation_step: float = 1.0 / (len(current_cluster))
        current_saturation: float = saturation_step
        for i in range(len(current_cluster)):
            current_cluster_colors.append(
                f'{current_hue:.3f} {current_saturation:.3f} 1.000')

            current_saturation += saturation_step

        current_hue += hue_step

        colors.append(current_cluster_colors)

    return colors
