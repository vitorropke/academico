import csv
import json


def main() -> None:
    with open(file='inputs/od_cost_matrix.json', mode='r') as file:
        data = json.load(fp=file)

    header: list[str] = ['point', 'latitude', 'longitude']
    output: list[list[str | int]] = []

    for origin in data:
        header.append(origin['id'])
        current_point: list[str | int | float] = [origin['id'], origin['lat'], origin['lon']]
        for destination in origin['calculo']:
            current_point.append(destination['distance']['value'])
        output.append(current_point)

    with open(file='inputs/od_matrix.csv', mode='w') as file:
        writer = csv.writer(file)
        writer.writerow(header)
        writer.writerows(output)


if __name__ == '__main__':
    main()
