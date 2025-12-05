import numpy as np
import pandas as pd
from astropy.constants.iau2015 import R_earth
from pandas import Series, DataFrame
from sklearn.preprocessing import StandardScaler


def calculate_haversine(orig_lat: float, orig_lon: float, dests_lat: Series, dests_lon: Series) -> Series:
    # Degrees to radians.
    orig_lat_rad: float = np.radians(orig_lat)
    orig_lon_rad: float = np.radians(orig_lon)
    dests_lat_rad: Series = np.radians(dests_lat)
    dests_lon_rad: Series = np.radians(dests_lon)

    # Coordinates difference.
    lat_diffs: Series = dests_lat_rad - orig_lat_rad
    lon_diffs: Series = dests_lon_rad - orig_lon_rad

    # Haversine formula.
    haversine_func: Series = np.sin(lat_diffs / 2.0) ** 2.0 + np.cos(orig_lat_rad) * np.cos(dests_lat_rad) * np.sin(
        lon_diffs / 2.0) ** 2.0
    distances: Series = 2.0 * R_earth.value * np.arcsin(np.sqrt(haversine_func))

    return distances


def rm_too_close_points(inst: DataFrame, distance_threshold: int) -> DataFrame:
    print('Removendo pontos muito próximos entre si.')

    points_to_rm: set[str] = set()

    od_matrix: DataFrame = inst.loc[:, inst.index]
    for orig, dests in zip(od_matrix.index, od_matrix.to_numpy()):
        # Skip the origin if it was already set to be removed.
        if orig in points_to_rm:
            continue

        # Add the points that met the threshold condition.
        # By od matrix values.
        points_to_rm.update(od_matrix.columns[(dests > 0) & (dests < distance_threshold)])
        # By beeline distance.
        distances: Series = calculate_haversine(orig_lat=inst.at[orig, 'latitude'].item(),
                                                orig_lon=inst.at[orig, 'longitude'].item(),
                                                dests_lat=inst.loc[:, 'latitude'], dests_lon=inst.loc[:, 'longitude'])
        points_to_rm.update(od_matrix.columns[(distances > 0) & (distances < distance_threshold)])

    return inst.drop(index=points_to_rm, columns=points_to_rm)


def pop_central_point(inst: DataFrame) -> tuple[DataFrame, str]:
    print('Removendo ponto central.')

    # Get central point using the smallest sum.
    od_matrix: DataFrame = inst.loc[:, inst.index]
    central_point_name: str = od_matrix.sum(axis='columns').idxmin()
    # central_point: Series = inst.loc[central_point_name, :]

    return inst.drop(index=central_point_name, columns=central_point_name), central_point_name


def scale_the_data(inst: DataFrame, population_influence_factor: float) -> DataFrame:
    """
    population_influence_factor dictates the influence of population values for clusterization outcome.
    population_influence_factor = 1.0 -> Default influence
    population_influence_factor < 1.0 -> Less influence
    population_influence_factor > 1.0 -> More influence
    :param inst:
    :param population_influence_factor:
    :return:
    """
    print('Dimensionando os dados.')

    # Separate the data.
    od_matrix: DataFrame = inst.loc[:, inst.index]
    population: DataFrame = inst.loc[:, ['population']]

    # Scale.
    od_matrix_scaler: StandardScaler = StandardScaler()
    scaled_od_matrix: np.ndarray[np.ndarray[np.float64]] = od_matrix_scaler.fit_transform(X=od_matrix)
    population_scaler: StandardScaler = StandardScaler()
    scaled_population: np.ndarray[np.ndarray[np.float64]] = population_scaler.fit_transform(X=population)

    # Apply the weight over the population.
    scaled_population *= population_influence_factor

    # Create dataFrame with scaled data.
    scaled_data: np.ndarray[np.ndarray[np.float64]] = np.hstack(tup=(scaled_od_matrix, scaled_population))
    scaled_data_cols: list[str] = od_matrix.columns.tolist() + ['population']

    return pd.DataFrame(data=scaled_data, index=inst.index, columns=scaled_data_cols)
