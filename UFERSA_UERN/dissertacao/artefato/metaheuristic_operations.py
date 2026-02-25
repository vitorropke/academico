import time

import pandas as pd
from pandas import DataFrame, Series

from connection_operations import calculate_cycle_cost


def perform_two_opt(inst: DataFrame, cycle: list[str]) -> list[str]:
    print('Fazendo o 2-opt.')

    best_cycle: list[str] = cycle.copy()

    curr_cycle: list[str] = best_cycle.copy()
    best_cost: int = calculate_cycle_cost(inst=inst, cycle=best_cycle)
    num_points: int = len(best_cycle)
    # Starts at 1(i) and ends at n-1(j) so as not to modify the hub.
    for i in range(1, num_points - 2):
        for j in range(i + 1, num_points - 1):
            curr_cycle.insert(i, curr_cycle.pop(j))
            curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
            if curr_cost < best_cost:
                best_cycle = curr_cycle.copy()
                best_cost = curr_cost

    return best_cycle


def perform_three_opt(inst: DataFrame, cycle: list[str]) -> list[str]:
    print('Fazendo o 3-opt.')

    cycle_copy: list[str] = cycle.copy()

    initial_cost: int = calculate_cycle_cost(inst=inst, cycle=cycle_copy)
    num_points: int = len(cycle_copy)
    # Starts at 1(i) and ends at n-1(k) so as not to modify the hub.
    for i in range(1, num_points - 3):
        for j in range(i + 1, num_points - 2):
            for k in range(j + 1, num_points - 1):
                segment1: list[str] = cycle_copy[:i]
                segment2: list[str] = cycle_copy[i:j]
                segment3: list[str] = cycle_copy[j:k]
                segment4: list[str] = cycle_copy[k:]

                curr_cycle: list[str]

                # segment 1 + segment 2 (reversed) + segment 3 + segment 4
                curr_cycle = segment1 + segment2[::-1] + segment3 + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 2 + segment 3 (reversed) + segment 4
                curr_cycle = segment1 + segment2 + segment3[::-1] + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 2 (reversed) + segment 3 (reversed) + segment 4
                curr_cycle = segment1 + segment2[::-1] + segment3[::-1] + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 3 + segment 2 + segment 4
                curr_cycle = segment1 + segment3 + segment2 + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 3 (reversed) + segment 2 + segment 4
                curr_cycle = segment1 + segment3[::-1] + segment2 + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 3 + segment 2 (reversed) + segment 4
                curr_cycle = segment1 + segment3 + segment2[::-1] + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

                # segment 1 + segment 3 (reversed) + segment 2 (reversed) + segment 4
                curr_cycle = segment1 + segment3[::-1] + segment2[::-1] + segment4
                curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
                if curr_cost < initial_cost:
                    return curr_cycle

    return cycle_copy


def perform_swap(inst: DataFrame, cycle: list[str]) -> list[str]:
    print('Fazendo o swap.')

    best_cycle: list[str] = cycle.copy()

    curr_cycle: list[str] = best_cycle.copy()
    best_cost: int = calculate_cycle_cost(inst=inst, cycle=best_cycle)
    num_points: int = len(best_cycle)
    # Starts at 1(i) and ends at n-1(j) so as not to modify the hub.
    for i in range(1, num_points - 2):
        for j in range(i + 1, num_points - 1):
            # Swap is always performed over the initial cycle. Therefore, the swap is done and then undone before the
            # next iteration.
            # Do the swap.
            curr_cycle[i], curr_cycle[j] = curr_cycle[j], curr_cycle[i]
            curr_cost: int = calculate_cycle_cost(inst=inst, cycle=curr_cycle)
            if curr_cost < best_cost:
                best_cycle = curr_cycle.copy()
                best_cost = curr_cost
            # Undo the swap.
            curr_cycle[i], curr_cycle[j] = curr_cycle[j], curr_cycle[i]

    return best_cycle


def perform_local_search(inst: DataFrame, cycle: list[str], local_search_method: int) -> list[str]:
    if local_search_method == 0:
        return perform_two_opt(inst=inst, cycle=cycle)
    elif local_search_method == 1:
        return perform_three_opt(inst=inst, cycle=cycle)
    elif local_search_method == 2:
        return perform_swap(inst=inst, cycle=cycle)


