def solution1(numbers):
    vector_size = len(numbers)
    max_sum = 0
    sequence_start = 0
    sequence_end = 0
    loops = 0

    for i in range(vector_size):
        for j in range(i, vector_size):
            this_sum = 0

            for k in range(i, j + 1):
                this_sum += numbers[k]

                loops += 1

            if this_sum > max_sum:
                max_sum = this_sum
                sequence_start = i
                sequence_end = j

    return max_sum, sequence_start, sequence_end, loops


def solution2(numbers):
    vector_size = len(numbers)
    max_sum = 0
    sequence_start = 0
    sequence_end = 0
    loops = 0

    for i in range(vector_size):
        this_sum = 0
        for j in range(i, vector_size):
            this_sum += numbers[j]

            loops += 1

            if this_sum > max_sum:
                max_sum = this_sum
                sequence_start = i
                sequence_end = j

    return max_sum, sequence_start, sequence_end, loops


def solution3(numbers):
    this_sum = 0
    max_sum = 0
    sequence_start = 0
    sequence_end = 0
    loops = 0

    i = 0
    for j in range(len(numbers)):
        this_sum += numbers[j]

        loops += 1

        if this_sum > max_sum:
            max_sum = this_sum
            sequence_start = i
            sequence_end = j
        elif this_sum < 0:
            i = j + 1
            this_sum = 0

    return max_sum, sequence_start, sequence_end, loops


with open("valores.txt", 'r') as file:
    data_read = file.read()

    # detect the used separator of the numbers in the file
    possible_separators = [' ', '\t', ',', ';', ':']
    detected_separator = None
    for separator in possible_separators:
        if separator in data_read:
            detected_separator = separator

    numbers_input_string = data_read.split(detected_separator)
    numbers_input_int = [int(number) for number in numbers_input_string]

    # print(solution1(numbers_input_int))
    # print(solution2(numbers_input_int))
    print(solution3(numbers_input_int))
