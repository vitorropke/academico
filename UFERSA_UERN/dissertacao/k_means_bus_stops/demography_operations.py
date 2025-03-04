import pandas as pd
from geopy import Location
from geopy.geocoders import Nominatim
from pandas import DataFrame


def get_neighborhoods_and_population(coordinates: DataFrame, population: DataFrame):
    geolocator = Nominatim(user_agent='geo_lookup')

    neighborhoods: list[str] = [''] * coordinates.shape[0]
    for i, point in enumerate(coordinates.itertuples()):
        address: Location = geolocator.reverse(query=(point.latitude, point.longitude), timeout=100)
        neighborhoods[i] = address.raw.get('address', {}).get('suburb', 'no')

        # Rename some neighborhoods.
        if neighborhoods[i] == 'Bairro Costa e Silva':
            neighborhoods[i] = 'Presidente Costa e Silva'
        elif neighborhoods[i] == 'Planalto 13 de Maio':
            neighborhoods[i] = 'Planalto Treze de Maio'
        elif neighborhoods[i] == 'Santa Júlia':
            neighborhoods[i] = 'Santa Delmira'

        print(i, neighborhoods[i])

    coordinates['neighborhood'] = neighborhoods
    coordinates['population'] = coordinates['neighborhood'].map(population['V01006']).fillna(0).astype(int)


def main():
    population: DataFrame = pd.read_csv(filepath_or_buffer='inputs/demografia_por_bairros.csv', sep=';',
                                        index_col='NM_BAIRRO', usecols=['NM_BAIRRO', 'V01006'], skiprows=range(1, 3468),
                                        nrows=27, encoding='latin1')
    distances: DataFrame = pd.read_csv(filepath_or_buffer='inputs/od_matrix.csv', index_col='point')

    get_neighborhoods_and_population(distances, population)
    distances.to_csv(path_or_buf='inputs/od_matrix_with_population.csv')


if __name__ == '__main__':
    main()
