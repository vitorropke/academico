import zipfile
from datetime import datetime, timedelta

from pandas import DataFrame


def calculate_gtfs_time(current_time: datetime) -> str:
    """
    Calculate the time to make it to go past 24:00:00 instead of resetting to 00:00:00. I.e. instead of going from
    23:59:59 to 00:00:00, it will go to 24:00:00 instead, then 24:00:01, then 24:00:02, and so on.

    :param current_time: The time that will be subtracted in relation to 00:00:00.
    :return: Time in 'hh:mm:ss' format.
    """
    time_diff: timedelta = current_time - datetime.strptime('00:00:00', '%H:%M:%S')
    total_seconds: int = int(time_diff.total_seconds())

    hours: int = total_seconds // 3600
    minutes: int = (total_seconds % 3600) // 60
    seconds: int = total_seconds % 60

    return f'{hours:02d}:{minutes:02d}:{seconds:02d}'


def generate_routes_trips_stop_times(inst: DataFrame, route_id: str, agency_id: str, route_short_name: str,
                                     start_time: str, end_time: str, service_id: str, trip_id: str, walk: list[str]) -> \
        tuple[dict[str, str | int], list[dict[str, str]], list[dict[str, str | int]]]:
    # routes.txt
    route: dict[str, str | int] = {'route_id': route_id, 'agency_id': agency_id, 'route_short_name': route_short_name,
                                   'route_type': 3}

    trips: list[dict[str, str]] = []
    stop_times: list[dict[str, str | int]] = []

    current_time: datetime = datetime.strptime(start_time, '%H:%M:%S')
    while current_time < datetime.strptime(end_time, '%H:%M:%S'):
        trip_id_with_time: str = f'{trip_id}_{current_time.strftime(format='%H:%M:%S')}'

        # trips.txt
        trips.append({'route_id': route_id, 'service_id': service_id, 'trip_id': trip_id_with_time})

        # stop_times.txt
        gtfs_time: str = calculate_gtfs_time(current_time=current_time)
        stop_times.append(
            {'trip_id': trip_id_with_time, 'arrival_time': gtfs_time, 'departure_time': gtfs_time, 'stop_id': walk[0],
             'stop_sequence': 1})
        for i, (orig, dest) in enumerate(zip(walk, walk[1:]), start=2):
            # formula t = d / s
            # time (seconds) = distance (meters) / speed (meters per second)
            bus_speed: float = 4.6
            current_time += timedelta(seconds=inst.at[orig, dest] // bus_speed)

            gtfs_time = calculate_gtfs_time(current_time=current_time)
            stop_times.append(
                {'trip_id': trip_id_with_time, 'arrival_time': gtfs_time, 'departure_time': gtfs_time, 'stop_id': dest,
                 'stop_sequence': i})

    return route, trips, stop_times


def generate_gtfs(inst: DataFrame, paths: list[list[str]], cycles: list[list[list[str]]], out_dir: str) -> None:
    agency_id: str = 'teste'

    # agency.txt
    DataFrame(data=[{'agency_id': agency_id, 'agency_name': 'Vitor', 'agency_url': 'https://github.com/vitorropke',
                     'agency_timezone': 'America/Fortaleza', 'agency_phone': '+55 84 9 0000-0000',
                     'agency_email': 'vitorropke@hotmail.com'}]).to_csv(path_or_buf=f'{out_dir}/agency.txt',
                                                                        index=False)

    start_date: str = '20260101'
    end_date: str = '20261231'

    # feed_info.txt
    DataFrame(data=[
        {'feed_publisher_name': 'UERN/UFERSA', 'feed_publisher_url': 'https://ppgcc.ufersa.edu.br/', 'feed_lang': 'por',
         'feed_start_date': start_date, 'feed_end_date': end_date, 'feed_version': '1.0',
         'feed_contact_email': 'vitor.ropke@alunos.ufersa.edu.br',
         'feed_contact_url': 'https://lattes.cnpq.br/4188290890572700'}]).to_csv(path_or_buf=f'{out_dir}/feed_info.txt',
                                                                                 index=False)

    # stops.txt
    inst.loc[:, ['latitude', 'longitude']].rename(
        columns={'latitude': 'stop_lat', 'longitude': 'stop_lon'}).rename_axis(index='stop_id').assign(
        stop_name=inst.index).to_csv(path_or_buf=f'{out_dir}/stops.txt')

    service_id: str = 'dia_util'

    # calendar.txt
    DataFrame(data=[
        {'service_id': service_id, 'monday': 1, 'tuesday': 1, 'wednesday': 1, 'thursday': 1, 'friday': 1, 'saturday': 0,
         'sunday': 0, 'start_date': start_date, 'end_date': end_date}]).to_csv(path_or_buf=f'{out_dir}/calendar.txt',
                                                                               index=False)

    # routes.txt, trips.txt and stop_times.txt
    routes: list[dict[str, str]] = []
    trips: list[dict[str, str]] = []
    stop_times: list[dict[str, str]] = []

    start_time: str = '05:00:00'
    end_time: str = '23:00:00'

    route_id: str
    route_short_name: str
    trip_id: str

    for i, path in enumerate(paths):
        route_id = f'caminho_{i}_a'
        route_short_name = f'Caminho {i} A'
        trip_id = f'{route_id}_viagem'
        path_a: tuple[
            dict[str, str | int], list[dict[str, str]], list[dict[str, str | int]]] = generate_routes_trips_stop_times(
            inst=inst, route_id=route_id, agency_id=agency_id, route_short_name=route_short_name, start_time=start_time,
            end_time=end_time, service_id=service_id, trip_id=trip_id, walk=paths[i])
        routes.append(path_a[0])
        trips += path_a[1]
        stop_times += path_a[2]

        route_id = f'caminho_{i}_b'
        route_short_name = f'Caminho {i} B'
        trip_id = f'{route_id}_viagem'
        path_b: tuple[
            dict[str, str | int], list[dict[str, str]], list[dict[str, str | int]]] = generate_routes_trips_stop_times(
            inst=inst, route_id=route_id, agency_id=agency_id, route_short_name=route_short_name, start_time=start_time,
            end_time=end_time, service_id=service_id, trip_id=trip_id, walk=paths[i][::-1])
        routes.append(path_b[0])
        trips += path_b[1]
        stop_times += path_b[2]

    for i, cluster in enumerate(cycles):
        for j, cycle in enumerate(cluster):
            route_id = f'ciclo_{i}_{j}'
            route_short_name = f'Ciclo {i}.{j}'
            trip_id = f'{route_id}_viagem'

            cycle_a: tuple[dict[str, str | int], list[dict[str, str]], list[
                dict[str, str | int]]] = generate_routes_trips_stop_times(inst=inst, route_id=route_id,
                                                                          agency_id=agency_id,
                                                                          route_short_name=route_short_name,
                                                                          start_time=start_time, end_time=end_time,
                                                                          service_id=service_id, trip_id=trip_id,
                                                                          walk=cycle)
            routes.append(cycle_a[0])
            trips += cycle_a[1]
            stop_times += cycle_a[2]

    DataFrame(routes).to_csv(path_or_buf=f'{out_dir}/routes.txt', index=False)
    DataFrame(trips).to_csv(path_or_buf=f'{out_dir}/trips.txt', index=False)
    DataFrame(stop_times).to_csv(path_or_buf=f'{out_dir}/stop_times.txt', index=False)

    with zipfile.ZipFile(file=f'{out_dir}/gtfs.zip', mode='w') as zip_file:
        zip_file.write(filename=f'{out_dir}/agency.txt', arcname='agency.txt')
        zip_file.write(filename=f'{out_dir}/feed_info.txt', arcname='feed_info.txt')
        zip_file.write(filename=f'{out_dir}/stops.txt', arcname='stops.txt')
        zip_file.write(filename=f'{out_dir}/calendar.txt', arcname='calendar.txt')
        zip_file.write(filename=f'{out_dir}/routes.txt', arcname='routes.txt')
        zip_file.write(filename=f'{out_dir}/trips.txt', arcname='trips.txt')
        zip_file.write(filename=f'{out_dir}/stop_times.txt', arcname='stop_times.txt')
