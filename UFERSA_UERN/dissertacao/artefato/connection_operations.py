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
    current_point: str = instance.index.values.tolist()[0]
    for i in range(1, number_of_points):
        visited_points.add(current_point)

        min_cost: float = float('inf')
        next_point: str | None = None
        for neighbor_point in instance.index.values:
            cost: float = instance.at[current_point, neighbor_point]
            if neighbor_point not in visited_points and (0.0 < cost < min_cost):
                next_point = neighbor_point
                min_cost = cost

        if next_point is None:
            break

        current_point = next_point
        cycle[i] = current_point

    return cycle


def create_cycles(instance: DataFrame, hubs: list[str]) -> list[list[str]]:
    od_matrix: DataFrame = instance[instance.index.tolist() + ['cluster', 'subcluster']]

    # cycles:list[list[str]] = [[] for _ in range(od_matrix['cluster'].nunique())]
    cycles: list[list[str]] = []

    for (cluster_number, subcluster_number), subcluster_data in od_matrix.groupby(by=['cluster', 'subcluster']):
        cycles.append(create_greedy_cycle(instance=subcluster_data[subcluster_data.index.tolist()],
                                          origin_destination=hubs[cluster_number]))

        print(cycles)
        exit(0)

    return cycles


def calculate_cycle_cost(instance: DataFrame, cycle: list[str]) -> float:
    cost: float = 0.0

    for i in range(len(cycle) - 1):
        cost += instance.at[cycle[i], cycle[i + 1]]

    return cost
