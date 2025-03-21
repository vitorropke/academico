import colorsys
import networkx as nx
import numpy as np
import pandas as pd
from graphviz import Graph
from matplotlib import pyplot as plt
from pandas import DataFrame
from sklearn.manifold import MDS


def generate_cluster_map(instance: DataFrame, clusters: np.ndarray[np.int32], hubs: np.ndarray[np.int64]) -> None:
    plt.clf()
    colors: list[str] = get_colors(cycles=len(instance['cluster'].unique()))
    for i in range(len(np.unique(ar=clusters))):
        current_cluster_data: pd.Index(str | int) = instance.index[np.where(clusters == i)[0]]
        current_hub_data: str | int = instance.index[hubs[i]]
        plt.scatter(x=instance.loc[current_cluster_data, 'longitude'], y=instance.loc[current_cluster_data, 'latitude'],
                    c=colors[i], label=f'Cluster {i}')
        plt.scatter(x=instance.loc[current_hub_data, 'longitude'], y=instance.loc[current_hub_data, 'latitude'], s=150,
                    c=colors[i], marker='x', label=f'Hub {i}')
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


def generate_graph(instance: DataFrame, clusters_cycles: list[list[list[str | int]]], hubs_cycle: list[str | int]) -> None:
    graph: Graph = Graph(engine='neato')

    # Nodes.
    colors: list[list[str]] = get_colors(cycles=clusters_cycles)
    for i, point in enumerate(instance.itertuples()):
        graph.node(name=str(point.Index), color=colors[point.cluster], label=str(point.cluster),
                   pos=f'{point.longitude * 1000},{point.latitude * 1000}!', shape=('box' if point.hub else 'ellipse'))

    # Clusters cycle.
    for cluster_cycle in clusters_cycles:
        cluster: int = instance.loc[cluster_cycle[0], 'cluster']
        print(cluster)
        for i in range(len(cluster_cycle) - 1):
            graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
                       color=colors[cluster], penwidth='1')
    # Hubs cycle.
    for i in range(len(hubs_cycle) - 1):
        graph.edge(tail_name=str(hubs_cycle[i]), head_name=str(hubs_cycle[i + 1]), penwidth='100')

    graph.render(filename='outputs/graph', format='pdf')


def generate_map(instance: DataFrame, cycles: list[list[str | int]]):
    graph = nx.Graph()

    # Nodes.
    colors: list[str] = get_colors(cycles=len(instance['cluster'].unique()))
    for i, point in enumerate(instance.itertuples()):
        graph.add_node(i, pos=(point.latitude, point.longitude))

    # Clusters cycle.
    for cluster_cycle in cycles[0]:
        cluster: int = instance.loc[cluster_cycle[0], 'cluster']
        for i in range(len(cluster_cycle) - 1):
            graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
                       color=colors[cluster], penwidth='1')


def get_colors(cycles: list[list[list[str | int]]]) -> list[str]:
    number_of_cycles: int = len(cycles)

    for current_cycle in cycles:
        number_of_sub_cycles: int = len(current_cycle)
        print(len(current_cycle))
    exit(0)
    colors: list[str] = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black', 'gray']

    return colors[:cycles]
