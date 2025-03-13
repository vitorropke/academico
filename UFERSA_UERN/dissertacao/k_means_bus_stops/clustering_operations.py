import numpy as np
import pandas as pd
from kneed import KneeLocator
from matplotlib import pyplot as plt
from pandas import DataFrame
from scipy.cluster.hierarchy import cophenet, dendrogram, fcluster, linkage
from scipy.spatial.distance import cdist, pdist
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

from colors_operations import get_n_colors


def calculate_hierarchical_clusters(instance: DataFrame) -> tuple[np.ndarray[np.int32], np.ndarray[np.int64]]:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)
    linkage_matrix: np.ndarray[np.ndarray[np.float64]] = linkage(y=scaled_data, method='ward',
                                                                 optimal_ordering=True)
    cophenetic_correlation_coefficient: np.float64 = cophenet(linkage_matrix, pdist(scaled_data))[0]
    print(cophenetic_correlation_coefficient)

    clusters: np.ndarray[np.int32] = fcluster(Z=linkage_matrix, t=250, criterion='distance')
    # The following code generates 't' clusters.
    # clusters: np.ndarray[np.int32] = fcluster(Z=linkage_matrix, t=4, criterion='maxclust')
    instance['cluster'] = clusters

    centroids: np.ndarray[np.ndarray[np.float64]] = np.array(
        object=[scaled_data[clusters == i].mean(axis=0) for i in np.unique(ar=clusters)])
    distances_to_centroids: np.ndarray[np.ndarray[np.float64]] = cdist(XA=scaled_data, XB=centroids, metric='euclidean')
    hubs: np.ndarray[np.int64] = np.argmin(a=distances_to_centroids, axis=0)
    instance['hub'] = np.where(instance.index.isin(instance.index[hubs]), 1, 0)

    plt.figure()
    dendrogram(Z=linkage_matrix, p=4, truncate_mode='lastp', color_threshold=(0.5 * linkage_matrix[-1:, 2]),
               leaf_font_size=10, leaf_rotation=45)
    plt.savefig(fname='outputs/dendrogram.pdf', transparent=True, bbox_inches='tight')

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
    centroids: np.ndarray[np.float64] = k_means.cluster_centers_
    clusters: np.ndarray[np.int32] = k_means.labels_
    instance['cluster'] = clusters

    # Find the closest point to each centroid.
    distances_to_centroids: np.ndarray[np.ndarray[np.float64]] = cdist(XA=scaled_data, XB=centroids,
                                                                       metric='euclidean')
    hubs: np.ndarray[np.int64] = np.argmin(a=distances_to_centroids, axis=0)
    instance['hub'] = np.where(instance.index.isin(instance.index[hubs]), 1, 0)

    # Plot the graph.
    plt.clf()
    colors: list[str] = get_n_colors(number_of_colors=len(instance['cluster'].unique()))
    for i in range(number_of_clusters):
        current_cluster_data: pd.Index(str | int) = instance.index[np.where(clusters == i)[0]]
        current_hub_data: str | int = instance.index[hubs[i]]
        plt.scatter(x=instance.loc[current_cluster_data, 'longitude'], y=instance.loc[current_cluster_data, 'latitude'],
                    c=colors[i], label=f'Cluster {i}')
        plt.scatter(x=instance.loc[current_hub_data, 'longitude'], y=instance.loc[current_hub_data, 'latitude'], s=150,
                    c=colors[i], marker='x', label=f'Hub {i}')
    plt.savefig(fname='outputs/clusters.pdf', transparent=True, bbox_inches='tight')

    return clusters, hubs


def scale_values(instance: DataFrame) -> np.ndarray[np.ndarray[np.float64]]:
    # return instance.drop(columns=['longitude', 'latitude', 'neighborhood'])
    # return StandardScaler().fit_transform(X=instance[['longitude', 'latitude', 'population']])
    return StandardScaler().fit_transform(
        X=instance.drop(columns=['longitude', 'latitude', 'neighborhood']))
