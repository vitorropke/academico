import random

from pandas import DataFrame, Series

from connection_operations import calculate_cycle_cost


def perform_two_opt(cycle: list[str]) -> list[list[str]]:
    cycle_copy: list[str] = cycle.copy()
    number_of_points: int = len(cycle_copy)

    # The formula used to initialize this list is just the inverse of the loop below.
    opted_cycles: list[list[str]] = [[] for _ in
                                     range(int(((number_of_points - 2) * ((number_of_points - 3) / 2)) + 1))]

    opted_cycles_index: int = 0
    # Starts at 1(i) and ends at n-1(j) so as not to modify the hub.
    for i in range(1, number_of_points - 2):
        for j in range(i + 1, number_of_points - 1):
            opted_cycles[opted_cycles_index] = cycle_copy.copy()
            cycle_copy.insert(i, cycle_copy.pop(j))
            opted_cycles_index += 1
    opted_cycles[opted_cycles_index] = cycle_copy.copy()

    return opted_cycles


def perform_local_search(instance: DataFrame, cycle: list[str], cost: int) -> tuple[list[str], int]:
    best_cycle: list[str] = cycle.copy()
    best_cost: int = cost

    current_cost: int = cost
    while current_cost <= best_cost:
        opted_cycles: list[list[str]] = perform_two_opt(cycle=best_cycle)
        cycle_costs: list[int] = [calculate_cycle_cost(instance=instance, cycle=opted_cycle) for opted_cycle in
                                  opted_cycles]

        # Best improvement.
        # lowest_cost_index: int = min(range(len(cycle_costs)), key=cycle_costs.__getitem__)
        # current_cycle = opted_cycles[lowest_cost_index].copy()
        # current_cost = cycle_costs[lowest_cost_index]
        # if current_cost < best_cost:
        #     best_cycle = current_cycle.copy()
        #     best_cost = current_cost

        # First improvement.
        for current_cycle, current_cost in zip(opted_cycles, cycle_costs):
            if current_cost < best_cost:
                best_cycle = current_cycle.copy()
                best_cost = current_cost
                break

    return best_cycle, best_cost


def switch_hub(instance: DataFrame, cycles: list[list[str]]) -> tuple[list[list[str]], str]:
    cycles_copy: list[list[str]] = cycles.copy()
    old_hub: str = cycles_copy[0][0]

    # Flatten the cycles. 'Set' is used to remove duplicated points (hub at the beginning and end of each cycle).
    flat_cycles_without_old_hub: set[str] = set()
    for cycle in cycles_copy:
        flat_cycles_without_old_hub.update(cycle)
    flat_cycles_without_old_hub.remove(old_hub)

    # Search for the 'n' nearest points to choose the next hub.
    number_of_nearest_points: int = 10
    nearest_points_to_old_hub: Series = instance.loc[list(flat_cycles_without_old_hub), old_hub].nsmallest(
        n=number_of_nearest_points)
    # Select one point randomly.
    new_hub: str = nearest_points_to_old_hub.sample(n=1, random_state=42).index.item()

    # Update the hubs in the cycles. Remove from the cycle to which it initially belonged.
    for cycle in cycles_copy:
        try:
            cycle[cycle.index(new_hub)] = old_hub
        except ValueError:
            pass

        cycle[0] = new_hub
        cycle[-1] = new_hub

    return cycles_copy, new_hub


def swap_points_between_cycles(instance: DataFrame, cycles: list[list[str]]) -> list[list[str]]:
    cycles_copy = cycles.copy()

    # Get two cycles randomly.
    cycle0: list[str]
    cycle1: list[str]
    cycle0, cycle1 = random.sample(population=cycles_copy, k=2)
    cycle0_position: int = cycles_copy.index(cycle0)
    cycle1_position: int = cycles_copy.index(cycle1)

    # Select all points except the hubs (beginning and end of each cycle).
    # Select the 'n' nearest pair of points.
    number_of_nearest_pair_of_points: int = 10
    nearest_pair_of_points: Series = instance.loc[cycle0[1:-1], cycle1[1:-1]].stack().nsmallest(
        n=number_of_nearest_pair_of_points)
    # Select one pair of points randomly.
    points_to_swap: Series = nearest_pair_of_points.sample(n=1, random_state=42)

    # Get positions of the points that will be swapped.
    point0_position: int = cycle0.index(points_to_swap.index[0][0])
    point1_position: int = cycle1.index(points_to_swap.index[0][1])

    # Swap
    cycle0[point0_position], cycle1[point1_position] = cycle1[point1_position], cycle0[point0_position]

    # Update the cycles.
    cycles_copy[cycle0_position] = cycle0
    cycles_copy[cycle1_position] = cycle1

    return cycles_copy


