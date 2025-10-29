import pandas as pd
from pandas import DataFrame, Series

from clustering_operations import perform_clustering, perform_subclustering
from connection_operations import find_hubs, create_cycles
from metaheuristic_operations import optimize_cycles
from preprocessing_operations import remove_too_close_points, scale_the_data, pop_central_point
from visualization_operations import generate_interactive_map, generate_static_map, get_colors


def main() -> None:
    instance: DataFrame = pd.read_csv(filepath_or_buffer='input/od_matrix.csv', index_col='point')

    instance = remove_too_close_points(instance=instance, distance_threshold=50)

    central_point: Series
    central_point, instance_without_central_point = pop_central_point(instance=instance)

    scaled_instance: DataFrame = scale_the_data(instance=instance_without_central_point,
                                                population_influence_factor=1.0)

    clusters: pd.Series = perform_clustering(instance=scaled_instance)
    instance_without_central_point['cluster'] = clusters
    scaled_instance['cluster'] = clusters

    minimum_number_of_points_per_subcluster: int = 29
    maximum_number_of_points_per_subcluster: int = 41
    subclusters: pd.Series = perform_subclustering(instance=scaled_instance,
                                                   minimum_number_of_points_per_subcluster=minimum_number_of_points_per_subcluster,
                                                   maximum_number_of_points_per_subcluster=maximum_number_of_points_per_subcluster)
    instance_without_central_point['subcluster'] = subclusters

    hubs: list[str] = find_hubs(instance=instance_without_central_point)
    cycles: list[list[list[str]]] = create_cycles(instance=instance_without_central_point, hubs=hubs)
    hubs, cycles = optimize_cycles(instance=instance, central_point=central_point.name, hubs=hubs, cycles=cycles)

    colors: list[list[str]] = get_colors(cycles=cycles)
    generate_interactive_map(instance=instance_without_central_point, central_point=central_point, hubs=hubs,
                             cycles=cycles, colors=colors, filepath='outputs/interactive_map.html')
    exit(0)
    generate_static_map(instance=instance, central_point=central_point, hubs=hubs, cycles=cycles,
                        filepath='outputs/static_map.pdf')


if __name__ == '__main__':
    main()
