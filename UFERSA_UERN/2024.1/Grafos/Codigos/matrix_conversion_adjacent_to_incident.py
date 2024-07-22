def adjacent_to_incident(matrix):
    number_of_ones = sum(row.count(1) for row in matrix)
    number_of_nodes = len(matrix)
    result = [[0 for _ in range(number_of_ones)] for _ in range(number_of_nodes)]
    arc = -1
    for line in range(number_of_nodes):
        for column in range(number_of_nodes):
            if matrix[line][column] == 1:
                arc += 1

                for k in range(number_of_nodes):
                    result[k][arc] = 0

                result[line][arc] = 1
                result[column][arc] = -1

    return result


adjacent_matrix = [[0, 1, 0], [1, 1, 1], [1, 1, 1]]
incident_matrix = adjacent_to_incident(adjacent_matrix)
print(incident_matrix)