def optimize_cycles(instance: DataFrame, central_point: str, hubs: list[str], cycles: list[list[list[str]]]) -> tuple[
    list[str], list[list[list[str]]]]:
    best_hubs: list[str] = hubs.copy()
    best_cycles: list[list[list[str]]] = cycles.copy()

    initial_cycle_costs: list[list[int]] = [
        [calculate_cycle_cost(instance=instance, cycle=current_cycle) for current_cycle in cluster] for cluster in
        best_cycles]
    print(initial_cycle_costs)
    initial_cluster_costs: list[int] = [
        (sum(cluster) + calculate_cycle_cost(instance=instance, cycle=[best_hubs[i], central_point])) for i, cluster in
        enumerate(initial_cycle_costs)]
    print(initial_cluster_costs)
    initial_overall_cost: int = sum(initial_cluster_costs)
    print(initial_overall_cost)

    # for i, current_cluster in enumerate(best_cycles):
    #     number_of_subclusters: int = len(current_cluster)
    #
    #     current_cycles: list[list[str]] = current_cluster.copy()
    #
    #     current_cycle_costs: list[int] = initial_cycle_costs[i].copy()
    #     current_cluster_cost: int = initial_cluster_costs[i]
    #     print(f'Custo inicial do cluster {i}: {current_cluster_cost}')
    #
    #     best_cycle_costs: list[int] = current_cycle_costs.copy()
    #     best_cluster_cost: int = current_cluster_cost
    #
    #     while current_cluster_cost <= best_cluster_cost:
    #         # for j in range(number_of_subclusters):
    #         #     current_cycles[j], current_cycle_costs[j] = perform_local_search(instance=instance,
    #         #                                                                      cycle=current_cycles[j],
    #         #                                                                      cost=best_cycle_costs[j])
    #         # current_cluster_cost = sum(current_cycle_costs) + calculate_cycle_cost(instance=instance,
    #         #                                                                        cycle=[current_hub,
    #         #                                                                               central_point])
    #         # if current_cluster_cost < best_cluster_cost:
    #         #     best_cycles[i] = current_cycles.copy()
    #         #     best_cycle_costs = current_cycle_costs.copy()
    #         #     best_cluster_cost = current_cluster_cost
    #         #     print(best_cluster_cost)
    #         #     print('melhorou')
    #
    #         cycles_with_modified_hubs: list[list[str]]
    #         new_hub: str
    #         cycles_with_modified_hubs, new_hub = switch_hub(instance=instance, cycles=current_cycles)
    #         for j in range(number_of_subclusters):
    #             current_cycles[j], current_cycle_costs[j] = perform_local_search(instance=instance,
    #                                                                              cycle=cycles_with_modified_hubs[j],
    #                                                                              cost=best_cycle_costs[j])
    #         current_cluster_cost = sum(current_cycle_costs) + calculate_cycle_cost(instance=instance,
    #                                                                                cycle=[new_hub, central_point])
    #
    #         if current_cluster_cost < best_cluster_cost:
    #             best_hubs[i] = new_hub
    #             best_cycles[i] = current_cycles.copy()
    #             best_cycle_costs = current_cycle_costs.copy()
    #             best_cluster_cost = current_cluster_cost
    #
    #     print(f'Custo final do cluster {i}: {current_cluster_cost}')

    final_cycle_costs: list[list[int]] = [
        [calculate_cycle_cost(instance=instance, cycle=current_cycle) for current_cycle in cluster] for cluster in
        best_cycles]
    print(final_cycle_costs)
    final_cluster_costs: list[int] = [
        (sum(cluster) + calculate_cycle_cost(instance=instance, cycle=[best_hubs[i], central_point])) for i, cluster in
        enumerate(final_cycle_costs)]
    print(final_cluster_costs)
    final_overall_cost: int = sum(final_cluster_costs)
    print(final_overall_cost)

    for i in range(len(final_cluster_costs)):
        print(
            f'Porcentagem de diferença de custo do cluster {i}: {(((final_cluster_costs[i] - initial_cluster_costs[i]) / initial_cluster_costs[i]) * 100):.2f} %')
    print(
        f'Porcentagem de diferença de custo geral: {(((final_overall_cost - initial_overall_cost) / initial_overall_cost) * 100):.2f} %')

    exit(0)
    return best_hubs, best_cycles
