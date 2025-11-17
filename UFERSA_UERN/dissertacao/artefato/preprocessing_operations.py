import numpy as np
import pandas as pd
from astropy.constants.iau2015 import R_earth
from pandas import Series, DataFrame
from sklearn.preprocessing import StandardScaler


def calculate_haversine(lat1: float, lon1: float, lat2: Series, lon2: Series) -> Series:
    lat2_copy: Series = lat2.copy()
    lon2_copy: Series = lon2.copy()

    # Degrees to radians.
    lat1 = np.radians(lat1)
    lon1 = np.radians(lon1)
    lat2_copy = np.radians(lat2_copy)
    lon2_copy = np.radians(lon2_copy)

    # Coordinates difference.
    lat_diff: Series = lat2_copy - lat1
    lon_diff: Series = lon2_copy - lon1

    # Haversine formula.
    haversine_func: Series = np.sin(lat_diff / 2.0) ** 2.0 + np.cos(lat1) * np.cos(lat2_copy) * np.sin(
        lon_diff / 2.0) ** 2.0
    distance: Series = 2.0 * R_earth.value * np.arcsin(np.sqrt(haversine_func))

    return distance


def rm_too_close_points(inst: DataFrame, distance_threshold: int) -> DataFrame:
    print('Removendo pontos muito próximos entre si.')

    inst_copy: DataFrame = inst.copy()

    points_to_rm: set[str] = set()

    od_matrix: DataFrame = inst_copy.loc[:, inst_copy.index]
    for orig, row in zip(od_matrix.index, od_matrix.to_numpy()):
        # Skip the origin if it was already set to be removed.
        if orig in points_to_rm:
            continue

        # Add the points that met the threshold condition.
        # By od matrix values.
        points_to_rm.update(od_matrix.columns[(row > 0) & (row < distance_threshold)])
        # By beeline distance.
        distances: Series = calculate_haversine(lat1=inst_copy.at[orig, 'latitude'].item(),
                                                lon1=inst_copy.at[orig, 'longitude'].item(),
                                                lat2=inst_copy.loc[:, 'latitude'], lon2=inst_copy.loc[:, 'longitude'])
        points_to_rm.update(od_matrix.columns[(distances > 0) & (distances < distance_threshold)])

    return inst_copy.drop(index=points_to_rm, columns=points_to_rm)


def pop_central_point(inst: DataFrame) -> tuple[DataFrame, Series]:
    print('Removendo ponto central.')

    inst_copy: DataFrame = inst.copy()

    # Get central point.
    od_matrix: DataFrame = inst_copy.loc[:, inst_copy.index]
    central_point_name: str = od_matrix.sum(axis='columns').idxmin()
    central_point: Series = inst_copy.loc[central_point_name, :]

    # Remove central point.
    inst_copy = inst_copy.drop(index=central_point_name, columns=central_point_name)

    return inst_copy, central_point


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

    inst_copy: DataFrame = inst.copy()

    # Separate the data.
    od_matrix: DataFrame = inst_copy.loc[:, inst_copy.index]
    population: DataFrame = inst_copy.loc[:, ['population']]

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

    return pd.DataFrame(data=scaled_data, index=inst_copy.index, columns=scaled_data_cols)
