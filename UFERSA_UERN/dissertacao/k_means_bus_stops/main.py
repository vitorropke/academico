from cycle_operations import create_greedy_cycle, calculate_cycle_cost
from map_viewing_operations import *
from clustering_operations import *


def main():
    # distances: DataFrame = pd.read_csv(filepath_or_buffer='inputs/od_matrix.txt', sep=' ', header=None)
    # distances: DataFrame = pd.read_csv(filepath_or_buffer='inputs/od_matrix.csv', index_col='point')
    distances: DataFrame = pd.read_csv(filepath_or_buffer='inputs/od_matrix_with_population.csv', index_col='point')

    # Perform clustering.
    clusters: np.ndarray[np.int32]
    hubs: np.ndarray[np.int64]

    # Hierarchical clustering.
    clusters, hubs = calculate_hierarchical_clusters(instance=distances)

    # K-means clustering.
    # best_number_of_clusters: int = calculate_elbow_method(instance=distances)
    # clusters, hubs = calculate_k_means_clusters(instance=distances, number_of_clusters=best_number_of_clusters)

    # Generate cycles.
    # Cluster cycle.
    cluster_cycle: list[list[str | int]] = []
    for i, current_cluster in enumerate(np.unique(ar=clusters)):
        selected_points: pd.Index(str | int) = distances.index[np.where(clusters == current_cluster)[0]]
        cluster_cycle.append(
            create_greedy_cycle(instance=distances.loc[selected_points, selected_points],
                                origin_destination=distances.index[hubs[i]]))

    # Hub cycle.
    hubs_distances: DataFrame = distances.loc[distances.index[hubs], distances.index[hubs]]
    hub_cycle: list[str | int] = create_greedy_cycle(instance=hubs_distances)

    # Print cycles.
    for i, cycle in enumerate(cluster_cycle):
        print(f'Cluster {i} cycle cost: {calculate_cycle_cost(instance=distances, cycle=cycle)}')
        print(f'Cluster {i} number of points: {len(cycle)}')
    print(f'Hub cycle cost: {calculate_cycle_cost(instance=distances, cycle=hub_cycle)}')

    # Generate visualizations.
    generate_coordinates(instance=distances)
    generate_graph(instance=distances, cycles=[cluster_cycle, hub_cycle])


if __name__ == '__main__':
    main()
