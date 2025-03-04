import json


def main() -> None:
    with open(file='od_cost_matrix.json', mode='r') as file:
        data = json.load(fp=file)

    for i in range(len(data)):
        data[i]['calculo'][641]['id'] = 'parada_Rua_Nisia_Floresta_Ida0'

    data.insert(5, data.pop(641))

    for i in range(len(data)):
        data[i]['calculo'].insert(5, data[i]['calculo'].pop(641))

    with open(file='od_matrix.json', mode='w') as file:
        json.dump(obj=data, fp=file, indent=2)

    # for origin in data:
    #     header.append(origin['id'])
    #     current_point: list[str | int | float] = [origin['id'], origin['lat'], origin['lon']]
    #     for destination in origin['calculo']:
    #         current_point.append(destination['distance']['value'])
    #     output.append(current_point)

    # with open(file='od_matrix.json', mode='w') as file:
    #     writer = csv.writer(file)
    #     writer.writerow(header)
    #     writer.writerows(output)


if __name__ == "__main__":
    main()
