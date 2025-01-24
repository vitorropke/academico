import random

from tsplib95.models import Problem

random.seed(42)

import numpy as np


def create_greedy_cycle(instance: Problem, origin_destination: int | None = None) -> np.ndarray[int]:
    number_cities: int = instance.dimension

    if origin_destination is None:
        number_attempts_creating_cycle: int = 0
    else:
        number_attempts_creating_cycle: int = -1

    cycle: np.ndarray[int] = np.zeros(shape=number_cities + 1, dtype=int)

    while not is_valid_cycle(instance=instance, cycle=cycle):
        current_city: int = origin_destination

        if number_attempts_creating_cycle >= 0:
            current_city = random.randint(a=0, b=number_cities - 1)

        cycle.fill(current_city)

        # Create a list of city indices.
        cities: np.ndarray[int] = np.arange(start=0, stop=number_cities, dtype=int)

        # Iterate adjacency matrix.
        visited_cities: set[int] = set()
        for i in range(1, number_cities):
            visited_cities.add(current_city)

            min_cost: float = 9999.0
            next_city: int | None = None
            for neighbor_city in cities:
                cost: float = instance.get_weight(start=current_city, end=neighbor_city)
                if neighbor_city not in visited_cities and (0.0 < cost < min_cost):
                    next_city = neighbor_city
                    min_cost = cost

            if next_city is None:
                break

            current_city = next_city
            cycle[i] = current_city

        number_attempts_creating_cycle += 1
        if number_attempts_creating_cycle == number_cities:
            # raise Exception('Nenhum ciclo válido foi encontrado!')
            return create_random_cycle(instance=instance, origin_destination=origin_destination)

    return cycle


def create_random_cycle(instance: Problem, origin_destination: int | None = None) -> np.ndarray[int]:
    number_cities: int = instance.dimension

    if origin_destination is None:
        number_attempts_creating_cycle: int = 0
    else:
        number_attempts_creating_cycle: int = -1

    cycle: np.ndarray[int] = np.zeros(shape=number_cities + 1, dtype=int)

    while not is_valid_cycle(instance=instance, cycle=cycle):
        current_city: int = origin_destination

        if number_attempts_creating_cycle >= 0:
            current_city = random.randint(a=0, b=number_cities - 1)

        cycle.fill(current_city)

        # Create a list of city indices.
        cities: np.ndarray[int] = np.arange(start=0, stop=number_cities, dtype=int)
        # Shuffle the list to get a random order.
        np.random.shuffle(x=cities)

        visited_cities: set[int] = set()
        for i in range(1, number_cities):
            visited_cities.add(current_city)

            min_cost: float = 9999.0
            next_city: int | None = None
            for neighbor_city in cities:
                cost: float = instance.get_weight(start=current_city, end=neighbor_city)
                if neighbor_city not in visited_cities and (0.0 < cost < min_cost):
                    next_city = neighbor_city
                    break

            if next_city is None:
                break

            current_city = next_city
            cycle[i] = current_city

        number_attempts_creating_cycle += 1
        if number_attempts_creating_cycle == number_cities:
            # raise Exception('Nenhum ciclo válido foi encontrado!')
            return create_greedy_cycle(instance=instance, origin_destination=origin_destination)

    return cycle


def create_sequential_cycle(instance: Problem, origin_destination: int | None = None) -> np.ndarray[int]:
    number_cities: int = instance.dimension

    if origin_destination is None:
        number_attempts_creating_cycle: int = 0
    else:
        number_attempts_creating_cycle: int = -1

    cycle: np.ndarray[int] = np.zeros(shape=number_cities + 1, dtype=int)

    while not is_valid_cycle(instance=instance, cycle=cycle):
        if number_attempts_creating_cycle >= 0:
            origin_destination = random.randint(a=0, b=number_cities - 1)

        cycle = np.arange(start=0, stop=number_cities, dtype=int)
        cycle = np.delete(arr=cycle, obj=origin_destination)
        cycle = np.insert(arr=cycle, obj=0, values=origin_destination)
        cycle = np.insert(arr=cycle, obj=number_cities, values=origin_destination)

        number_attempts_creating_cycle += 1
        if number_attempts_creating_cycle == number_cities:
            # raise Exception('Nenhum ciclo válido foi encontrado!')
            return create_random_cycle(instance=instance, origin_destination=origin_destination)

    return cycle


def is_valid_cycle(instance: Problem, cycle: np.ndarray[int]) -> bool:
    # Find for invalid edges.
    for i in range(len(cycle) - 1):
        cost: float = instance.get_weight(start=cycle[i], end=cycle[i + 1])
        if (cost == 0.0) or (cost >= 9999.0):
            return False

    # Find for duplicate cities.
    return len(np.unique(cycle[1:])) == len(cycle[1:])
