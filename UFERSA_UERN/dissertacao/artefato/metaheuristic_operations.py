import random

import pandas as pd
from pandas import DataFrame, Series

from connection_operations import calculate_cycle_cost


def perform_two_opt(cycle: list[str]) -> list[list[str]]:
    print('Fazendo o 2-opt.')

    cycle_copy: list[str] = cycle.copy()
    num_points: int = len(cycle_copy)

    # The formula used to initialize this list is just the inverse of the loop below.
    opted_cycles: list[list[str]] = [[] for _ in range(int(((num_points - 2) * ((num_points - 3) / 2)) + 1))]

    opted_cycles_index: int = 0
    # Starts at 1(i) and ends at n-1(j) so as not to modify the hub.
    for i in range(1, num_points - 2):
        for j in range(i + 1, num_points - 1):
            opted_cycles[opted_cycles_index] = cycle_copy.copy()
            cycle_copy.insert(i, cycle_copy.pop(j))
            opted_cycles_index += 1
    opted_cycles[opted_cycles_index] = cycle_copy.copy()

    return opted_cycles


def perform_vnd(inst: DataFrame, cycles: list[list[str]]) -> list[list[str]]:
    print('Fazendo o VND.')

    best_cycles: list[list[str]] = [cycle.copy() for cycle in cycles]

    for i, curr_best_cycle in enumerate(best_cycles):
        best_cycle: list[str] = curr_best_cycle.copy()

        curr_cost: int = calculate_cycle_cost(inst=inst, cycle=best_cycle)
        best_cost: int = curr_cost
        while curr_cost <= best_cost:
            opted_cycles: list[list[str]] = perform_two_opt(cycle=best_cycle)
            opted_cycle_costs: list[int] = [calculate_cycle_cost(inst=inst, cycle=opted_cycle) for opted_cycle in
                                            opted_cycles]

            # Best improvement.
            # lowest_cost_index: int = min(range(len(opted_cycle_costs)), key=opted_cycle_costs.__getitem__)
            # curr_cycle = opted_cycles[lowest_cost_index].copy()
            # curr_cost = opted_cycle_costs[lowest_cost_index]
            # if curr_cost < best_cost:
            #     best_cycle = curr_cycle.copy()
            #     best_cost = curr_cost
            # else:
            #     curr_cost += 1

            # First improvement.
            for curr_cycle, curr_cost in zip(opted_cycles, opted_cycle_costs):
                if curr_cost < best_cost:
                    best_cycle = curr_cycle.copy()
                    best_cost = curr_cost
                    break

        best_cycles[i] = best_cycle

    return best_cycles


def get_one_point(inst: DataFrame, dests: list[str], orig: str) -> tuple[str, str]:
    # Search for the 'n' nearest points around the origin.
    num_nearest_points: int = 10
    nearest_points: Series = inst.loc[dests, orig].nsmallest(n=num_nearest_points)
    # Select one point randomly and the nearest point to the origin.
    return nearest_points.sample(n=1, random_state=42).index.item(), nearest_points.index[0]


def get_pair_of_points(inst: DataFrame, origs: list[str], dests: list[str]) -> Series:
    # Select the 'n' nearest pair of points.
    num_nearest_pair_of_points: int = 10
    nearest_pair_of_points: Series = inst.loc[origs, dests].stack().nsmallest(n=num_nearest_pair_of_points)
    # Select one pair of points randomly.
    return nearest_pair_of_points.sample(n=1, random_state=42)


def get_dest_idx(inst: DataFrame, cycle: list[str], point: str, second_point_idx: int) -> int:
    left_adjacent_idx: int = (second_point_idx - 1) % len(cycle)
    right_adjacent_idx: int = (second_point_idx + 1) % len(cycle)
    if inst.at[cycle[left_adjacent_idx], point] < inst.at[cycle[right_adjacent_idx], point]:
        return second_point_idx
    else:
        return second_point_idx + 1


