import random

from pandas import DataFrame

random.seed(42)

import numpy as np

MAXIMUM_INVALID_VALUE: float = 1000000.0


def calculate_cycle_cost(instance: DataFrame, cycle: list[str | int]) -> float:
    cost: float = 0.0
    for i in range(len(cycle) - 1):
        cost += instance[cycle[i]][cycle[i + 1]]

    return cost


def create_greedy_cycle(instance: DataFrame, origin_destination: str | int | None = None) -> list[str | int]:
    number_of_points: int = len(instance)
    first_point: str | int = instance.index[0]

    if origin_destination is None:
        number_of_attempts_creating_cycle: int = 0
    else:
        number_of_attempts_creating_cycle: int = -1

    cycle: list[str | int] = [first_point] * (number_of_points + 1)

    while not is_valid_cycle(instance=instance, cycle=cycle):
        if number_of_attempts_creating_cycle >= 0:
            current_point: str | int = instance.index[number_of_attempts_creating_cycle]
        else:
            current_point: str | int = origin_destination

        cycle = [current_point] * len(cycle)

        # Iterate adjacency matrix.
        visited_points: set[str | int] = set()
        for i in range(1, number_of_points):
            visited_points.add(current_point)

            min_cost: float = MAXIMUM_INVALID_VALUE
            next_point: str | int | None = None
            for neighbor_point in instance.index.values:
                cost: float = instance[current_point][neighbor_point]
                if neighbor_point not in visited_points and (0.0 < cost < min_cost):
                    next_point = neighbor_point
                    min_cost = cost

            if next_point is None:
                break

            current_point = next_point
            cycle[i] = current_point

        number_of_attempts_creating_cycle += 1
        if number_of_attempts_creating_cycle == number_of_points:
            raise Exception('Nenhum ciclo válido foi encontrado!')

    return cycle


def is_valid_cycle(instance: DataFrame, cycle: list[str | int]) -> bool:
    # Find for invalid edges.
    for i in range(len(cycle) - 1):
        cost: float = instance[cycle[i]][cycle[i + 1]]
        if (cost == 0.0) or (cost >= MAXIMUM_INVALID_VALUE):
            return False

    # Find for duplicate points.
    return len(np.unique(cycle[1:])) == len(cycle[1:])
