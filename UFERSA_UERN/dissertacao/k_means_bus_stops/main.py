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
    clusters_cycles: list[list[list[str | int]]] = []
    for i, current_cluster in enumerate(np.unique(ar=clusters)):
        selected_points: pd.Index(str | int) = distances.index[np.where(clusters == current_cluster)[0]]

        sub_clusters: np.ndarray[np.int32] = calculate_sub_cluster(instance=distances.loc[selected_points],
                                                                   number_of_sub_clusters=3)

        sub_cluster_cycle: list[list[str | int]] = []
        for current_sub_cluster in np.unique(ar=sub_clusters):
            selected_sub_points: pd.Index(str | int) = distances.index[np.where(sub_clusters == current_sub_cluster)[0]]

            if distances.index[hubs[i]] not in selected_sub_points:
                selected_sub_points = selected_sub_points.append(pd.Index([distances.index[hubs[i]]]))

            sub_cluster_cycle.append(
                create_greedy_cycle(instance=distances.loc[selected_sub_points, selected_sub_points],
                                    origin_destination=distances.index[hubs[i]]))

        clusters_cycles.append(sub_cluster_cycle)
    # Hub cycle.
    hubs_distances: DataFrame = distances.loc[distances.index[hubs], distances.index[hubs]]
    hubs_cycle: list[str | int] = create_greedy_cycle(instance=hubs_distances)

    # Print cycles.
    for i, cycle in enumerate(clusters_cycles):
        for j, sub_cycle in enumerate(cycle):
            print(f'Cluster {i}.{j} cycle cost: {calculate_cycle_cost(instance=distances, cycle=sub_cycle)}')
            print(f'Cluster {i}.{j} number of points: {len(sub_cycle)}')
    print(f'Hub cycle cost: {calculate_cycle_cost(instance=distances, cycle=hubs_cycle)}')

    # Generate visualizations.
    generate_coordinates(instance=distances)
    generate_graph(instance=distances, clusters_cycles=clusters_cycles, hubs_cycle=hubs_cycle)


if __name__ == '__main__':
    main()
