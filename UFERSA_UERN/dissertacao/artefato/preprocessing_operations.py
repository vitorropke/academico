import numpy as np
from astropy.constants.iau2015 import R_earth
from pandas import Series, DataFrame
from sklearn.preprocessing import StandardScaler


def calculate_haversine(latitude1: float, longitude1: float, latitude2: Series, longitude2: Series) -> Series:
    # Degrees to radians.
    latitude1 = np.radians(latitude1)
    longitude1 = np.radians(longitude1)
    latitude2 = np.radians(latitude2)
    longitude2 = np.radians(longitude2)

    # Coordinates difference.
    latitude_difference: Series = latitude2 - latitude1
    longitude_difference: Series = longitude2 - longitude1

    # Haversine formula.
    haversine_function: Series = np.sin(latitude_difference / 2.0) ** 2.0 + np.cos(latitude1) * np.cos(
        latitude2) * np.sin(longitude_difference / 2.0) ** 2.0
    distance: Series = 2.0 * R_earth.value * np.arcsin(np.sqrt(haversine_function))

    return distance


def remove_too_close_points(instance: DataFrame, distance_threshold: int) -> DataFrame:
    instance_copy: DataFrame = instance.copy()

    od_matrix: DataFrame = instance_copy[instance_copy.index.tolist()]

    points_to_remove: set[str] = set()
    for origin, row in zip(od_matrix.index, od_matrix.to_numpy()):
        # Skip the origin if it was set to be removed.
        if origin in points_to_remove:
            continue

        # Add the points that met the threshold condition.
        # By od matrix values.
        # Points to be removed are in the columns.
        points_to_remove.update(od_matrix.columns[(row > 0) & (row < distance_threshold)])
        # By beeline distance.
        distances: Series = calculate_haversine(latitude1=instance_copy.at[origin, 'latitude'],
                                                longitude1=instance_copy.at[origin, 'longitude'],
                                                latitude2=instance_copy['latitude'],
                                                longitude2=instance_copy['longitude'])
        # Points to be removed are in the rows.
        points_to_remove.update(od_matrix.index[(distances > 0) & (distances < distance_threshold)])

    return instance_copy.drop(index=list(points_to_remove), columns=list(points_to_remove))


def pop_central_point(instance: DataFrame) -> tuple[str, DataFrame]:
    instance_copy: DataFrame = instance.copy()

    od_matrix: DataFrame = instance_copy[instance_copy.index.tolist()]

    # Get central point.
    central_point_name: str = od_matrix.sum(axis='columns').idxmin()

    # Remove central point.
    instance_copy = instance_copy.drop(index=central_point_name, columns=central_point_name)

    return central_point_name, instance_copy


def scale_the_data(instance: DataFrame, population_influence_factor: float) -> DataFrame:
    """
    population_influence_factor dictates the influence of population values for clusterization outcome.
    population_influence_factor = 1.0 -> Default influence
    population_influence_factor < 1.0 -> Less influence
    population_influence_factor > 1.0 -> More influence
    :param instance:
    :param population_influence_factor:
    :return:
    """
    instance_copy: DataFrame = instance.copy()

    # Separate the data.
    od_matrix: DataFrame = instance_copy[instance_copy.index.tolist()]
    population: DataFrame = instance_copy[['population']]

    # Normalize.
    scaler: StandardScaler = StandardScaler()
    scaled_od_matrix: np.ndarray[np.ndarray[np.float64]] = scaler.fit_transform(X=od_matrix)
    scaled_population: np.ndarray[np.ndarray[np.float64]] = scaler.fit_transform(X=population)

    # Apply the weight over the population.
    scaled_population *= population_influence_factor

    # Save to DataFrame.
    instance_copy[od_matrix.columns] = instance_copy[od_matrix.columns].astype(dtype=np.float64)
    instance_copy[od_matrix.columns] = scaled_od_matrix
    instance_copy['population'] = instance_copy['population'].astype(dtype=np.float64)
    instance_copy['population'] = scaled_population

    return instance_copy
