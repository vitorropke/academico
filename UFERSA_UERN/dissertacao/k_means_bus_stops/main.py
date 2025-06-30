import pandas as pd

from clustering_operations import *
from cycle_operations import create_greedy_cycle, calculate_cycle_cost
from map_viewing_operations import *


def main():
    instance: DataFrame = pd.read_csv(filepath_or_buffer='inputs/od_matrix_with_population.csv', index_col='point')

    # Remove too close points, leaving only one of them.
    distance_matrix: DataFrame = instance.drop(columns=['latitude', 'longitude', 'neighborhood', 'population'],
                                               errors='ignore')
    distance_threshold: int = 50
    for point in distance_matrix.itertuples():
        if any((getattr(point, column) < distance_threshold) and (getattr(point, column) != 0) for column in
               distance_matrix.columns):
            distance_matrix = distance_matrix.drop(index=point.Index, columns=point.Index)

    instance = distance_matrix.join(instance[['latitude', 'longitude', 'neighborhood', 'population']])

    # Perform clustering.
    clusters: np.ndarray[np.int32]
    hubs: np.ndarray[np.int64]

    # Hierarchical clustering.
    clusters, hubs = calculate_hierarchical_clusters(instance=instance)

    # K-means clustering.
    # best_number_of_clusters: int = calculate_elbow_method(instance=instance)
    # clusters, hubs = calculate_k_means_clusters(instance=instance, number_of_clusters=best_number_of_clusters)

    # Generate cycles.
    # Cluster cycle.
    clusters_cycles: list[list[list[str | int]]] = []
    sub_clusters: Series = pd.Series(data=0, index=instance.index, dtype=np.int32)
    for i, current_cluster in enumerate(np.unique(ar=clusters)):
        selected_points: pd.Index(str | int) = instance.index[np.where(clusters == current_cluster)[0]]

        print(f'\nNumber of points of cluster {i}: {len(selected_points)}')

        sub_clusters_of_the_current_cluster: tuple[np.ndarray[np.int32], Series] = calculate_sub_cluster(
            cluster=instance.loc[selected_points, selected_points], maximum_number_of_points_per_sub_cluster=41,
            minimum_number_of_points_per_sub_cluster=30)
        sub_clusters.update(other=sub_clusters_of_the_current_cluster[1])

        sub_clusters_cycle: list[list[str | int]] = []
        for j, current_sub_cluster in enumerate(np.unique(ar=sub_clusters_of_the_current_cluster[0])):
            selected_sub_points: pd.Index(str | int) = selected_points[
                np.where(sub_clusters_of_the_current_cluster[0] == current_sub_cluster)[0]]

            print(f'Number of points of sub-cluster {j}: {len(selected_sub_points)}')

            if instance.index[hubs[i]] not in selected_sub_points:
                selected_sub_points = selected_sub_points.append(pd.Index([instance.index[hubs[i]]]))

            initial_cycle: list[str | int] = create_greedy_cycle(
                instance=instance.loc[selected_sub_points, selected_sub_points],
                origin_destination=instance.index[hubs[i]])

            print(f'Cycle cost of sub-cluster {j}: {calculate_cycle_cost(instance=instance, cycle=initial_cycle)}')

            sub_clusters_cycle.append(initial_cycle)

        clusters_cycles.append(sub_clusters_cycle)
    # Put the new sub-clusters in the dataframe.
    instance['sub_cluster'] = sub_clusters

    # Hub trail.
    hubs_distances: DataFrame = instance.loc[instance.index[hubs], instance.index[hubs]]
    hubs_distances_sum: Series = np.sum(a=hubs_distances, axis=0)
    hubs_centroid: np.int64 = np.argmin(hubs_distances_sum)
    hubs_center: str | int = hubs_distances.index[hubs_centroid]
    hubs_center = 'parada_Igreja_Sao_Vicente'
    hubs_trail: list[list[str | int]] = [[hubs_center, i] for i in hubs_distances.index if hubs_center != i]

    print(f'\nNumber of hubs: {len(hubs_distances)}')

    # Print cycles.
    # for i, cycle in enumerate(clusters_cycles):
    #     for j, sub_cycle in enumerate(cycle):
    #         print(f'Cluster {i}.{j} cycle cost: {calculate_cycle_cost(instance=instance, cycle=sub_cycle)}')
    #         print(f'Cluster {i}.{j} number of points: {len(sub_cycle) - 1}')
    # print(f'Number of hubs: {len(hubs_trail)}')

    # Generate visualizations.
    generate_coordinates(instance=instance)
    generate_cluster_map(instance=instance, cycles=clusters_cycles)
    generate_graph(instance=instance, clusters_cycles=clusters_cycles, hubs_trail=hubs_trail)
    generate_map(instance=instance, clusters_cycles=clusters_cycles, hubs_trail=hubs_trail)


if __name__ == '__main__':
    main()
