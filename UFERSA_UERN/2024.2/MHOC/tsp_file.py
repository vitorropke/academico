import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from matplotlib.figure import Figure
from tsplib95.models import Problem


def generate_adjacent_matrix(instance: Problem) -> np.ndarray[np.ndarray[float]]:
    # Initialize an adjacency matrix.
    cities: np.ndarray[int] = np.fromiter(iter=instance.get_nodes(), dtype=int)
    number_cities: int = instance.dimension
    adjacency_matrix: np.ndarray[np.ndarray[float]] = np.zeros(shape=(number_cities, number_cities), dtype=float)

    # Fill the adjacency matrix.
    for i in range(number_cities):
        for j in range(number_cities):
            adjacency_matrix[i][j] = instance.get_weight(start=cities[i], end=cities[j])

    return adjacency_matrix


def calculate_cycle_cost(instance: Problem, cycle: np.ndarray[int]) -> float:
    cost: float = 0.0
    for i in range(len(cycle) - 1):
        cost += instance.get_weight(start=cycle[i], end=cycle[i + 1])
    return cost


def generate_graph(instance: Problem, cycle: np.ndarray[int]) -> Figure:
    brazil_graph: nx.Graph = instance.get_graph()
    cycle_graph: nx.Graph = nx.Graph()

    # Add edges from the tour.
    for i in range(len(cycle) - 1):
        node1: int = cycle[i]
        node2: int = cycle[i + 1]

        weight: float = instance.get_weight(start=node1, end=node2)
        cycle_graph.add_edge(u_of_edge=node1, v_of_edge=node2, weight=weight)

    pos: dict[int, tuple[float, float]] = nx.nx_agraph.graphviz_layout(G=brazil_graph)

    fig: Figure = plt.subplots()[0]
    nx.draw(G=cycle_graph, pos=pos, with_labels=True)
    labels: dict[tuple[int, int], float] = nx.get_edge_attributes(G=cycle_graph, name='weight')
    nx.draw_networkx_edge_labels(G=cycle_graph, pos=pos, edge_labels=labels)

    return fig