def perform_vnd_neighborhood_change_sequential(inst: DataFrame, old_cycle: list[str], new_cycle: list[str],
                                               curr_local_search_method: int) -> tuple[list[str], int]:
    old_cost: int = calculate_cycle_cost(inst=inst, cycle=old_cycle)
    new_cost: int = calculate_cycle_cost(inst=inst, cycle=new_cycle)

    if new_cost < old_cost:
        return new_cycle, 0
    else:
        return old_cycle, curr_local_search_method + 1


def perform_vnd(inst: DataFrame, cycles: list[list[str]]) -> list[list[str]]:
    print('Fazendo o VND.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    for i, cycle in enumerate(cycles_copy):
        print(f'Otimizando o ciclo {i}.')

        curr_cycle: list[str] = cycle.copy()

        curr_local_search_method: int = 0
        num_local_search_methods: int = 3
        while curr_local_search_method < num_local_search_methods:
            new_cycle: list[str] = perform_local_search(inst=inst, cycle=curr_cycle,
                                                        local_search_method=curr_local_search_method)
            curr_cycle, curr_local_search_method = perform_vnd_neighborhood_change_sequential(inst=inst,
                                                                                              old_cycle=curr_cycle,
                                                                                              new_cycle=new_cycle,
                                                                                              curr_local_search_method=curr_local_search_method)

        cycles_copy[i] = curr_cycle

    return cycles_copy


def get_points(inst: DataFrame, orig: str, dests: list[str], random_state: int, num_nearest_points: int = 10,
               num_points: int = 1) -> tuple[str, str]:
    # Select the 'n' nearest points around the origin.
    nearest_points: Series = inst.loc[dests, orig].nsmallest(n=num_nearest_points)
    # Select 'n' points randomly and the nearest point to the origin.
    return nearest_points.sample(n=num_points, random_state=random_state).index.item(), nearest_points.index[0]


def get_pairs_of_points(inst: DataFrame, origs: list[str], dests: list[str], distance_threshold: int = 500) -> Series:
    # Group each origin with destinations.
    nearest_pairs_of_points: Series = inst.loc[origs, dests].stack()
    # Select the pairs of points whose distance is less than a threshold.
    return nearest_pairs_of_points[nearest_pairs_of_points < distance_threshold]


def find_dest_idx(inst: DataFrame, orig_point: str, dest_cycle: list[str], dest_point_idx: int) -> int:
    # Check the distance from the origin point to the adjacent points of the destination point in the destination cycle.
    # If the nearest adjacent is to the left of the destination point, the destination index will be the index of the
    # destination point itself. That's because using the `insert` command will shift the destination point and the rest
    # of the list to the right, keeping the origin point to the left of the destination point.
    # If the nearest adjacent is to the right of the destination point, the destination index will be to the right of
    # the destination point. That is, the index of the destination point + 1.
    left_adjacent_idx: int = (dest_point_idx - 1) % len(dest_cycle)
    right_adjacent_idx: int = (dest_point_idx + 1) % len(dest_cycle)
    if inst.at[dest_cycle[left_adjacent_idx], orig_point] < inst.at[dest_cycle[right_adjacent_idx], orig_point]:
        return dest_point_idx
    else:
        return dest_point_idx + 1


def replace_cluster_hub(inst: DataFrame, cycles: list[list[str]], hubs_tabu_list: set[str],
                        min_num_points_per_cycle: int, max_num_points_per_cycle: int, random_state: int) -> list[
    list[str]]:
    print('Trocando o hub do cluster.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    old_hub: str = cycles_copy[0][0]
    hubs_tabu_list.add(old_hub)

    flat_cycles_without_old_hubs: list[str] = [point for cycle in cycles_copy for point in cycle[1:-1] if
                                               point not in hubs_tabu_list]

    new_hub: str
    nearest_point_to_old_hub: str
    new_hub, nearest_point_to_old_hub = get_points(inst=inst, orig=old_hub, dests=flat_cycles_without_old_hubs,
                                                   random_state=random_state)

    for i, cycle in enumerate(cycles_copy):
        curr_cycle: list[str] = cycle.copy()

        # Remove the old hub from the cycles, except for the one where the nearest point to the old hub is located.
        # In this case, just remove the duplicate in the first index.
        if nearest_point_to_old_hub in curr_cycle:
            curr_cycle = curr_cycle[1:]
        else:
            curr_cycle = curr_cycle[1:-1]

        if new_hub in curr_cycle:
            # Rotate the cycle so that the new hub is in the first index.
            new_hub_idx: int = curr_cycle.index(new_hub)
            curr_cycle = curr_cycle[new_hub_idx:] + curr_cycle[:new_hub_idx]
            # Duplicate the new hub at the end of the cycle.
            curr_cycle.append(new_hub)
        else:
            nearest_point_to_new_hub: str = inst.loc[curr_cycle, new_hub].idxmin()
            nearest_point_to_new_hub_idx: int = curr_cycle.index(nearest_point_to_new_hub)
            nearest_adjacent_idx: int = find_dest_idx(inst=inst, orig_point=new_hub, dest_cycle=curr_cycle,
                                                      dest_point_idx=nearest_point_to_new_hub_idx)
            # Rotate the cycle so that the nearest point to the new hub and its nearest adjacent remain in the first and
            # last indexes.
            curr_cycle = curr_cycle[nearest_adjacent_idx:] + curr_cycle[:nearest_adjacent_idx]

            # Add new hub.
            curr_cycle.insert(0, new_hub)
            curr_cycle.append(new_hub)

        cycles_copy[i] = curr_cycle

    # If any of the cycles violates the minimum or the maximum number of points, return the original cycles.
    if any((len(cycle[1:-1]) < min_num_points_per_cycle) or (len(cycle[1:-1]) > max_num_points_per_cycle) for cycle in
           cycles_copy):
        return cycles

    return cycles_copy


def swap_points_between_cycles(inst: DataFrame, cycles: list[list[str]], swaps_tabu_list: set[tuple[str, str]],
                               random_state: int) -> list[list[str]]:
    print('Trocando pontos entre ciclos.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    # Get pairs for each combination from origin to destination cycles.
    pairs_of_points_by_orig_dest_cycles: list[Series] = [curr_pairs for i, orig_cycle in enumerate(cycles_copy) for
                                                         j, dest_cycle in enumerate(cycles_copy) if i != j if not (
            curr_pairs := get_pairs_of_points(inst=inst, origs=orig_cycle[1:-1], dests=dest_cycle[1:-1])).empty]

    # If there are no pairs of points, return the original cycles.
    if not pairs_of_points_by_orig_dest_cycles:
        return cycles

    pairs_of_points: Series = pd.concat(objs=pairs_of_points_by_orig_dest_cycles)

    # Exclude all swaps that are in the swap tabu list.
    pairs_of_points = pairs_of_points[~pairs_of_points.index.isin(swaps_tabu_list)]

    # If there are no pairs of points, return the original cycles.
    if pairs_of_points.empty:
        return cycles

    # Get one pair of points.
    points_to_swap: Series = pairs_of_points.sample(n=1, random_state=random_state)
    point0: str = points_to_swap.index[0][0]
    point1: str = points_to_swap.index[0][1]

    swaps_tabu_list.add((point0, point1))

    # Find the indexes of the pair of points.
    # tuple[index of the cycle in the cluster, index of the point in the cycle]
    point0_idx: tuple[int, int] | None = None
    point1_idx: tuple[int, int] | None = None

    for i, cycle in enumerate(cycles_copy):
        for j, point in enumerate(cycle):
            if point0 == point:
                point0_idx = (i, j)
                break
            if point1 == point:
                point1_idx = (i, j)
                break

        if (point0_idx is not None) and (point1_idx is not None):
            break

    # Swap.
    cycles_copy[point0_idx[0]][point0_idx[1]], cycles_copy[point1_idx[0]][point1_idx[1]] = cycles_copy[point1_idx[0]][
        point1_idx[1]], cycles_copy[point0_idx[0]][point0_idx[1]]

    return cycles_copy


def move_point_between_cycles(inst: DataFrame, cycles: list[list[str]], moves_tabu_list: set[tuple[str, str]],
                              min_num_points_per_cycle: int, max_num_points_per_cycle: int, random_state: int) -> list[
    list[str]]:
    print('Movendo um ponto de um ciclo para outro.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    giveable_cycles: set[int] = set()
    receivable_cycles: set[int] = set()

    for i, cycle in enumerate(cycles_copy):
        if len(cycle[1:-1]) > min_num_points_per_cycle:
            giveable_cycles.add(i)
        if len(cycle[1:-1]) < max_num_points_per_cycle:
            receivable_cycles.add(i)

    # If it doesn't exist giveable or receivable cycles, or there's only one giveable and receivable cycle, and they're
    # the same, return the original cycles.
    if (len(giveable_cycles) == 0) or (len(receivable_cycles) == 0) or (
            (len(giveable_cycles) == 1) and (len(receivable_cycles) == 1) and (giveable_cycles == receivable_cycles)):
        return cycles

    # Get pairs for each combination from giveable to receivable cycles.
    pairs_of_points_by_giveable_receivable_cycles: list[Series] = [curr_pairs for giveable_cycle in giveable_cycles for
                                                                   receivable_cycle in receivable_cycles if
                                                                   giveable_cycle != receivable_cycle if not (
            curr_pairs := get_pairs_of_points(inst=inst, origs=cycles_copy[giveable_cycle][1:-1],
                                              dests=cycles_copy[receivable_cycle][1:-1])).empty]

    # If there are no pairs of points, return the original cycles.
    if not pairs_of_points_by_giveable_receivable_cycles:
        return cycles

    pairs_of_points: Series = pd.concat(objs=pairs_of_points_by_giveable_receivable_cycles)

    # Exclude all moves that are in the move tabu list.
    pairs_of_points = pairs_of_points[~pairs_of_points.index.isin(moves_tabu_list)]

    # If there are no pairs of points, return the original cycles.
    if pairs_of_points.empty:
        return cycles

    # Get one pair of points.
    moving_and_fixed_point: Series = pairs_of_points.sample(n=1, random_state=random_state)
    moving_point: str = moving_and_fixed_point.index[0][0]
    fixed_point: str = moving_and_fixed_point.index[0][1]

    moves_tabu_list.add((moving_point, fixed_point))

    # Find the indexes of the pair of points.
    # tuple[index of the cycle in the cluster, index of the point in the cycle]
    moving_point_idx: tuple[int, int] | None = None
    fixed_point_idx: tuple[int, int] | None = None

    for i, cycle in enumerate(cycles_copy):
        for j, point in enumerate(cycle):
            if moving_point == point:
                moving_point_idx = (i, j)
                break
            if fixed_point == point:
                fixed_point_idx = (i, j)
                break

        if (moving_point_idx is not None) and (fixed_point_idx is not None):
            break

    # Find an index to put the moving point.
    moving_point_dest_idx: int = find_dest_idx(inst=inst, dest_cycle=cycles_copy[fixed_point_idx[0]],
                                               orig_point=moving_point, dest_point_idx=fixed_point_idx[1])

    # Move the point.
    cycles_copy[fixed_point_idx[0]].insert(moving_point_dest_idx,
                                           cycles_copy[moving_point_idx[0]].pop(moving_point_idx[1]))

    return cycles_copy


def perform_cluster_shake(inst: DataFrame, cycles: list[list[str]], hubs_tabu_list: set[str],
                          swaps_tabu_list: set[tuple[str, str]], moves_tabu_list: set[tuple[str, str]],
                          min_num_points_per_cycle: int, max_num_points_per_cycle: int, shake_method: int,
                          random_state: int) -> list[list[str]]:
    print('Fazendo o shake do cluster.')

    if shake_method == 0:
        return replace_cluster_hub(inst=inst, cycles=cycles, hubs_tabu_list=hubs_tabu_list,
                                   min_num_points_per_cycle=min_num_points_per_cycle,
                                   max_num_points_per_cycle=max_num_points_per_cycle, random_state=random_state)
    elif shake_method == 1:
        return swap_points_between_cycles(inst=inst, cycles=cycles, swaps_tabu_list=swaps_tabu_list,
                                          random_state=random_state)
    else:
        return move_point_between_cycles(inst=inst, cycles=cycles, moves_tabu_list=moves_tabu_list,
                                         min_num_points_per_cycle=min_num_points_per_cycle,
                                         max_num_points_per_cycle=max_num_points_per_cycle, random_state=random_state)


def replace_major_hub(inst: DataFrame, old_major_hub: str, cycles: list[list[list[str]]], major_hub_tabu_list: set[str],
                      min_num_points_per_cycle: int, max_num_points_per_cycle: int, random_state: int) -> tuple[
    str, list[list[list[str]]]]:
    print('Trocando o grande hub.')

    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    major_hub_tabu_list.add(old_major_hub)

    flat_cycles_without_hubs_and_old_major_hubs: list[str] = [point for cluster in cycles_copy for cycle in cluster for
                                                              point in cycle[1:-1] if point not in major_hub_tabu_list]

    new_major_hub: str
    nearest_point_to_old_major_hub: str
    new_major_hub, nearest_point_to_old_major_hub = get_points(inst=inst, orig=old_major_hub,
                                                               dests=flat_cycles_without_hubs_and_old_major_hubs,
                                                               random_state=random_state)

    # Find the index of the new major hub and an index to put the old major hub.
    # tuple[index of the cluster, index of the cycle in the cluster, index of the point in the cycle]
    new_major_hub_idx: tuple[int, int, int] | None = None
    old_major_hub_dest_idx: tuple[int, int, int] | None = None

    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            for k, point in enumerate(cycle):
                if new_major_hub == point:
                    new_major_hub_idx = (i, j, k)
                if nearest_point_to_old_major_hub == point:
                    old_major_hub_dest_idx = (i, j, find_dest_idx(inst=inst, orig_point=old_major_hub, dest_cycle=cycle,
                                                                  dest_point_idx=k))

                if (new_major_hub_idx is not None) and (old_major_hub_dest_idx is not None):
                    break
            if (new_major_hub_idx is not None) and (old_major_hub_dest_idx is not None):
                break
        if (new_major_hub_idx is not None) and (old_major_hub_dest_idx is not None):
            break

    # If the new major hub is the same point as the nearest point of the old major hub.
    if new_major_hub == nearest_point_to_old_major_hub:
        # The old major hub will replace the new major hub in the cycle.
        cycles_copy[new_major_hub_idx[0]][new_major_hub_idx[1]][new_major_hub_idx[2]] = old_major_hub
    else:
        # Remove the new major hub from the cycle it belonged.
        del cycles_copy[new_major_hub_idx[0]][new_major_hub_idx[1]][new_major_hub_idx[2]]

        # Insert the old major hub into a cycle.
        # If the indexes are in the same cycle and the index of the insertion operation (old major hub destination) is
        # to the right where the removal operation took place, correct the index position due to the offset caused by
        # the removal.
        if (new_major_hub_idx[0] == old_major_hub_dest_idx[0]) and (
                new_major_hub_idx[1] == old_major_hub_dest_idx[1]) and (
                new_major_hub_idx[2] < old_major_hub_dest_idx[2]):
            cycles_copy[old_major_hub_dest_idx[0]][old_major_hub_dest_idx[1]].insert(old_major_hub_dest_idx[2] - 1,
                                                                                     old_major_hub)
        else:
            cycles_copy[old_major_hub_dest_idx[0]][old_major_hub_dest_idx[1]].insert(old_major_hub_dest_idx[2],
                                                                                     old_major_hub)

    # If any of the cycles violates the minimum or the maximum number of points, return the original cycles.
    if any((len(cycle[1:-1]) < min_num_points_per_cycle) or (len(cycle[1:-1]) > max_num_points_per_cycle) for cluster in
           cycles_copy for cycle in cluster):
        return old_major_hub, cycles

    return new_major_hub, cycles_copy


def swap_points_between_clusters(inst: DataFrame, cycles: list[list[list[str]]], swaps_tabu_list: set[tuple[str, str]],
                                 random_state: int) -> list[list[list[str]]]:
    print('Trocando pontos entre clusters.')

    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    # Get pairs for each combination from origin to destination cycles except for the same cluster.
    pairs_of_points_by_orig_dest_cycles: list[Series] = [curr_pairs for i, orig_cluster in enumerate(cycles_copy) for
                                                         j, dest_cluster in enumerate(cycles_copy) if i != j for
                                                         orig_cycle in orig_cluster for dest_cycle in dest_cluster if
                                                         not (curr_pairs := get_pairs_of_points(inst=inst,
                                                                                                origs=orig_cycle[1:-1],
                                                                                                dests=dest_cycle[
                                                                                                    1:-1])).empty]

    # If there are no pairs of points, return the original cycles.
    if not pairs_of_points_by_orig_dest_cycles:
        return cycles

    pairs_of_points: Series = pd.concat(objs=pairs_of_points_by_orig_dest_cycles)

    # Exclude all swaps that are in the swap tabu list.
    pairs_of_points = pairs_of_points[~pairs_of_points.index.isin(swaps_tabu_list)]

    # If there are no pairs of points, return the original cycles.
    if pairs_of_points.empty:
        return cycles

    # Get one pair of points.
    points_to_swap: Series = pairs_of_points.sample(n=1, random_state=random_state)
    point0: str = points_to_swap.index[0][0]
    point1: str = points_to_swap.index[0][1]

    swaps_tabu_list.add((point0, point1))

    # Find the indexes of the pair of points.
    # tuple[index of the cluster, index of the cycle in the cluster, index of the point in the cycle]
    point0_idx: tuple[int, int, int] | None = None
    point1_idx: tuple[int, int, int] | None = None

    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            for k, point in enumerate(cycle):
                if point0 == point:
                    point0_idx = (i, j, k)
                    break
                if point1 == point:
                    point1_idx = (i, j, k)
                    break

            if (point0_idx is not None) and (point1_idx is not None):
                break
        if (point0_idx is not None) and (point1_idx is not None):
            break

    # Swap.
    cycles_copy[point0_idx[0]][point0_idx[1]][point0_idx[2]], cycles_copy[point1_idx[0]][point1_idx[1]][point1_idx[2]] = \
        cycles_copy[point1_idx[0]][point1_idx[1]][point1_idx[2]], cycles_copy[point0_idx[0]][point0_idx[1]][
            point0_idx[2]]

    return cycles_copy


def move_point_between_clusters(inst: DataFrame, cycles: list[list[list[str]]], moves_tabu_list: set[tuple[str, str]],
                                min_num_points_per_cycle: int, max_num_points_per_cycle: int, random_state: int) -> \
        list[list[list[str]]]:
    print('Movendo um ponto de um cluster para outro.')

    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    giveable_cycles: set[tuple[int, int]] = set()
    receivable_cycles: set[tuple[int, int]] = set()

    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            if len(cycle[1:-1]) > min_num_points_per_cycle:
                giveable_cycles.add((i, j))
            if len(cycle[1:-1]) < max_num_points_per_cycle:
                receivable_cycles.add((i, j))

    # If it doesn't exist giveable or receivable cycles, or there's only one giveable and receivable cycle, and they're
    # the same, return the original cycles.
    if (len(giveable_cycles) == 0) or (len(receivable_cycles) == 0) or (
            (len(giveable_cycles) == 1) and (len(receivable_cycles) == 1) and (giveable_cycles == receivable_cycles)):
        return cycles

    # Get pairs for each combination from giveable to receivable cycles except for the same cluster.
    pairs_of_points_by_giveable_receivable_cycles: list[Series] = [curr_pairs for giveable_cycle in giveable_cycles for
                                                                   receivable_cycle in receivable_cycles if
                                                                   (giveable_cycle[0] != receivable_cycle[0]) if not (
            curr_pairs := get_pairs_of_points(inst=inst, origs=cycles_copy[giveable_cycle[0]][giveable_cycle[1]][1:-1],
                                              dests=cycles_copy[receivable_cycle[0]][receivable_cycle[1]][1:-1])).empty]

    # If there are no pairs of points, return the original cycles.
    if not pairs_of_points_by_giveable_receivable_cycles:
        return cycles

    pairs_of_points: Series = pd.concat(objs=pairs_of_points_by_giveable_receivable_cycles)

    # Exclude all moves that are in the move tabu list.
    pairs_of_points = pairs_of_points[~pairs_of_points.index.isin(moves_tabu_list)]

    # If there are no pairs of points, return the original cycles.
    if pairs_of_points.empty:
        return cycles

    # Get one pair of points.
    moving_and_fixed_point: Series = pairs_of_points.sample(n=1, random_state=random_state)
    moving_point: str = moving_and_fixed_point.index[0][0]
    fixed_point: str = moving_and_fixed_point.index[0][1]

    moves_tabu_list.add((moving_point, fixed_point))

    # Find the indexes of the pair of points.
    # tuple[index of the cluster, index of the cycle in the cluster, index of the point in the cycle]
    moving_point_idx: tuple[int, int, int] | None = None
    fixed_point_idx: tuple[int, int, int] | None = None

    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            for k, point in enumerate(cycle):
                if moving_point == point:
                    moving_point_idx = (i, j, k)
                    break
                if fixed_point == point:
                    fixed_point_idx = (i, j, k)
                    break

            if (moving_point_idx is not None) and (fixed_point_idx is not None):
                break
        if (moving_point_idx is not None) and (fixed_point_idx is not None):
            break

    # Find an index to put the moving point.
    moving_point_dest_idx: int = find_dest_idx(inst=inst,
                                               dest_cycle=cycles_copy[fixed_point_idx[0]][fixed_point_idx[1]],
                                               orig_point=moving_point, dest_point_idx=fixed_point_idx[2])

    # Move the point.
    cycles_copy[fixed_point_idx[0]][fixed_point_idx[1]].insert(moving_point_dest_idx, cycles_copy[moving_point_idx[0]][
        moving_point_idx[1]].pop(moving_point_idx[2]))

    return cycles_copy


def perform_overall_shake(inst: DataFrame, major_hub: str, cycles: list[list[list[str]]], major_hub_tabu_list: set[str],
                          swaps_tabu_list: set[tuple[str, str]], moves_tabu_list: set[tuple[str, str]],
                          min_num_points_per_cycle: int, max_num_points_per_cycle: int, shake_method: int,
                          random_state: int) -> tuple[str, list[list[list[str]]]]:
    print('Fazendo o shake geral.')

    if shake_method == 0:
        return replace_major_hub(inst=inst, old_major_hub=major_hub, cycles=cycles,
                                 major_hub_tabu_list=major_hub_tabu_list,
                                 min_num_points_per_cycle=min_num_points_per_cycle,
                                 max_num_points_per_cycle=max_num_points_per_cycle, random_state=random_state)
    elif shake_method == 1:
        return major_hub, swap_points_between_clusters(inst=inst, cycles=cycles, swaps_tabu_list=swaps_tabu_list,
                                                       random_state=random_state)
    else:
        return major_hub, move_point_between_clusters(inst=inst, cycles=cycles, moves_tabu_list=moves_tabu_list,
                                                      min_num_points_per_cycle=min_num_points_per_cycle,
                                                      max_num_points_per_cycle=max_num_points_per_cycle,
                                                      random_state=random_state)


def calculate_costs(inst: DataFrame, major_hub: str, cycles: list[list[list[str]]]) -> tuple[
    list[list[int]], list[int], int]:
    cycle_costs: list[list[int]] = [[calculate_cycle_cost(inst=inst, cycle=cycle) for cycle in cluster] for cluster in
                                    cycles]
    cluster_costs: list[int] = [(sum(cluster) + calculate_cycle_cost(inst=inst, cycle=[cycles[i][0][0], major_hub])) for
                                i, cluster in enumerate(cycle_costs)]
    overall_cost: int = sum(cluster_costs)

    return cycle_costs, cluster_costs, overall_cost


def perform_cluster_neighborhood_change_sequential(inst: DataFrame, major_hub: str, old_cycles: list[list[str]],
                                                   new_cycles: list[list[str]], curr_shake_method: int) -> tuple[
    list[list[str]], int]:
    old_cost: int = calculate_costs(inst=inst, major_hub=major_hub, cycles=[old_cycles])[2]
    new_cost: int = calculate_costs(inst=inst, major_hub=major_hub, cycles=[new_cycles])[2]

    if new_cost < old_cost:
        return new_cycles, 0
    else:
        return old_cycles, curr_shake_method + 1


def optimize_cycles(inst: DataFrame, major_hub: str, cycles: list[list[list[str]]], min_num_points_per_cycle: int,
                    max_num_points_per_cycle: int, random_state: int) -> list[list[list[str]]]:
    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    for i, curr_cluster in enumerate(cycles_copy):
        print()
        print(f'Otimizando o cluster {i}.')

        curr_cycles: list[list[str]] = perform_vnd(inst=inst, cycles=curr_cluster)

        curr_shake_method: int = 0
        num_shake_methods: int = 3
        hubs_tabu_list: set[str] = set()
        swaps_tabu_list: set[tuple[str, str]] = set()
        moves_tabu_list: set[tuple[str, str]] = set()
        while curr_shake_method < num_shake_methods:
            shaken_cycles: list[list[str]]
            shaken_cycles = perform_cluster_shake(inst=inst, cycles=curr_cycles, hubs_tabu_list=hubs_tabu_list,
                                                  swaps_tabu_list=swaps_tabu_list, moves_tabu_list=moves_tabu_list,
                                                  min_num_points_per_cycle=min_num_points_per_cycle,
                                                  max_num_points_per_cycle=max_num_points_per_cycle,
                                                  shake_method=curr_shake_method, random_state=random_state)
            cycles_after_vnd: list[list[str]] = perform_vnd(inst=inst, cycles=shaken_cycles)
            curr_cycles, curr_shake_method = perform_cluster_neighborhood_change_sequential(inst=inst,
                                                                                            major_hub=major_hub,
                                                                                            old_cycles=curr_cycles,
                                                                                            new_cycles=cycles_after_vnd,
                                                                                            curr_shake_method=curr_shake_method)
        cycles_copy[i] = curr_cycles

    return cycles_copy


def perform_overall_neighborhood_change_sequential(inst: DataFrame, old_major_hub: str, new_major_hub: str,
                                                   old_cycles: list[list[list[str]]], new_cycles: list[list[list[str]]],
                                                   curr_shake_method: int) -> tuple[str, list[list[list[str]]], int]:
    old_cost: int = calculate_costs(inst=inst, major_hub=old_major_hub, cycles=old_cycles)[2]
    new_cost: int = calculate_costs(inst=inst, major_hub=new_major_hub, cycles=new_cycles)[2]

    if new_cost < old_cost:
        return new_major_hub, new_cycles, 0
    else:
        return old_major_hub, old_cycles, curr_shake_method + 1


def perform_optimization(inst: DataFrame, major_hub: str, cycles: list[list[list[str]]], min_num_points_per_cycle: int,
                         max_num_points_per_cycle: int, random_state: int) -> tuple[
    str, list[str], list[list[list[str]]]]:
    curr_major_hub: str = major_hub
    curr_cycles: list[list[list[str]]] = optimize_cycles(inst=inst, major_hub=major_hub, cycles=cycles,
                                                         min_num_points_per_cycle=min_num_points_per_cycle,
                                                         max_num_points_per_cycle=max_num_points_per_cycle,
                                                         random_state=random_state)

    curr_shake_method: int = 0
    num_shake_methods: int = 3
    major_hub_tabu_list: set[str] = set()
    swaps_tabu_list: set[tuple[str, str]] = set()
    moves_tabu_list: set[tuple[str, str]] = set()
    while curr_shake_method < num_shake_methods:
        new_major_hub: str
        shaken_cycles: list[list[list[str]]]
        new_major_hub, shaken_cycles = perform_overall_shake(inst=inst, major_hub=curr_major_hub, cycles=curr_cycles,
                                                             major_hub_tabu_list=major_hub_tabu_list,
                                                             swaps_tabu_list=swaps_tabu_list,
                                                             moves_tabu_list=moves_tabu_list,
                                                             min_num_points_per_cycle=min_num_points_per_cycle,
                                                             max_num_points_per_cycle=max_num_points_per_cycle,
                                                             shake_method=curr_shake_method, random_state=random_state)
        optimized_cycles: list[list[list[str]]]
        optimized_cycles = optimize_cycles(inst=inst, major_hub=new_major_hub, cycles=shaken_cycles,
                                           min_num_points_per_cycle=min_num_points_per_cycle,
                                           max_num_points_per_cycle=max_num_points_per_cycle, random_state=random_state)
        curr_major_hub, curr_cycles, curr_shake_method = perform_overall_neighborhood_change_sequential(inst=inst,
                                                                                                        old_major_hub=curr_major_hub,
                                                                                                        new_major_hub=new_major_hub,
                                                                                                        old_cycles=curr_cycles,
                                                                                                        new_cycles=optimized_cycles,
                                                                                                        curr_shake_method=curr_shake_method)

    return curr_major_hub, [cluster[0][0] for cluster in curr_cycles], curr_cycles
