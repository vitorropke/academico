from pandas import DataFrame, Series

from connection_operations import calculate_cycle_cost


def two_opt(cycle: list[str]) -> list[list[str]]:
    number_of_points: int = len(cycle)

    # The formula used to initialize this list is just the inverse of the loop below.
    opted_cycles: list[list[str]] = [[] for _ in
                                     range(int(((number_of_points - 2) * ((number_of_points - 3) / 2)) + 1))]

    cycle_copy: list[str] = cycle.copy()
    opted_cycles[0] = cycle_copy

    index: int = 1
    # Starts at 1(i) and ends at n-1(j) so as not to modify the hub.
    for i in range(1, number_of_points - 2):
        for j in range(i + 1, number_of_points - 1):
            cycle_copy = cycle_copy.copy()
            cycle_copy.insert(i, cycle_copy.pop(j))
            opted_cycles[index] = cycle_copy
            index += 1

    return opted_cycles


def switch_hub(instance: DataFrame, cycles: list[list[str]]) -> tuple[list[list[str]], str]:
    cycles_copy: list[list[str]] = cycles.copy()
    old_hub: str = cycles_copy[0][0]

    # Flatten the cycles. 'Set' is used to remove duplicated points (hub at the beginning and end of each cycle).
    flat_cycles_without_old_hub: set[str] = set()
    for cycle in cycles_copy:
        flat_cycles_without_old_hub.update(cycle)
    flat_cycles_without_old_hub.remove(old_hub)

    # Search for the 'n' nearest points to choose the next hub.
    number_of_nearest_points: int = 5
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


def swap_points_between_cycles(instance: DataFrame, cycle0: list[str], cycle1: list[str]) -> tuple[
    list[str], list[str]]:
    cycle0_copy: list[str] = cycle0.copy()
    cycle1_copy: list[str] = cycle1.copy()

    # Select all points except the hubs (beginning and end of each cycle).
    # Select the 'n' nearest pair of points.
    number_of_nearest_pair_of_points: int = 5
    nearest_pair_of_points: Series = instance.loc[cycle0_copy[1:-1], cycle1_copy[1:-1]].stack().nsmallest(
        n=number_of_nearest_pair_of_points)
    # Select one pair of points randomly.
    points_to_swap: Series = nearest_pair_of_points.sample(n=1, random_state=42)

    # Get positions of the points that will be swapped.
    cycle0_position: int = cycle0_copy.index(points_to_swap.index[0][0])
    cycle1_position: int = cycle1_copy.index(points_to_swap.index[0][1])

    cycle0_copy[cycle0_position], cycle1_copy[cycle1_position] = cycle1_copy[cycle1_position], cycle0_copy[
        cycle0_position]

    return cycle0_copy, cycle1_copy


def optimize_cycles(instance: DataFrame, central_point: str, hubs: list[str], cycles: list[list[list[str]]]) -> tuple[
    list[str], list[list[list[str]]]]:
    number_of_cluster: int = len(cycles)

    best_hubs: list[str] = hubs.copy()
    best_cycles: list[list[list[str]]] = cycles.copy()

    for i in range(number_of_cluster):
        number_of_subclusters: int = len(best_cycles[i])
        # switch_hub(instance=instance, cycles=cycles[i])
        # swap_points_between_cycles(instance=instance, cycle0=cycles[i][0], cycle1=cycles[i][1])

        current_cost: int = 0
        for j in range(number_of_subclusters):
            current_cost += calculate_cycle_cost(instance=instance, cycle=best_cycles[i][j])
        current_cost += calculate_cycle_cost(instance=instance, cycle=[best_hubs[i], central_point])

        best_cost: int = current_cost + 1

        while current_cost < best_cost:
            opted_cycles: list[list[str]] = two_opt(cycle=best_cycles[0][0])

            number_of_opted_cycles: int = len(opted_cycles)

            costs: list[float] = [0 for _ in range(number_of_opted_cycles)]
            for k in range(number_of_opted_cycles):
                costs[k] = calculate_cycle_cost(instance=instance, cycle=opted_cycles[k])

            print(min(costs))

    return best_hubs, best_cycles
