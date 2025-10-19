from pandas import DataFrame


def find_hubs(instance: DataFrame) -> list[str]:
    od_matrix: DataFrame = instance[instance.index.tolist() + ['cluster']]

    hubs: list[str] = ['' for _ in range(od_matrix['cluster'].nunique())]

    for cluster_number, cluster_data in od_matrix.groupby(by='cluster'):
        cluster_data = cluster_data[cluster_data.index.tolist()]
        hub_name: str = cluster_data.sum(axis='columns').idxmin()

        hubs[cluster_number] = hub_name

    return hubs


def create_greedy_cycle(instance: DataFrame, origin_destination: str) -> list[str]:
    number_of_points: int = len(instance)

    cycle: list[str] = [origin_destination for _ in range(number_of_points + 1)]

    visited_points: set[str] = set()
    visited_points.add(origin_destination)
    current_point: str = instance.index.values.tolist()[0]
    for i in range(1, number_of_points):
        visited_points.add(current_point)
        cycle[i] = current_point

        if len(visited_points) == number_of_points:
            break

        current_point = instance.loc[current_point].drop(labels=list(visited_points), errors='ignore').idxmin()

    return cycle


def create_cycles(instance: DataFrame, hubs: list[str]) -> list[list[list[str]]]:
    od_matrix: DataFrame = instance[instance.index.tolist() + ['cluster', 'subcluster']]

    cycles: list[list[list[str]]] = [[[] for _ in range(number_of_subclusters)] for number_of_subclusters in
                                     od_matrix.groupby(by='cluster')['subcluster'].nunique()]

    for (cluster_number, subcluster_number), subcluster_data in od_matrix.groupby(by=['cluster', 'subcluster']):
        cycles[cluster_number][subcluster_number] = create_greedy_cycle(
            instance=subcluster_data[subcluster_data.index.tolist()], origin_destination=hubs[cluster_number])

    return cycles


def calculate_cycle_cost(instance: DataFrame, cycle: list[str]) -> int:
    cost: int = 0

    for i in range(len(cycle) - 1):
        cost += instance.at[cycle[i], cycle[i + 1]]

    return cost
