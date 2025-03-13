import networkx as nx
import numpy as np
from graphviz import Graph
from matplotlib import pyplot as plt
from pandas import DataFrame
from sklearn.manifold import MDS

from colors_operations import get_n_colors


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


def generate_graph(instance: DataFrame, cycles: list[list[str | int]]) -> None:
    graph: Graph = Graph(engine='neato')

    # Nodes.
    colors: list[str] = get_n_colors(number_of_colors=(max(instance['cluster'].unique()) + 1))
    for i, point in enumerate(instance.itertuples()):
        graph.node(name=str(point.Index), color=colors[point.cluster], label=str(point.cluster),
                   pos=f'{point.longitude * 1000},{point.latitude * 1000}!', shape=('box' if point.hub else 'ellipse'))

    # Clusters cycle.
    for cluster_cycle in cycles[0]:
        cluster: int = instance.loc[cluster_cycle[0], 'cluster']
        for i in range(len(cluster_cycle) - 1):
            graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
                       color=colors[cluster], penwidth='1')
    # Hubs cycle.
    for i in range(len(cycles[1]) - 1):
        graph.edge(tail_name=str(cycles[1][i]), head_name=str(cycles[1][i + 1]), penwidth='100')

    graph.render(filename='outputs/graph', format='pdf')


def generate_map(instance: DataFrame, cycles: list[list[str | int]]):
    graph = nx.Graph()

    # Nodes.
    colors: list[str] = get_n_colors(number_of_colors=len(instance['cluster'].unique()))
    for i, point in enumerate(instance.itertuples()):
        graph.add_node(i, pos=(point.latitude, point.longitude))

    # Clusters cycle.
    for cluster_cycle in cycles[0]:
        cluster: int = instance.loc[cluster_cycle[0], 'cluster']
        for i in range(len(cluster_cycle) - 1):
            graph.edge(tail_name=str(cluster_cycle[i]), head_name=str(cluster_cycle[i + 1]),
                       color=colors[cluster], penwidth='1')
