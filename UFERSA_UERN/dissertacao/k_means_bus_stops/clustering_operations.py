import numpy as np
from k_means_constrained import KMeansConstrained
from kneed import KneeLocator
from matplotlib import pyplot as plt
from pandas import DataFrame, Series
from scipy.cluster.hierarchy import cophenet, dendrogram, fcluster, linkage
from scipy.spatial.distance import cdist, pdist
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler


def calculate_hierarchical_clusters(instance: DataFrame) -> tuple[np.ndarray[np.int32], np.ndarray[np.int64]]:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)
    linkage_matrix: np.ndarray[np.ndarray[np.float64]] = linkage(y=scaled_data, method='ward',
                                                                 optimal_ordering=True)
    cophenetic_correlation_coefficient: np.float64 = cophenet(linkage_matrix, pdist(scaled_data))[0]
    # print(cophenetic_correlation_coefficient)

    plt.figure()

    # dendrogram(Z=linkage_matrix, p=4, truncate_mode='lastp', color_threshold=0.0)
    # plt.xlabel('Número de paradas')
    # plt.ylabel('Distância entre clusters')

    dendrogram(Z=linkage_matrix, color_threshold=0.0)
    ax = plt.gca()
    for label in ax.get_xticklabels():
        label.set_color('white')
    plt.xlabel('Paradas ou clusters')
    plt.ylabel('Distância entre paradas ou clusters')

    plt.savefig(fname='outputs/dendrogram.pdf', transparent=True, bbox_inches='tight')

    # option: int = int(input('Enter the option you want\n'
    #                         '0: I want to enter the distance threshold\n'
    #                         '1: I want to enter the number of clusters\n'))
    option = 1
    clusters: np.ndarray[np.int32]
    if option == 0:
        # distance_threshold: int = int(input('Enter the distance threshold: '))
        distance_threshold = 400
        clusters = fcluster(Z=linkage_matrix, t=distance_threshold, criterion='distance')
    else:
        # number_of_clusters: int = int(input('Enter the number of clusters: '))
        number_of_clusters = 4
        clusters = fcluster(Z=linkage_matrix, t=number_of_clusters, criterion='maxclust')
    # Make the clusters start at 0.
    clusters = clusters - 1
    instance['cluster'] = clusters

    centroids: np.ndarray[np.ndarray[np.float64]] = np.array(
        object=[scaled_data[clusters == i].mean(axis=0) for i in np.unique(ar=clusters)])
    print(centroids)
    exit(0)
    distances_to_centroids: np.ndarray[np.ndarray[np.float64]] = cdist(XA=scaled_data, XB=centroids, metric='euclidean')
    hubs: np.ndarray[np.int64] = np.argmin(a=distances_to_centroids, axis=0)
    instance['hub'] = np.where(instance.index.isin(instance.index[hubs]), 1, 0)

    return clusters, hubs


def calculate_elbow_method(instance: DataFrame) -> int:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)

    maximum_number_of_clusters: int = 10
    cluster_range: range = range(1, maximum_number_of_clusters + 1)
    inertias: list[float] = []
    for i in cluster_range:
        k_means: KMeans = KMeans(n_clusters=i, random_state=42)
        k_means.fit_predict(X=scaled_data)
        inertias.append(k_means.inertia_)

    # Identify the elbow point.
    knee_point: KneeLocator = KneeLocator(x=cluster_range, y=inertias, curve='convex', direction='decreasing')

    # Plot the elbow graph.
    plt.clf()
    knee_point.plot_knee()
    plt.savefig(fname='outputs/inertias.pdf', transparent=True, bbox_inches='tight')

    return knee_point.knee


def calculate_k_means_clusters(instance: DataFrame, number_of_clusters: int) -> tuple[
    np.ndarray[np.int32], np.ndarray[np.int64]]:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)

    k_means: KMeans = KMeans(n_clusters=number_of_clusters, random_state=42)
    k_means.fit_predict(X=scaled_data)

    clusters: np.ndarray[np.int32] = k_means.labels_
    instance['cluster'] = clusters

    # Find the closest point to each centroid.
    centroids: np.ndarray[np.float64] = k_means.cluster_centers_
    distances_to_centroids: np.ndarray[np.ndarray[np.float64]] = cdist(XA=scaled_data, XB=centroids, metric='euclidean')
    hubs: np.ndarray[np.int64] = np.argmin(a=distances_to_centroids, axis=0)
    instance['hub'] = np.where(instance.index.isin(instance.index[hubs]), 1, 0)

    return clusters, hubs


def calculate_sub_cluster(cluster: DataFrame, maximum_number_of_points_per_sub_cluster: int,
                          minimum_number_of_points_per_sub_cluster: int) -> tuple[np.ndarray[np.int32], Series]:
    number_of_sub_clusters = int(np.floor(len(cluster) / minimum_number_of_points_per_sub_cluster))

    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(cluster)

    k_means_constrained = KMeansConstrained(n_clusters=number_of_sub_clusters,
                                            size_min=minimum_number_of_points_per_sub_cluster,
                                            size_max=maximum_number_of_points_per_sub_cluster, random_state=42)
    k_means_constrained.fit_predict(X=scaled_data)

    cluster['sub_cluster'] = k_means_constrained.labels_

    return cluster['sub_cluster'].values, cluster['sub_cluster']


def scale_values(instance: DataFrame) -> np.ndarray[np.ndarray[np.float64]]:
    # return instance.drop(columns=['longitude', 'latitude', 'neighborhood'])
    # return StandardScaler().fit_transform(X=instance[['longitude', 'latitude', 'population']])
    return StandardScaler().fit_transform(
        X=instance.drop(columns=['longitude', 'latitude', 'neighborhood', 'cluster', 'hub', 'sub_cluster'],
                        errors='ignore'))
