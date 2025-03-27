import colorsys
import networkx as nx
import numpy as np
import pandas as pd
from graphviz import Graph
from matplotlib import pyplot as plt
from pandas import DataFrame
from sklearn.manifold import MDS


def generate_cluster_map(instance: DataFrame, clusters: np.ndarray[np.int32], sub_clusters: np.ndarray[np.int32],
                         hubs: np.ndarray[np.int64], cycles: list[list[list[str | int]]]) -> None:
    plt.clf()
    colors: list[list[str]] = get_colors(cycles=cycles)
    for current_cluster in np.unique(ar=clusters):
        current_cluster_data: pd.Index(str | int) = instance.index[np.where(clusters == current_cluster)[0]]
        for current_sub_cluster in np.unique(ar=sub_clusters):
            print(len(sub_clusters))
            current_sub_cluster_data: pd.Index(str | int) = current_cluster_data[
                np.where(sub_clusters == current_sub_cluster)[0]]
            plt.scatter(x=instance.loc[current_sub_cluster_data, 'longitude'],
                        y=instance.loc[current_sub_cluster_data, 'latitude'],
                        c=colors[current_cluster][current_sub_cluster], label=f'Cluster {current_cluster}.{current_sub_cluster}')

        current_hub_data: str | int = instance.index[hubs[current_cluster]]
        plt.scatter(x=instance.loc[current_hub_data, 'longitude'], y=instance.loc[current_hub_data, 'latitude'], s=150,
                    c=colors[current_cluster], marker='x', label=f'Hub {current_cluster}')

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
                   hubs_cycle: list[str | int]) -> None:
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
    # Hubs cycle.
    for i in range(len(hubs_cycle) - 1):
        graph.edge(tail_name=str(hubs_cycle[i]), head_name=str(hubs_cycle[i + 1]), penwidth='100')

    graph.render(filename='outputs/graph', format='pdf')


def generate_map(instance: DataFrame, cycles: list[list[list[str | int]]]):
    graph = nx.Graph()

    # Nodes.
    colors: list[list[str]] = get_colors(cycles=cycles)
    for i, point in enumerate(instance.itertuples()):
        graph.add_node(i, pos=(point.latitude, point.longitude))

    # Clusters cycle.
    for cluster_cycle in cycles[0]:
        cluster: int = instance.loc[cluster_cycle[0], 'cluster']
        for i in range(len(cluster_cycle) - 1):
            graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
                       color=colors[cluster], penwidth='1')


def get_colors(cycles: list[list[list[str | int]]]) -> list[list[str]]:
    colors: list[list[str]] = []

    hue_step: float = 1.0 / (len(cycles) - 1)
    current_hue: float = 0.0
    for current_cluster in cycles:
        current_cluster_colors: list[str] = []

        saturation_step: float = 1.0 / (len(current_cluster) - 1)
        current_saturation: float = 0.0
        for i in range(len(current_cluster)):
            current_cluster_colors.append(
                f'{current_hue:.3f} 1.000 {current_saturation:.3f}')

            current_saturation += saturation_step

        current_hue += hue_step

        colors.append(current_cluster_colors)

    return colors