def switch_hub(inst: DataFrame, cycles: list[list[str]], hubs_tabu_list: set[str], min_num_points_per_cycle: int,
               max_num_points_per_cycle: int) -> list[list[str]]:
    print('Trocando o hub.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    old_hub: str = cycles_copy[0][0]
    hubs_tabu_list.add(old_hub)

    flat_cycles_without_old_hubs: list[str] = [point for cycle in cycles_copy for point in cycle[1:-1] if
                                               point not in hubs_tabu_list]

    # Search for the 'n' nearest points to choose the next hub.
    num_nearest_points: int = 10
    nearest_points_to_old_hub: Series = inst.loc[flat_cycles_without_old_hubs, old_hub].nsmallest(n=num_nearest_points)
    # Select one point randomly.
    new_hub: str = nearest_points_to_old_hub.sample(n=1, random_state=42).index.item()

    nearest_point_to_old_hub: str = nearest_points_to_old_hub.index[0]
    for i, cycle in enumerate(cycles_copy):
        # Remove the old hub from the cycles, except for the one where the nearest point to the old hub is located.
        # In this case, just remove the duplicate in the first index.
        if nearest_point_to_old_hub in cycle:
            cycles_copy[i] = cycles_copy[i][1:]
        else:
            cycles_copy[i] = cycles_copy[i][1:-1]

    # If any of the cycles violates the minimum and maximum number of points, return the original cycles.
    for i, cycle in enumerate(cycles_copy):
        if (len(cycle) < min_num_points_per_cycle) or (len(cycle) > max_num_points_per_cycle):
            return cycles

    for i, cycle in enumerate(cycles_copy):
        if new_hub in cycle:
            # Rotate the cycle so that the new hub is in the first index.
            new_hub_idx: int = cycle.index(new_hub)
            cycles_copy[i] = cycles_copy[i][new_hub_idx:] + cycles_copy[i][:new_hub_idx]
            # Duplicate the new hub at the end of the cycle.
            cycles_copy[i].append(new_hub)
        else:
            nearest_point_to_new_hub: str = inst.loc[cycle, new_hub].idxmin()
            nearest_point_to_new_hub_idx: int = cycle.index(nearest_point_to_new_hub)
            # Rotate the cycle so that the nearest point to the new hub and the nearest adjacent of this nearest point
            # to the new hub remain in the first and last indexes.
            left_adjacent_idx: int = (nearest_point_to_new_hub_idx - 1) % len(cycle)
            right_adjacent_idx: int = (nearest_point_to_new_hub_idx + 1) % len(cycle)
            if inst.at[cycle[left_adjacent_idx], new_hub] < inst.at[cycle[right_adjacent_idx], new_hub]:
                # If the nearest adjacent is to the left, rotate the cycle so that the nearest is first and the
                # adjacent is last.
                cycles_copy[i] = cycles_copy[i][nearest_point_to_new_hub_idx:] + cycles_copy[i][
                    :nearest_point_to_new_hub_idx]
            else:
                # If the nearest adjacent is to the right, rotate the cycle so that the nearest is last and the
                # adjacent is first.
                cycles_copy[i] = cycles_copy[i][right_adjacent_idx:] + cycles_copy[i][:right_adjacent_idx]

            # Add new hub.
            cycles_copy[i].insert(0, new_hub)
            cycles_copy[i].append(new_hub)

    return cycles_copy


def swap_points_between_cycles(inst: DataFrame, cycles: list[list[str]]) -> list[list[str]]:
    print('Trocando pontos entre ciclos.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    random_cycle_idx: int = random.randint(a=0, b=len(cycles_copy) - 1)

    flat_cycles_without_hub_and_random_cycle: list[str] = [point for i, cycle in enumerate(cycles_copy) if
                                                           i != random_cycle_idx for point in cycle[1:-1]]

    points_to_swap: Series = get_pair_of_points(inst=inst, origs=cycles_copy[random_cycle_idx][1:-1],
                                                dests=flat_cycles_without_hub_and_random_cycle)

    other_cycle_idx: int = -1
    for i, cycle in enumerate(cycles_copy):
        if points_to_swap.index[0][1] in cycle:
            other_cycle_idx = i
            break

    # Get indexes of the points that will be swapped.
    point0_idx: int = cycles_copy[random_cycle_idx].index(points_to_swap.index[0][0])
    point1_idx: int = cycles_copy[other_cycle_idx].index(points_to_swap.index[0][1])

    # Swap.
    cycles_copy[random_cycle_idx][point0_idx], cycles_copy[other_cycle_idx][point1_idx] = cycles_copy[other_cycle_idx][
        point1_idx], cycles_copy[random_cycle_idx][point0_idx]

    return cycles_copy


def move_point_between_cycles(inst: DataFrame, cycles: list[list[str]], min_num_points_per_cycle: int,
                              max_num_points_per_cycle: int) -> list[list[str]]:
    print('Movendo um ponto de um ciclo para outro.')

    cycles_copy: list[list[str]] = [cycle.copy() for cycle in cycles]

    giveable_cycles: list[int] = []
    receivable_cycles: list[int] = []

    for i, cycle in enumerate(cycles_copy):
        if len(cycle[1:-1]) > min_num_points_per_cycle:
            giveable_cycles.append(i)
        if len(cycle[1:-1]) < max_num_points_per_cycle:
            receivable_cycles.append(i)

    # If it doesn't exist giveable or receivable cycles,
    # or there's only one giveable and receivable cycle, and they're the same.
    if (len(giveable_cycles) == 0) or (len(receivable_cycles) == 0) or (
            (len(giveable_cycles) == 1) and (len(receivable_cycles) == 1) and (giveable_cycles == receivable_cycles)):
        return cycles

    # Get a giveable cycle randomly.
    random_giveable_cycle_idx: int = random.choice(seq=giveable_cycles)
    # Flatten the receivable cycles avoiding the inclusion of the random giveable cycle.
    flat_receivable_cycles_without_random_giveable_cycle: list[str] = [point for i, cycle in enumerate(cycles_copy) if
                                                                       (i in receivable_cycles) and (
                                                                               i != random_giveable_cycle_idx) for point
                                                                       in cycle[1:-1]]

    pair_of_points: Series = get_pair_of_points(inst=inst, origs=cycles_copy[random_giveable_cycle_idx][1:-1],
                                                dests=flat_receivable_cycles_without_random_giveable_cycle)

    moving_point: str = pair_of_points.index[0][0]
    nearest_point_in_receivable_cycle_to_moving_point: str = pair_of_points.index[0][1]

    moving_point_orig_idx: int = cycles_copy[random_giveable_cycle_idx].index(moving_point)
    receivable_cycle_idx: int = -1
    nearest_point_in_receivable_cycle_to_moving_point_idx: int = -1
    for i, cycle in enumerate(cycles_copy):
        if nearest_point_in_receivable_cycle_to_moving_point in cycle:
            receivable_cycle_idx = i
            nearest_point_in_receivable_cycle_to_moving_point_idx = cycle.index(
                nearest_point_in_receivable_cycle_to_moving_point)
            break

    # Find an index to put the moving point.
    # Check the distance from the moving point to the adjacent points of the nearest point of the receivable cycle. If
    # the nearest adjacent is to the left, put the moving point to the left of the nearest point. If the nearest
    # adjacent is to the right, put the moving point to the right of the nearest point.
    moving_point_destination_idx: int
    if inst.at[
        cycles_copy[receivable_cycle_idx][nearest_point_in_receivable_cycle_to_moving_point_idx - 1], moving_point] < \
            inst.at[cycles_copy[receivable_cycle_idx][
                nearest_point_in_receivable_cycle_to_moving_point_idx + 1], moving_point]:
        moving_point_destination_idx = nearest_point_in_receivable_cycle_to_moving_point_idx
    else:
        moving_point_destination_idx = nearest_point_in_receivable_cycle_to_moving_point_idx + 1

    # Move the point.
    cycles_copy[receivable_cycle_idx].insert(moving_point_destination_idx,
                                             cycles_copy[random_giveable_cycle_idx].pop(moving_point_orig_idx))

    return cycles_copy


def perform_cluster_shake(inst: DataFrame, cycles: list[list[str]], hubs_tabu_list: set[str],
                          min_num_points_per_cycle: int, max_num_points_per_cycle: int, shake_method: int) -> list[
    list[str]]:
    print('Fazendo o shake do cluster.')

    if shake_method == 0:
        return switch_hub(inst=inst, cycles=cycles, hubs_tabu_list=hubs_tabu_list,
                          min_num_points_per_cycle=min_num_points_per_cycle,
                          max_num_points_per_cycle=max_num_points_per_cycle)
    elif shake_method == 1:
        return swap_points_between_cycles(inst=inst, cycles=cycles)
    else:
        return move_point_between_cycles(inst=inst, cycles=cycles, min_num_points_per_cycle=min_num_points_per_cycle,
                                         max_num_points_per_cycle=max_num_points_per_cycle)


def move_point_between_clusters(inst: DataFrame, cycles: list[list[list[str]]], min_num_points_per_cycle: int,
                                max_num_points_per_cycle: int) -> list[list[list[str]]]:
    print('Movendo um ponto de um cluster para outro.')

    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    giveable_cycles: list[tuple[int, int]] = []
    receivable_cycles: list[tuple[int, int]] = []

    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            if len(cycle[1:-1]) > min_num_points_per_cycle:
                giveable_cycles.append((i, j))
            if len(cycle[1:-1]) < max_num_points_per_cycle:
                receivable_cycles.append((i, j))

    # If it doesn't exist giveable or receivable cycles,
    # or there's only one giveable and receivable cycle, and they're the same.
    if (len(giveable_cycles) == 0) or (len(receivable_cycles) == 0) or (
            (len(giveable_cycles) == 1) and (len(receivable_cycles) == 1) and (giveable_cycles == receivable_cycles)):
        return cycles

    print(giveable_cycles)
    print(receivable_cycles)

    # Get a pair for each combination of giveable and receivable cycle except for the same cluster.
    pair_of_points_from_giveable_to_receivable_cycles: list[Series] = [
        get_pair_of_points(inst=inst, origs=cycles_copy[giveable_cycle[0]][giveable_cycle[1]][1:-1],
                           dests=cycles_copy[receivable_cycle[0]][receivable_cycle[1]][1:-1]) for giveable_cycle in
        giveable_cycles for receivable_cycle in receivable_cycles if
        (giveable_cycle != receivable_cycle) and (giveable_cycle[0] != receivable_cycle[0])]

    pair_of_points: Series = pd.concat(objs=pair_of_points_from_giveable_to_receivable_cycles).nsmallest(n=10).sample(
        n=1, random_state=42)
    print(pair_of_points)
    moving_point: str = pair_of_points.index[0][0]
    nearest_point_in_receivable_cycle_to_moving_point: str = pair_of_points.index[0][1]
    print(moving_point)
    print(nearest_point_in_receivable_cycle_to_moving_point)
    moving_point_idx: tuple[int, int, int] = (-1, -1, -1)
    nearest_point_in_receivable_cycle_to_moving_point_idx: tuple[int, int, int] = (-1, -1, -1)
    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            if moving_point in cycle:
                moving_point_idx = (i, j, cycle.index(moving_point))
                break
            if nearest_point_in_receivable_cycle_to_moving_point in cycle:
                nearest_point_in_receivable_cycle_to_moving_point_idx = (i, j, cycle.index(
                    nearest_point_in_receivable_cycle_to_moving_point))
                break
        if (moving_point_idx != (-1, -1, -1)) and (
                nearest_point_in_receivable_cycle_to_moving_point_idx != (-1, -1, -1)):
            break

    print(moving_point_idx)
    print(nearest_point_in_receivable_cycle_to_moving_point_idx)
    # Find an index to put the moving point.
    # Check the distance from the moving point to the adjacent points of the nearest point of the receivable cycle. If
    # the nearest adjacent is to the left, put the moving point to the left of the nearest point. If the nearest
    # adjacent is to the right, put the moving point to the right of the nearest point.
    moving_point_destination_idx: int
    if inst.at[cycles_copy[nearest_point_in_receivable_cycle_to_moving_point_idx[0]][
        nearest_point_in_receivable_cycle_to_moving_point_idx[1]][
        nearest_point_in_receivable_cycle_to_moving_point_idx[2] - 1], moving_point] < inst.at[
        cycles_copy[nearest_point_in_receivable_cycle_to_moving_point_idx[0]][
            nearest_point_in_receivable_cycle_to_moving_point_idx[1]][
            nearest_point_in_receivable_cycle_to_moving_point_idx[2] - 1], moving_point]:
        moving_point_destination_idx = nearest_point_in_receivable_cycle_to_moving_point_idx[2]
    else:
        moving_point_destination_idx = nearest_point_in_receivable_cycle_to_moving_point_idx[2] + 1

    # Move the point.
    cycles_copy[nearest_point_in_receivable_cycle_to_moving_point_idx[0]][
        nearest_point_in_receivable_cycle_to_moving_point_idx[1]].insert(moving_point_destination_idx,
                                                                         cycles_copy[moving_point_idx[0]][
                                                                             moving_point_idx[1]].pop(
                                                                             moving_point_idx[2]))

    print(cycles_copy)
    exit(66)
    return cycles_copy


def replace_central_point(inst: DataFrame, central_point: str, central_point_tabu_list: set[str],
                          cycles: list[list[list[str]]], min_num_points_per_cycle: int,
                          max_num_points_per_cycle: int) -> tuple[str, list[list[list[str]]]]:
    print('Trocando o ponto central.')

    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    central_point_tabu_list.add(central_point)

    flat_cycles_without_hubs_and_central_point: list[str] = [point for cluster in cycles_copy for cycle in cluster for
                                                             point in cycle[1:-1] if
                                                             point not in central_point_tabu_list]

    new_central_point: str
    nearest_point_to_old_central_point: str
    new_central_point, nearest_point_to_old_central_point = get_one_point(inst=inst,
                                                                          dests=flat_cycles_without_hubs_and_central_point,
                                                                          orig=central_point)

    print(new_central_point)
    print(nearest_point_to_old_central_point)
    old_central_point_dest_idx: tuple[int, int, int] = (-1, -1, -1)
    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            if nearest_point_to_old_central_point in cycle:
                old_central_point_dest_idx = (i, j, get_dest_idx(inst=inst, cycle=cycle, point=central_point,
                                                                 second_point_idx=cycle.index(
                                                                     nearest_point_to_old_central_point)))
                break
        if old_central_point_dest_idx != (-1, -1, -1):
            break

    print(old_central_point_dest_idx)
    # Insert old central point to a new cycle.
    cycles_copy[old_central_point_dest_idx[0]][old_central_point_dest_idx[1]].insert(old_central_point_dest_idx[2],
                                                                                     central_point)
    # Remove the new central point from the cycle it belonged.
    for i, cluster in enumerate(cycles_copy):
        for j, cycle in enumerate(cluster):
            if new_central_point in cycle:
                cycle.remove(new_central_point)
                break

    print(cycles_copy)
    exit(99)
    return new_central_point, cycles_copy


def perform_overall_shake(inst: DataFrame, central_point: str, central_point_tabu_list: set[str],
                          cycles: list[list[list[str]]], min_num_points_per_cycle: int, max_num_points_per_cycle: int,
                          shake_method: int) -> tuple[str, list[list[list[str]]]]:
    print('Fazendo o shake geral.')

    if shake_method == 0:
        return central_point, move_point_between_clusters(inst=inst, cycles=cycles,
                                                          min_num_points_per_cycle=min_num_points_per_cycle,
                                                          max_num_points_per_cycle=max_num_points_per_cycle)
    else:
        return replace_central_point(inst=inst, central_point=central_point,
                                     central_point_tabu_list=central_point_tabu_list, cycles=cycles,
                                     min_num_points_per_cycle=min_num_points_per_cycle,
                                     max_num_points_per_cycle=max_num_points_per_cycle)


def calculate_costs(inst: DataFrame, central_point: str, cycles: list[list[list[str]]]) -> tuple[
    list[list[int]], list[int], int]:
    cycle_costs: list[list[int]] = [[calculate_cycle_cost(inst=inst, cycle=cycle) for cycle in cluster] for cluster in
                                    cycles]
    cluster_costs: list[int] = [(sum(cluster) + calculate_cycle_cost(inst=inst, cycle=[cycles[i][0][0], central_point]))
                                for i, cluster in enumerate(cycle_costs)]
    overall_cost: int = sum(cluster_costs)

    return cycle_costs, cluster_costs, overall_cost


def perform_cluster_neighborhood_change_sequential(inst: DataFrame, central_point: str, old_cycles: list[list[str]],
                                                   new_cycles: list[list[str]], curr_shake_method: int) -> tuple[
    list[list[str]], int]:
    old_cost: int = calculate_costs(inst=inst, central_point=central_point, cycles=[old_cycles])[2]
    new_cost: int = calculate_costs(inst=inst, central_point=central_point, cycles=[new_cycles])[2]

    if new_cost < old_cost:
        return new_cycles, 0
    else:
        return old_cycles, curr_shake_method + 1


def optimize_cycles(inst: DataFrame, central_point: str, cycles: list[list[list[str]]], min_num_points_per_cycle: int,
                    max_num_points_per_cycle: int) -> list[list[list[str]]]:
    cycles_copy: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    for i, curr_cluster in enumerate(cycles_copy):
        print()
        print(f'Otimizando o cluster {i}.')

        curr_cycles: list[list[str]] = perform_vnd(inst=inst, cycles=curr_cluster)

        curr_shake_method: int = 0
        num_shake_methods: int = 3
        hubs_tabu_list: set[str] = set()
        while curr_shake_method < num_shake_methods:
            shaken_cycles: list[list[str]]
            shaken_cycles = perform_cluster_shake(inst=inst, cycles=curr_cycles, hubs_tabu_list=hubs_tabu_list,
                                                  min_num_points_per_cycle=min_num_points_per_cycle,
                                                  max_num_points_per_cycle=max_num_points_per_cycle,
                                                  shake_method=curr_shake_method)
            vndded_cycles: list[list[str]] = perform_vnd(inst=inst, cycles=shaken_cycles)
            curr_cycles, curr_shake_method = perform_cluster_neighborhood_change_sequential(inst=inst,
                                                                                            central_point=central_point,
                                                                                            old_cycles=curr_cycles,
                                                                                            new_cycles=vndded_cycles,
                                                                                            curr_shake_method=curr_shake_method)
        cycles_copy[i] = curr_cycles

    return cycles_copy


def perform_overall_neighborhood_change_sequential(inst: DataFrame, old_central_point: str, new_central_point: str,
                                                   old_cycles: list[list[list[str]]], new_cycles: list[list[list[str]]],
                                                   curr_shake_method: int) -> tuple[str, list[list[list[str]]], int]:
    old_cost: int = calculate_costs(inst=inst, central_point=old_central_point, cycles=old_cycles)[2]
    new_cost: int = calculate_costs(inst=inst, central_point=new_central_point, cycles=new_cycles)[2]

    if new_cost < old_cost:
        return new_central_point, new_cycles, 0
    else:
        return old_central_point, old_cycles, curr_shake_method + 1


def perform_optimization(inst: DataFrame, central_point: str, cycles: list[list[list[str]]],
                         min_num_points_per_cycle: int, max_num_points_per_cycle: int) -> tuple[
    list[str], list[list[list[str]]]]:
    best_cycles: list[list[list[str]]] = [[cycle.copy() for cycle in cluster] for cluster in cycles]

    # TODO apague isso depois
    # print(move_point_between_clusters(inst=inst, cycles=best_cycles, min_num_points_per_cycle=min_num_points_per_cycle,
    #                                   max_num_points_per_cycle=max_num_points_per_cycle))
    print(replace_central_point(inst=inst, central_point=central_point, central_point_tabu_list=set(), cycles=cycles,
                                min_num_points_per_cycle=min_num_points_per_cycle,
                                max_num_points_per_cycle=max_num_points_per_cycle))
    # TODO apague isso depois

    initial_cycle_costs: list[list[int]]
    initial_cluster_costs: list[int]
    initial_overall_cost: int
    initial_cycle_costs, initial_cluster_costs, initial_overall_cost = calculate_costs(inst=inst,
                                                                                       central_point=central_point,
                                                                                       cycles=best_cycles)
    print('Custos iniciais')
    print('Custos por ciclo:', initial_cycle_costs)
    print('Custos por cluster:', initial_cluster_costs)
    print('Custo geral:', initial_overall_cost)
    print()

    curr_central_point: str = central_point
    curr_cycles: list[list[list[str]]] = optimize_cycles(inst=inst, central_point=central_point, cycles=best_cycles,
                                                         min_num_points_per_cycle=min_num_points_per_cycle,
                                                         max_num_points_per_cycle=max_num_points_per_cycle)

    curr_shake_method: int = 0
    num_shake_methods: int = 2
    central_points_tabu_list: set[str] = set()
    while curr_shake_method < num_shake_methods:
        new_central_point: str
        shaken_cycles: list[list[list[str]]]
        new_central_point, shaken_cycles = perform_overall_shake(inst=inst, central_point=central_point,
                                                                 central_point_tabu_list=central_points_tabu_list,
                                                                 cycles=curr_cycles,
                                                                 min_num_points_per_cycle=min_num_points_per_cycle,
                                                                 max_num_points_per_cycle=max_num_points_per_cycle,
                                                                 shake_method=curr_shake_method)
        optimized_cycles: list[list[list[str]]]
        optimized_cycles = optimize_cycles(inst=inst, central_point=new_central_point, cycles=shaken_cycles,
                                           min_num_points_per_cycle=min_num_points_per_cycle,
                                           max_num_points_per_cycle=max_num_points_per_cycle)
        curr_central_point, curr_cycles, curr_shake_method = perform_overall_neighborhood_change_sequential(inst=inst,
                                                                                                            old_central_point=curr_central_point,
                                                                                                            new_central_point=new_central_point,
                                                                                                            old_cycles=curr_cycles,
                                                                                                            new_cycles=optimized_cycles,
                                                                                                            curr_shake_method=curr_shake_method)

    central_point = curr_central_point
    best_cycles = curr_cycles

    final_cycle_costs: list[list[int]]
    final_cluster_costs: list[int]
    final_overall_cost: int
    final_cycle_costs, final_cluster_costs, final_overall_cost = calculate_costs(inst=inst, central_point=central_point,
                                                                                 cycles=best_cycles)
    print('Custos finais')
    print('Custos por ciclo:', final_cycle_costs)
    print('Custos por cluster:', final_cluster_costs)
    print('Custo geral:', final_overall_cost)
    print()

    for i in range(len(final_cluster_costs)):
        print(f'Porcentagem da diferença de custo do cluster {i}: '
              f'{(((final_cluster_costs[i] - initial_cluster_costs[i]) / initial_cluster_costs[i]) * 100):.2f} %')
    print(f'Porcentagem da diferença de custo geral: '
          f'{(((final_overall_cost - initial_overall_cost) / initial_overall_cost) * 100):.2f} %')

    return [cycle[0][0] for cycle in best_cycles], best_cycles
