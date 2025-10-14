import pandas as pd
from pandas import DataFrame, Series

from clustering_operations import perform_clustering, perform_subclustering
from connection_operations import find_hubs, create_cycles
from preprocessing_operations import remove_too_close_points, scale_the_data, pop_central_point
from visualization_operations import generate_interactive_map, generate_static_map


def main() -> None:
    instance: DataFrame = pd.read_csv(filepath_or_buffer='input/od_matrix.csv', index_col='point')

    instance = remove_too_close_points(instance=instance, distance_threshold=50)

    central_point: Series
    central_point, instance = pop_central_point(instance=instance)

    scaled_instance: DataFrame = scale_the_data(instance=instance, population_influence_factor=1.0)

    clusters: pd.Series = perform_clustering(instance=scaled_instance)
    scaled_instance['cluster'] = clusters
    instance['cluster'] = clusters

    subclusters: pd.Series = perform_subclustering(instance=scaled_instance, minimum_number_of_points=29,
                                                   maximum_number_of_points=41)
    instance['subcluster'] = subclusters

    hubs: list[str] = find_hubs(instance=instance)
    cycles: list[list[str]] = create_cycles(instance=instance, hubs=hubs)
    exit(0)
    generate_interactive_map(instance=instance, filepath='outputs/interactive_map.html')
    generate_static_map(instance=instance, filepath='outputs/static_map.pdf')


if __name__ == '__main__':
    main()
