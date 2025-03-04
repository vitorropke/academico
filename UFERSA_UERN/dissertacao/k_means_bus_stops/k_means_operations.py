import numpy as np
import pandas as pd
import plotly.figure_factory as ff
from kneed import KneeLocator
from matplotlib import pyplot as plt
from pandas import DataFrame
from plotly.graph_objs import Figure
from scipy.cluster import hierarchy
from scipy.spatial.distance import cdist
from sklearn.cluster import KMeans
from sklearn.manifold import MDS
from sklearn.preprocessing import StandardScaler

from colors_operations import get_n_colors


def generate_coordinates(instance: DataFrame) -> None:
    if not {'longitude', 'latitude'}.issubset(instance.columns):
        mds: MDS = MDS(random_state=42, dissimilarity='precomputed')
        coordinates: np.ndarray[np.float64] = mds.fit_transform(X=instance)

        instance[['longitude', 'latitude']] = coordinates

        plt.clf()
        plt.scatter(x=coordinates[:, 0], y=coordinates[:, 1])
        for i, (x, y) in enumerate(coordinates):
            plt.text(x=x, y=y, s=f'Loc {i}')
        plt.savefig(fname='outputs/map.pdf', transparent=True, bbox_inches='tight')


def calculate_dendrogram(instance: DataFrame):
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)
    linkage_matrix: np.ndarray[np.ndarray[np.float64]] = hierarchy.linkage(y=scaled_data, method='single')
    plt.figure()
    hierarchy.dendrogram(linkage_matrix)
    plt.savefig(fname='outputs/dendrogram.pdf', transparent=True, bbox_inches='tight')

    figure: Figure = ff.create_dendrogram(X=scaled_data)
    figure.write_image(file='outputs/dendrogram0.pdf')
    exit(0)



def calculate_elbow_method(instance: DataFrame) -> int:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)

    maximum_number_of_clusters: int = 10
    clusters: range = range(1, maximum_number_of_clusters + 1)
    inertias: list[float] = []
    for i in clusters:
        k_means: KMeans = KMeans(n_clusters=i, random_state=42)
        k_means.fit_predict(X=scaled_data)
        inertias.append(k_means.inertia_)

    # Identify the elbow point.
    knee_point: KneeLocator = KneeLocator(x=clusters, y=inertias, curve='convex', direction='decreasing')

    # Plot the elbow graph.
    plt.clf()
    knee_point.plot_knee()
    plt.savefig(fname='outputs/inertias.pdf', transparent=True, bbox_inches='tight')

    return knee_point.knee


def calculate_k_means(instance: DataFrame, number_of_clusters: int) -> tuple[
    np.ndarray[np.int32], np.ndarray[np.int64]]:
    scaled_data: np.ndarray[np.ndarray[np.float64]] = scale_values(instance)

    k_means: KMeans = KMeans(n_clusters=number_of_clusters, random_state=42)
    k_means.fit_predict(X=scaled_data)
    centroids: np.ndarray[np.float64] = k_means.cluster_centers_
    labels: np.ndarray[np.int32] = k_means.labels_
    instance['cluster'] = labels

    # Find the closest point to each centroid.
    distances_to_centroids: np.ndarray[np.ndarray[np.float64]] = cdist(XA=scaled_data, XB=centroids,
                                                                       metric='euclidean')
    hubs: np.ndarray[np.int64] = np.argmin(a=distances_to_centroids, axis=0)
    instance['hub'] = np.where(instance.index.isin(instance.index[hubs]), 1, 0)

    # Plot the graph.
    plt.clf()
    colors: list[str] = get_n_colors(number_of_colors=len(instance['cluster'].unique()))
    for i in range(number_of_clusters):
        current_cluster_data: pd.Index(str | int) = instance.index[np.where(labels == i)[0]]
        current_hub_data: str | int = instance.index[hubs[i]]
        plt.scatter(x=instance.loc[current_cluster_data, 'longitude'], y=instance.loc[current_cluster_data, 'latitude'],
                    c=colors[i], label=f'Cluster {i}')
        plt.scatter(x=instance.loc[current_hub_data, 'longitude'], y=instance.loc[current_hub_data, 'latitude'], s=150,
                    c=colors[i], marker='x', label=f'Hub {i}')
    plt.savefig(fname='outputs/clusters.pdf', transparent=True, bbox_inches='tight')

    return labels, hubs


def scale_values(instance: DataFrame) -> np.ndarray[np.ndarray[np.float64]]:
    # return instance.drop(columns=['longitude', 'latitude', 'neighborhood'])
    # return StandardScaler().fit_transform(X=instance[['longitude', 'latitude', 'population']])
    return StandardScaler().fit_transform(
        X=instance.drop(columns=['longitude', 'latitude', 'neighborhood']))
