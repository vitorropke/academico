import time
from pathlib import Path

import pandas as pd
from pandas import DataFrame, Series

from clustering_operations import perform_clustering, perform_subclustering
from connection_operations import find_hubs, create_cycles
from gtfs_operations import generate_gtfs
from metaheuristic_operations import calculate_costs, perform_optimization
from preprocessing_operations import rm_too_close_points, scale_the_data, pop_central_point
from visualization_operations import generate_interactive_map, generate_static_map, set_colors_for_points, \
    convert_point_names_to_coords


def generate_maps(inst: DataFrame, major_hub: str, hubs: list[str], cycles: list[list[list[str]]],
                  filename: str) -> None:
    hub_coords: list[tuple[float, float]]
    cycle_coords: list[list[list[tuple[float, float]]]]
    hub_coords, cycle_coords = convert_point_names_to_coords(inst=inst, hubs=hubs, cycles=cycles)
    colors: dict[tuple[float, float], str] = set_colors_for_points(cycles=cycle_coords)

    print()
    print('Gerando mapas.')
    Path(filename).mkdir(parents=True, exist_ok=True)
    generate_interactive_map(inst=inst, major_hub=major_hub, hubs=hub_coords, cycles=cycle_coords, colors=colors,
                             filepath=f'{filename}/interactive_map.html')
    generate_static_map(inst=inst, major_hub=major_hub, hubs=hub_coords, colors=colors,
                        filepath=f'{filename}/static_map.pdf')


def main(random_state: int) -> None:
    start_time: float = time.process_time()

    print('Lendo instância.')
    inst: DataFrame = pd.read_csv(filepath_or_buffer='input/od_matrix.csv', index_col='point')

    print()
    print('Pré-processando.')
    inst = rm_too_close_points(inst=inst, distance_threshold=50)

    inst_without_major_hub: DataFrame
    initial_major_hub: str
    inst_without_major_hub, initial_major_hub = pop_central_point(inst=inst)

    scaled_inst: DataFrame = scale_the_data(inst=inst_without_major_hub, population_influence_factor=1.0)

    print()
    print('Agrupando.')
    clusters: Series = perform_clustering(inst=scaled_inst)
    inst_without_major_hub['cluster'] = clusters
    scaled_inst['cluster'] = clusters

    min_num_points_per_subcluster: int = 29
    max_num_points_per_subcluster: int = 41
    subclusters: Series = perform_subclustering(inst=scaled_inst,
                                                min_num_points_per_subcluster=min_num_points_per_subcluster,
                                                max_num_points_per_subcluster=max_num_points_per_subcluster,
                                                random_state=random_state)
    inst_without_major_hub['subcluster'] = subclusters

    print()
    print('Gerando solução.')
    initial_hubs: list[str] = find_hubs(inst=inst_without_major_hub)
    initial_cycles: list[list[list[str]]] = create_cycles(inst=inst_without_major_hub, hubs=initial_hubs)

    map_path: str = f'outputs/maps/map_{random_state}'

    generate_maps(inst=inst, major_hub=initial_major_hub, hubs=initial_hubs, cycles=initial_cycles,
                  filename=f'{map_path}/initial_solution')

    print()
    print('Otimizando solução.')
    min_num_points_per_cycle: int = min_num_points_per_subcluster - 1
    max_num_points_per_cycle: int = max_num_points_per_subcluster + 1
    final_major_hub, final_hubs, final_cycles = perform_optimization(inst=inst, major_hub=initial_major_hub,
                                                                     cycles=initial_cycles,
                                                                     min_num_points_per_cycle=min_num_points_per_cycle,
                                                                     max_num_points_per_cycle=max_num_points_per_cycle,
                                                                     random_state=random_state)

    generate_maps(inst=inst, major_hub=final_major_hub, hubs=final_hubs, cycles=final_cycles,
                  filename=f'{map_path}/optimized_solution')

    hub_and_spoke_paths: list[list[str]] = [[cluster[0][0], final_major_hub] for cluster in final_cycles]
    feeder_trunk_paths: list[list[str]] = [[final_cycles[0][0][0], final_major_hub, final_cycles[2][0][0]],
                                           [final_cycles[1][0][0], final_major_hub, final_cycles[3][0][0]]]
    gtfs_path: str = f'outputs/gtfs/gtfs_{random_state}'
    Path(f'{gtfs_path}/hs').mkdir(parents=True, exist_ok=True)
    Path(f'{gtfs_path}/ft').mkdir(parents=True, exist_ok=True)
    generate_gtfs(inst=inst, paths=hub_and_spoke_paths, cycles=final_cycles, out_dir=f'{gtfs_path}/hs')
    generate_gtfs(inst=inst, paths=feeder_trunk_paths, cycles=final_cycles, out_dir=f'{gtfs_path}/ft')

    end_time: float = time.process_time()

    Path('outputs/costs').mkdir(parents=True, exist_ok=True)
    with open(file=f'outputs/costs/costs_{random_state}.txt', mode='w') as file:
        initial_cycle_costs: list[list[int]]
        initial_cluster_costs: list[int]
        initial_overall_cost: int
        initial_cycle_costs, initial_cluster_costs, initial_overall_cost = calculate_costs(inst=inst,
                                                                                           major_hub=initial_major_hub,
                                                                                           cycles=initial_cycles)
        final_cycle_costs: list[list[int]]
        final_cluster_costs: list[int]
        final_overall_cost: int
        final_cycle_costs, final_cluster_costs, final_overall_cost = calculate_costs(inst=inst,
                                                                                     major_hub=final_major_hub,
                                                                                     cycles=final_cycles)

        costs: str = ''

        costs += 'Custos iniciais\n'
        costs += f'Custos por ciclo: {initial_cycle_costs}\n'
        costs += f'Custos por cluster: {initial_cluster_costs}\n'
        costs += f'Custo geral: {initial_overall_cost}\n\n'

        costs += 'Custos finais\n'
        costs += f'Custos por ciclo: {final_cycle_costs}\n'
        costs += f'Custos por cluster: {final_cluster_costs}\n'
        costs += f'Custo geral: {final_overall_cost}\n\n'

        cost_diff: float
        for i in range(len(final_cluster_costs)):
            cost_diff = ((final_cluster_costs[i] - initial_cluster_costs[i]) / initial_cluster_costs[i]) * 100
            costs += f'Porcentagem de otimização do cluster {i}: {cost_diff:.2f} %\n'
        cost_diff = ((final_overall_cost - initial_overall_cost) / initial_overall_cost) * 100
        costs += f'Porcentagem de otimização geral: {cost_diff:.2f} %\n\n'

        time_diff: int = int(end_time - start_time)
        costs += f'Tempo de execução: {time_diff} segundos\n'

        pd.DataFrame({'Custo inicial': [initial_overall_cost], 'Custo final': [final_overall_cost],
                      'Diferença de custo (%)': [f'{cost_diff:.2f}'],
                      'Tempo de execução (segundos)': [time_diff]}).to_csv(
            path_or_buf=f'outputs/costs/cost_{random_state}.csv', index=False)
        file.write(costs)

    Path('outputs/solutions').mkdir(parents=True, exist_ok=True)
    with open(file=f'outputs/solutions/solutions_{random_state}.txt', mode='w') as file:
        solutions: str = ''

        solutions += f'Grande hub: {final_major_hub}\n\n'
        solutions += f'Hubs: {final_hubs}\n\n'
        solutions += f'Ciclos: {final_cycles}\n'

        file.write(solutions)


if __name__ == '__main__':
    for curr_random_state in range(10):
        main(random_state=curr_random_state)
    main(random_state=42)
