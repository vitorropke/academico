import numpy as np
import pandas as pd
from k_means_constrained import KMeansConstrained
from matplotlib import pyplot as plt
from pandas import DataFrame, Series
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster


def perform_clustering(instance: DataFrame) -> pd.Series:
    od_matrix_with_population: DataFrame = instance[instance.index.tolist() + ['population']]

    linkage_matriz: np.ndarray[np.ndarray[np.float64]] = linkage(y=od_matrix_with_population, method='ward')

    # Show dendrogram.
    plt.figure()
    # Complete dendrogram.
    dendrogram(Z=linkage_matriz, color_threshold=0.0)
    # Partial dendrogram.
    # dendrogram(Z=linkage_matriz, p=4, truncate_mode='lastp', color_threshold=0.0)
    # plt.show(block=False)
    # plt.pause(interval=4)

    # Define the clusters.
    # number_of_clusters: int = int(input('Digite o número de clusters desejado: '))
    number_of_clusters = 4
    clusters: np.ndarray[np.int32] = fcluster(Z=linkage_matriz, t=number_of_clusters, criterion='maxclust')

    # - 1 to make clusters start from 0
    return pd.Series(data=(clusters - 1), index=od_matrix_with_population.index)


def calculate_subclusters(instance: DataFrame, minimum_number_of_points_per_subcluster: int,
                          maximum_number_of_points_per_subcluster: int) -> pd.Series:
    number_of_clusters: int = int(np.floor(len(instance.index) / minimum_number_of_points_per_subcluster))
    clusters = KMeansConstrained(n_clusters=number_of_clusters, size_min=minimum_number_of_points_per_subcluster,
                                 size_max=maximum_number_of_points_per_subcluster, random_state=42)
    clusters.fit_predict(X=instance)

    return pd.Series(data=clusters.labels_, index=instance.index)


def perform_subclustering(instance: DataFrame, minimum_number_of_points_per_subcluster: int,
                          maximum_number_of_points_per_subcluster: int) -> pd.Series:
    od_matrix_with_population: DataFrame = instance[instance.index.tolist() + ['population', 'cluster']]

    subclusters: list[Series] = [pd.Series() for _ in range(od_matrix_with_population['cluster'].nunique())]

    for cluster_number, cluster_data in od_matrix_with_population.groupby(by='cluster'):
        subclusters[cluster_number] = calculate_subclusters(
            instance=cluster_data[cluster_data.index.tolist() + ['population']],
            minimum_number_of_points_per_subcluster=minimum_number_of_points_per_subcluster,
            maximum_number_of_points_per_subcluster=maximum_number_of_points_per_subcluster)

    return pd.concat(objs=subclusters)
