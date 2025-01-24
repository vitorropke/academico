from matplotlib import pyplot as plt
from matplotlib.lines import Line2D

from cycle_operations import *

random.seed(42)

import numpy as np

from tsp_file import calculate_cycle_cost


def calculate_fitness(instance: Problem, cycle: np.ndarray[int]) -> float:
    return 1.0 / calculate_cycle_cost(instance=instance, cycle=cycle)  # Inverse for fitness (higher is better)


def initialize_population(instance: Problem, population_size: int, origin_destination: int | None = None) -> np.ndarray[
    np.ndarray[int]]:
    number_cities: int = instance.dimension

    cycle_population: np.ndarray[np.ndarray[int]] = np.zeros(shape=(population_size, number_cities + 1), dtype=int)

    for i in range(population_size):
        # Check if the new individual is already in the population.
        new_individual: np.ndarray[int] = create_random_or_greedy_cycle(instance=instance,
                                                                   origin_destination=origin_destination)
        while any(np.array_equal(new_individual, cycle) for cycle in cycle_population):
            new_individual = create_random_or_greedy_cycle(instance=instance, origin_destination=origin_destination)
        cycle_population[i] = new_individual
        print('Indivíduo', i, 'criado')

    return cycle_population


def create_random_or_greedy_cycle(instance: Problem, origin_destination: int | None = None) -> np.ndarray[int]:
    # 50% to create a random cycle and 50% to create a greedy cycle.
    if random.randint(a=0, b=99) < 50:
        return create_random_cycle(instance=instance, origin_destination=origin_destination)
    else:
        return create_greedy_cycle(instance=instance, origin_destination=origin_destination)


def tournament_selection(instance: Problem, population: np.ndarray[np.ndarray[int]], fitnesses: np.ndarray[float],
                         k: int = 3) -> np.ndarray[int]:
    selected: np.ndarray[np.ndarray[int]] = random.choices(population=population, weights=fitnesses, k=k)
    return max(selected, key=lambda individual: calculate_fitness(instance=instance, cycle=individual))


def crossover(instance: Problem, parent1: np.ndarray[int], parent2: np.ndarray[int]) -> np.ndarray[int]:
    child: np.ndarray[int] = do_crossover(parent1=parent1, parent2=parent2)
    number_attempts_crossovers: int = 1
    while not is_valid_cycle(instance=instance, cycle=child):
        # if number_attempts_crossovers == 100:
        #     raise Exception('Nenhum ciclo válido foi encontrado!')
        child = do_crossover(parent1=parent1, parent2=parent2)
        number_attempts_crossovers += 1

    return child


def do_crossover(parent1: np.ndarray[int], parent2: np.ndarray[int]) -> np.ndarray[int]:
    parent_size: int = len(parent1)

    # Select two random cities.
    cities: list[int] = sorted(random.sample(population=range(1, parent_size - 1), k=2))
    start: int = cities[0]
    end: int = cities[1]
    # Initialize the child with invalid values (-1).
    child: np.ndarray[int] = np.full(shape=parent_size, fill_value=-1, dtype=int)
    # Copy the segment of parent1.
    child[start:end] = parent1[start:end].copy()

    # Fill the gaps with the cities of parent2.
    position: int = 0
    for city in parent2:
        # Check if the city is already in the child.
        if city not in child:
            # Find the next available position.
            while child[position] != -1:
                position += 1
            # Add the city in the available position.
            child[position] = city
    child[parent_size - 1] = child[0]

    return child


def mutate(instance: Problem, cycle: np.ndarray[int], mutation_rate: float) -> np.ndarray[int]:
    new_cycle = cycle.copy()

    if random.random() < mutation_rate:
        new_cycle = swap_cities(cycle=new_cycle)
        number_attempts_swap_cities: int = 1
        while not is_valid_cycle(instance=instance, cycle=new_cycle):
            new_cycle = cycle.copy()
            # if number_attempts_swap_cities == 100:
            #     raise Exception('Nenhum ciclo válido foi encontrado!')
            new_cycle = swap_cities(cycle=new_cycle)
            number_attempts_swap_cities += 1

    return new_cycle


def swap_cities(cycle: np.ndarray[int]) -> np.ndarray[int]:
    # Get random two sequential cities, except the origin/destination city.
    cities: list[int] = random.sample(population=range(1, len(cycle) - 1), k=2)
    i: int = cities[0]
    j: int = cities[1]
    # Swap the two cities.
    cycle[i], cycle[j] = cycle[j], cycle[i]

    return cycle


def plot_visualization(cost_values: list[float]) -> None:
    plt.plot(cost_values)

    plt.xlabel('Gerações')
    plt.ylabel('Custo')

    plt.savefig(fname='ga-plot.pdf', transparent=True, bbox_inches='tight')


def genetic_algorithm(instance: Problem, population_size: int, generations: int, mutation_rate: float,
                      origin_destination: int | None = None) -> tuple[np.ndarray[int], float]:
    number_cities: int = instance.dimension

    population: np.ndarray[np.ndarray[int]] = initialize_population(instance=instance, population_size=population_size,
                                                                    origin_destination=origin_destination)

    fitnesses: np.ndarray[float] = np.zeros(shape=population_size, dtype=float)
    for i, individual in enumerate(population):
        fitnesses[i] = calculate_fitness(instance=instance, cycle=individual)

    # Set the initial solution.
    best_index: int = np.argmax(a=fitnesses)
    best_cycle: np.ndarray[int] = population[best_index].copy()
    best_cost: float = float(1.0 / fitnesses[best_index])

    cost_values: list[float] = [best_cost]
    for generation in range(generations):
        new_population: np.ndarray[np.ndarray[int]] = np.zeros(shape=(population_size, number_cities + 1), dtype=int)
        # Make the genetic operations.
        for i in range(population_size):
            parent1: np.ndarray[int] = tournament_selection(instance=instance, population=population,
                                                            fitnesses=fitnesses)
            parent2: np.ndarray[int] = tournament_selection(instance=instance, population=population,
                                                            fitnesses=fitnesses)
            child: np.ndarray[int] = crossover(instance=instance, parent1=parent1, parent2=parent2)
            child: np.ndarray[int] = mutate(instance=instance, cycle=child, mutation_rate=mutation_rate)
            new_population[i] = child
        population = new_population.copy()

        # Calculate new solutions.
        for i, individual in enumerate(population):
            fitnesses[i] = calculate_fitness(instance=instance, cycle=individual)

        # Track the best solution.
        best_index = np.argmax(a=fitnesses)
        current_cost: float = float(1.0 / fitnesses[best_index])
        cost_values.append(current_cost)
        if current_cost < best_cost:
            best_cycle = population[best_index].copy()
            best_cost = current_cost

        print(f"Geração {generation}: Melhor custo = {best_cost}")

    plot_visualization(cost_values)

    return best_cycle, best_cost
