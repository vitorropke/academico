from pandas import DataFrame


def find_hubs(inst: DataFrame) -> list[str]:
    print('Encontrando hubs.')

    od_matrix_with_cluster: DataFrame = inst.loc[:, inst.index.tolist() + ['cluster']]

    hubs: list[str] = ['' for _ in range(od_matrix_with_cluster.loc[:, 'cluster'].nunique())]

    for cluster_num, cluster_data in od_matrix_with_cluster.groupby(by='cluster'):
        cluster_od_matrix = cluster_data.loc[:, cluster_data.index]
        hub_name: str = cluster_od_matrix.sum(axis='columns').idxmin()

        hubs[cluster_num] = hub_name

    return hubs


def create_greedy_cycle(inst: DataFrame, orig_dest: str) -> list[str]:
    inst_copy: DataFrame = inst.copy()
    inst_copy = inst_copy.drop(index=orig_dest, columns=orig_dest, errors='ignore')

    num_points: int = len(inst_copy)

    cycle: list[str] = [orig_dest for _ in range(num_points + 2)]

    visited_points: set[str] = set()
    curr_point: str = inst_copy.index[0]
    for i in range(1, num_points):
        cycle[i] = curr_point
        visited_points.add(curr_point)
        curr_point = inst_copy.loc[curr_point, :].drop(labels=list(visited_points), errors='ignore').idxmin()
    cycle[-2] = curr_point

    return cycle


def create_cycles(inst: DataFrame, hubs: list[str]) -> list[list[list[str]]]:
    print('Gerando ciclos.')

    od_matrix_with_cluster_and_subcluster: DataFrame = inst.loc[:, inst.index.tolist() + ['cluster', 'subcluster']]

    cycles: list[list[list[str]]] = [[[] for _ in range(num_subclusters)] for num_subclusters in
                                     od_matrix_with_cluster_and_subcluster.groupby(by='cluster')[
                                         'subcluster'].nunique()]

    for (cluster_num, subcluster_num), subcluster_data in od_matrix_with_cluster_and_subcluster.groupby(
            by=['cluster', 'subcluster']):
        cycles[cluster_num][subcluster_num] = create_greedy_cycle(
            inst=subcluster_data.loc[:, subcluster_data.index], orig_dest=hubs[cluster_num])

    return cycles


def calculate_cycle_cost(inst: DataFrame, cycle: list[str]) -> int:
    cost: int = 0

    for orig, dest in zip(cycle, cycle[1:]):
        cost += inst.at[orig, dest].item()

    return cost
