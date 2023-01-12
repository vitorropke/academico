"""
Implementar a equalização de histograma duma imagem:
    — Apresentar os histogramas e as imagens (original e realçada).

Implementar a correção de gama.
"""
import cv2
import numpy as np
from matplotlib import pyplot as plt


def image_histogram_equalization(image: np.ndarray[np.uint8]) -> plt.Figure:
    """
    Equaliza o histograma da imagem e mostra a comparação da imagem original, equalizada e seus respectivos histogramas.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :return: figura com a imagem original à esquerda com seu histograma abaixo e a imagem equalizada à direita, também
        com seu histograma abaixo
    :rtype: plt.Figure
    """
    gray_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    equalized_histogram_image: np.ndarray[np.uint8] = cv2.equalizeHist(gray_image)

    original_image_histogram: np.ndarray[np.float32] = cv2.calcHist([gray_image], [0], None, [gray_image.shape[0]],
                                                                    [0, 256])
    equalized_histogram: np.ndarray[np.float32] = cv2.calcHist([equalized_histogram_image], [0], None,
                                                               [gray_image.shape[0]], [0, 256])

    output: plt.Figure = plt.figure()

    plt.subplot(221), plt.imshow(gray_image, "gray")
    plt.subplot(222), plt.imshow(equalized_histogram_image, "gray")
    plt.subplot(223), plt.plot(original_image_histogram)
    plt.subplot(224), plt.plot(equalized_histogram)
    plt.xlim([0, 256])

    return output


def image_gamma_correction(image: np.ndarray[np.uint8], gamma: float) -> np.ndarray[np.uint8]:
    """
    Aumenta ou diminui o brilho da imagem utilizando a correção de gama.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param gamma: valor que controla o brilho da imagem na saída
    :type gamma: float
    :return: imagem original à esquerda e imagem com a gama corrigida à direita
    :rtype: np.ndarray[np.uint8]
    """
    if gamma == 0:
        inv_gamma: float = 0.0
    else:
        gamma = abs(gamma)
        inv_gamma: float = 1.0 / gamma

    table: np.ndarray[np.uint8] = np.uint8([(((i / 255.0) ** inv_gamma) * 255.0) for i in np.arange(256)])

    return cv2.LUT(image, table)


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")

    equalized_image_comparison: plt.Figure = image_histogram_equalization(input_image)
    plt.show()

    cv2.imshow("Imagem com gama corrigida", image_gamma_correction(input_image, 2.5))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
