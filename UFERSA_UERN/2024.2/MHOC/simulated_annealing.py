import math

import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

from cycle_operations import *
from tsp_file import calculate_cycle_cost


def plot_visualization(cost_values: list[float], temperature_values: list[float]) -> None:
    fig, ax1 = plt.subplots(figsize=(10, 6))

    # Cost values.
    plot1: Line2D = ax1.plot(cost_values, color='blue', label='Custo')[0]
    ax1.set_xlabel('Iteração')
    ax1.set_ylabel('Custo')

    # Temperature values.
    ax2 = ax1.twinx()
    plot2 = ax2.plot(temperature_values, color='red', label='Temperatura')[0]
    ax2.set_ylabel('Temperatura')

    # Combine legends from both axes.
    plots: list[Line2D] = [plot1, plot2]
    labels = [plot.get_label() for plot in plots]
    plt.legend(plots, labels=labels, loc='best', fontsize='small')

    plt.savefig(fname='sa-plot.pdf', transparent=True, bbox_inches='tight')
    # plt.show()


def swap_cities(cycle: np.ndarray[int]) -> np.ndarray[int]:
    # Get two random cities, except the origin/destination city.
    cities: list[int] = random.sample(population=range(1, len(cycle) - 1), k=2)
    i: int = cities[0]
    j: int = cities[1]
    # Swap the two cities.
    cycle[i], cycle[j] = cycle[j], cycle[i]

    return cycle


def simulated_annealing(instance: Problem, start_temperature: float, final_temperature: float, cooling_rate: float,
                        origin_destination: int | None = None) -> tuple[np.ndarray[int], float]:
    # Create initial cycle.
    current_cycle: np.ndarray[int] = create_greedy_cycle(instance=instance, origin_destination=origin_destination)
    # current_cycle: np.ndarray[int] = create_random_cycle(len(adjacency_matrix), origin_destination)
    # current_cycle: np.ndarray[int] = create_sequential_cycle(len(adjacency_matrix), origin_destination)

    best_cycle: np.ndarray[int] = current_cycle.copy()
    current_cost: float = calculate_cycle_cost(instance=instance, cycle=current_cycle)
    best_cost: float = current_cost

    current_temperature: float = start_temperature
    cost_values: list[float] = []
    temperature_values: list[float] = []
    # graphs: list[Figure] = []
    current_index = 0
    while current_temperature > final_temperature:
        cost_values.append(current_cost)
        temperature_values.append(current_temperature)
        # graphs.append(generate_graph(current_cycle, str(current_index)))

        new_cycle: np.ndarray[int] = current_cycle.copy()
        new_cycle = swap_cities(cycle=new_cycle)
        number_attempts_swap_cities: int = 1
        while not is_valid_cycle(instance=instance, cycle=new_cycle):
            new_cycle = current_cycle.copy()
            # if number_attempts_swap_cities == 100:
            #     raise Exception('Nenhum ciclo válido foi encontrado!')
            new_cycle = swap_cities(cycle=new_cycle)
            number_attempts_swap_cities += 1

        # Update new best values if a lower cost is found.
        new_cost: float = calculate_cycle_cost(instance=instance, cycle=new_cycle)
        if new_cost < best_cost:
            best_cycle = new_cycle.copy()
            best_cost = new_cost

        # Update current values given the conditions.
        delta_cost: float = new_cost - current_cost
        if (delta_cost <= 0) or (math.exp(-delta_cost / current_temperature) > random.random()):
            current_cycle = new_cycle.copy()
            current_cost = new_cost

        # print(f"Iteração {current_index}: Temperatura {current_temperature}: Melhor distância = {best_cost}")
        current_temperature *= cooling_rate
        current_index += 1

    plot_visualization(cost_values, temperature_values)
    # graphs.append(generate_graph(best_cycle, str(current_index)))
    # generate_gif_from_plt(graphs)

    return best_cycle, best_cost
