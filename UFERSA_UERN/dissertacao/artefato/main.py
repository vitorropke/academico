import time

import pandas as pd
from pandas import DataFrame

from clustering_operations import perform_clustering, perform_subclustering
from connection_operations import find_hubs, create_cycles
from metaheuristic_operations import perform_optimization
from preprocessing_operations import rm_too_close_points, scale_the_data, pop_central_point
from visualization_operations import generate_interactive_map, generate_static_map, get_colors, \
    convert_point_names_to_coords


def main() -> None:
    print('Lendo instância.')
    inst: DataFrame = pd.read_csv(filepath_or_buffer='input/od_matrix.csv', index_col='point')

    print()
    print('Pré-processando.')
    inst = rm_too_close_points(inst=inst, distance_threshold=50)

    inst_without_major_hub: DataFrame
    major_hub: str
    inst_without_major_hub, major_hub = pop_central_point(inst=inst)

    scaled_inst: DataFrame = scale_the_data(inst=inst_without_major_hub, population_influence_factor=1.0)

    print()
    print('Agrupando.')
    clusters: pd.Series = perform_clustering(inst=scaled_inst)
    inst_without_major_hub['cluster'] = clusters
    scaled_inst['cluster'] = clusters

    min_num_points_per_subcluster: int = 29
    max_num_points_per_subcluster: int = 41
    subclusters: pd.Series = perform_subclustering(inst=scaled_inst,
                                                   min_num_points_per_subcluster=min_num_points_per_subcluster,
                                                   max_num_points_per_subcluster=max_num_points_per_subcluster)
    inst_without_major_hub['subcluster'] = subclusters

    print()
    print('Gerando solução.')
    hubs: list[str] = find_hubs(inst=inst_without_major_hub)
    cycles: list[list[list[str]]] = create_cycles(inst=inst_without_major_hub, hubs=hubs)

    hub_coords: list[tuple[float, float]]
    cycle_coords: list[list[list[tuple[float, float]]]]
    hub_coords, cycle_coords = convert_point_names_to_coords(inst=inst_without_major_hub, hubs=hubs, cycles=cycles)
    colors: list[list[str]] = get_colors(cycles=cycles)

    print()
    print('Gerando mapa da solução inicial.')
    # generate_interactive_map(inst=inst_without_major_hub, major_hub=major_hub, hubs=hub_coords,
    #                          cycles=cycle_coords, colors=colors, filepath='outputs/interactive_map_before.html')

    print()
    print('Otimizando solução.')
    min_num_points_per_cycle: int = min_num_points_per_subcluster - 1
    max_num_points_per_cycle: int = max_num_points_per_subcluster + 1
    major_hub, hubs, cycles = perform_optimization(inst=inst, major_hub=major_hub, cycles=cycles,
                                                   min_num_points_per_cycle=min_num_points_per_cycle,
                                                   max_num_points_per_cycle=max_num_points_per_cycle)

    print()
    print('Gerando mapa da solução otimizada.')
    # hub_coords, cycle_coords = convert_point_names_to_coords(inst=inst_without_major_hub, hubs=hubs, cycles=cycles)
    # generate_interactive_map(inst=inst_without_major_hub, major_hub=major_hub, hubs=hub_coords, cycles=cycle_coords,
    #                          colors=colors, filepath='outputs/interactive_map_after.html')
    # generate_static_map(inst=inst_without_major_hub, major_hub=major_hub, hubs=hub_coords, cycles=cycle_coords,
    #                     filepath='outputs/static_map.pdf')


if __name__ == '__main__':
    start_time: float = time.perf_counter()
    main()
    end_time: float = time.perf_counter()

    print(f'Tempo de execução: {end_time - start_time} segundos')
