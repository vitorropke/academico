import numpy as np
import tsplib95
from tsplib95.models import Problem

from genetic_algorithm import genetic_algorithm
from simulated_annealing import simulated_annealing

files: np.ndarray[str] = np.array(
    ['br17.atsp', 'brazil58.tsp', 'ftv35.atsp', 'ftv70.atsp', 'p43.atsp', 'rbg323.atsp', 'rbg403.atsp', 'swiss42.tsp'])
for file in files:
    instance: Problem = tsplib95.load('instancias/' + file)
    print(file)

    start_temperature = 90000.0
    final_temperature = 0.5
    cooling_rate = 0.8
    simulated_annealing_result = simulated_annealing(instance=instance, start_temperature=start_temperature,
                                                     final_temperature=final_temperature, cooling_rate=cooling_rate)
    print(simulated_annealing_result)

    # population_size = 100
    # generations = 500
    # mutation_rate = 0.01
    # genetic_algorithm_result = genetic_algorithm(instance=instance, population_size=population_size,
    #                                              generations=generations, mutation_rate=mutation_rate)
    # print(genetic_algorithm_result)

# best_start_temperature = 0.0
# best_final_temperature = 0.0
# best_cooling_rate = 0.0
# best_simulated_annealing_result_cycle = None
# best_simulated_annealing_result_cost = float('inf')
# for i in range(10000):
#     instance: Problem = tsplib95.load('instancias/' + files[1])
#     start_temperature = random.uniform(100, 100000)
#     final_temperature = random.random()
#     cooling_rate = random.random()
#     simulated_annealing_result = simulated_annealing(instance=instance, start_temperature=start_temperature,
#                                                      final_temperature=final_temperature, cooling_rate=cooling_rate)
#     print(simulated_annealing_result)
#
#     if simulated_annealing_result[1] < best_simulated_annealing_result_cost:
#         best_start_temperature = start_temperature
#         best_final_temperature = final_temperature
#         best_cooling_rate = cooling_rate
#         best_simulated_annealing_result_cycle = simulated_annealing_result[0]
#         best_simulated_annealing_result_cost = simulated_annealing_result[1]
#
# print(best_start_temperature)
# print(best_final_temperature)
# print(best_cooling_rate)
# print(best_simulated_annealing_result_cycle)
# print(best_simulated_annealing_result_cost)

# instance: Problem = tsplib95.load('instancias/' + files[1])
# start_temperature = 90000.0
# final_temperature = 0.5
# cooling_rate = 0.999
# simulated_annealing_result = simulated_annealing(instance=instance, start_temperature=start_temperature,
#                                                  final_temperature=final_temperature, cooling_rate=cooling_rate)
# print(simulated_annealing_result)

# instance: Problem = tsplib95.load('instancias/' + files[1])
# population_size = 100
# generations = 500
# mutation_rate = 0.01
# genetic_algorithm_result = genetic_algorithm(instance=instance, population_size=population_size,
#                                              generations=generations, mutation_rate=mutation_rate)
# print(genetic_algorithm_result)
