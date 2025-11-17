import numpy as np
import pandas as pd
from k_means_constrained import KMeansConstrained
from matplotlib import pyplot as plt
from pandas import DataFrame, Series
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster


def perform_clustering(inst: DataFrame) -> pd.Series:
    print('Fazendo a clusterização.')

    od_matrix_with_population: DataFrame = inst.loc[:, inst.index.tolist() + ['population']]

    linkage_matrix: np.ndarray[np.ndarray[np.float64]] = linkage(y=od_matrix_with_population, method='ward')

    # Show dendrogram.
    plt.figure()
    # Complete dendrogram.
    dendrogram(Z=linkage_matrix, color_threshold=0.0)
    # Partial dendrogram.
    # dendrogram(Z=linkage_matrix, p=4, truncate_mode='lastp', color_threshold=0.0)
    # plt.show(block=False)
    # plt.pause(interval=4)

    # Define the clusters.
    # num_clusters: int = int(input('Digite o número de clusters desejado: '))
    num_clusters: int = 4
    clusters: np.ndarray[np.int32] = fcluster(Z=linkage_matrix, t=num_clusters, criterion='maxclust')

    # - 1 to make clusters start from 0.
    return pd.Series(data=(clusters - 1), index=od_matrix_with_population.index)


def calculate_subclusters(inst: DataFrame, min_num_points_per_subcluster: int,
                          max_num_points_per_subcluster: int) -> pd.Series:
    num_subclusters: int = int(np.floor(len(inst.index) / min_num_points_per_subcluster))
    subclusters: KMeansConstrained = KMeansConstrained(n_clusters=num_subclusters,
                                                       size_min=min_num_points_per_subcluster,
                                                       size_max=max_num_points_per_subcluster, random_state=42)
    subclusters.fit_predict(X=inst)

    return pd.Series(data=subclusters.labels_, index=inst.index)


def perform_subclustering(inst: DataFrame, min_num_points_per_subcluster: int,
                          max_num_points_per_subcluster: int) -> pd.Series:
    print('Fazendo a sub-clusterização.')
    od_matrix_with_population_and_cluster: DataFrame = inst.loc[:, inst.index.tolist() + ['population', 'cluster']]

    subclusters: list[Series] = [pd.Series() for _ in
                                 range(od_matrix_with_population_and_cluster.loc[:, 'cluster'].nunique())]

    for cluster_num, cluster_data in od_matrix_with_population_and_cluster.groupby(by='cluster'):
        subclusters[cluster_num] = calculate_subclusters(
            inst=cluster_data.loc[:, cluster_data.index.tolist() + ['population']],
            min_num_points_per_subcluster=min_num_points_per_subcluster,
            max_num_points_per_subcluster=max_num_points_per_subcluster)

    return pd.concat(objs=subclusters)
