"""
Implementar um conjunto de funcionalidades que permita ao usuário, aplicar as operações apresentadas na aula:
    — Transformações Lineares:
        A) Nesse caso, sendo o intervalo da imagem dado por [F-min, F-max] deve-se fornecer o novo intervalo
            [G-min, G-max] onde o intervalo inicial deve ser mapeado.\n
        B) Escolhe-se da quantidade de partes e depois define o intervalo tal qual no ‘item’ A.\n
        C) Inversa.\n
        D) Binária.

    — Transformações não-Lineares:
        1. Log.
        2. Raiz.
        3. Exponencial.
        4. Quadrado.
"""
import cv2
import numpy as np
from matplotlib import pyplot as plt


def image_histogram_remapping(image: np.ndarray[np.uint8], g_min: np.ndarray[np.uint8],
                              g_max: np.ndarray[np.uint8]) -> np.ndarray[np.uint8]:
    """
    Realiza o remapeamento do histograma da imagem para novos valores máximos e mínimos.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param g_min: intervalo mínimo para remapeamento do histograma
    :type g_min: np.ndarray[np.uint8]
    :param g_max: intervalo máximo para remapeamento do histograma
    :type g_max: np.ndarray[np.uint8]
    :return: imagem com o histograma remapeado
    :rtype: np.ndarray[np.uint8]
    """
    # o vetor com os novos valores devem ser iguais
    if g_min.shape != g_max.shape:
        return image

    remapped_image: np.ndarray[np.uint8] = image.copy()
    for interval in range(g_min.shape[0]):
        f_min: np.uint8 = np.amin(remapped_image)
        f_max: np.uint8 = np.amax(remapped_image)

        remapped_image = np.uint8(
            ((g_max[interval] - g_min[interval]) / (f_max - f_min)) * (remapped_image - f_min) + g_min[interval])

    return remapped_image


def image_gray_scale_transformation(image: np.ndarray[np.uint8], transformation: int) -> np.ndarray[np.uint8]:
    """
    Realiza transformação da escala de cinza da imagem baseado no valor em transformation.

    Transformações:
        0 -> Inversa\n
        1 -> Binária\n
        2 -> Logarítmica\n
        3 -> Raiz quadrada\n
        4 -> Exponencial\n
        5 -> Potência quadrada

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param transformation: transformação a ser realizada na imagem
    :type transformation: int
    :return: imagem transformada a partir duma função
    :rtype: np.ndarray[np.uint8]
    """
    # inversa
    if transformation == 0:
        return cv2.bitwise_not(image)
    # binária
    elif transformation == 1:
        image_copy: np.ndarray[np.uint8] = image.copy()
        image_copy[image < 128] = 0
        image_copy[image >= 128] = 255

        return image_copy
    # logarítmica
    elif transformation == 2:
        a: np.float64 = 255.0 / np.log(1 + np.amax(image))
        return np.uint8(a * np.log(image + 1))
    # raiz quadrada
    elif transformation == 3:
        a: np.float64 = 255.0 / ((1 + np.amax(image)) ** 0.5)
        return np.uint8(a * (image ** 0.5))
    # exponencial
    elif transformation == 4:
        float_image: np.ndarray[np.float64] = np.float64(image)
        a: np.float64 = 255.0 / np.log(1 + np.amax(image))

        return np.uint8(np.exp(float_image) ** (1.0 / a) - 1.0)
    # potência quadrada
    elif transformation == 5:
        a: np.float64 = 255.0 / ((1 + np.amax(image)) ** 2)
        return np.uint8(a * (image ** 2))

    # nenhuma transformação
    return image


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")
    input_image_histogram: np.ndarray[np.float32] = cv2.calcHist([input_image], [0], None, [256], [0, 256])
    """
    remapped_image: np.ndarray[np.uint8] = image_histogram_remapping(input_image, np.uint8([0]), np.uint8([50]))
    remapped_image_histogram: np.ndarray[np.float32] = cv2.calcHist([remapped_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem com histograma remapeado", remapped_image)
    plt.plot(remapped_image_histogram)
    """
    """
    remapped_image_portions: np.ndarray[np.uint8] = image_histogram_remapping(input_image, np.uint8([0, 50, 150]),
                                                                              np.uint8([50, 150, 255]))
    remapped_image_portions_histogram: np.ndarray[np.float32] = cv2.calcHist([remapped_image_portions], [0], None,
                                                                             [256], [0, 256])
    cv2.imshow("Imagem com histograma remapeado por partes", remapped_image_portions)
    plt.plot(remapped_image_portions_histogram)
    """
    """
    reverse_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 0)
    reverse_image_histogram: np.ndarray[np.float32] = cv2.calcHist([reverse_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem inversa", reverse_image)
    plt.plot(reverse_image_histogram)
    """
    """
    binary_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 1)
    binary_image_histogram: np.ndarray[np.float32] = cv2.calcHist([binary_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem binaria", binary_image)
    plt.plot(binary_image_histogram)
    """
    """
    logarithmic_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 2)
    logarithmic_image_histogram: np.ndarray[np.float32] = cv2.calcHist([logarithmic_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem logaritmica", logarithmic_image)
    plt.plot(logarithmic_image_histogram)
    """
    """
    square_root_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 3)
    square_root_image_histogram: np.ndarray[np.float32] = cv2.calcHist([square_root_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem com raiz quadrada", square_root_image)
    plt.plot(square_root_image_histogram)
    """
    """
    exponential_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 4)
    exponential_image_histogram: np.ndarray[np.float32] = cv2.calcHist([exponential_image], [0], None, [256], [0, 256])
    cv2.imshow("Imagem exponencial", exponential_image)
    plt.plot(exponential_image_histogram)
    """
    """
    square_power_image: np.ndarray[np.uint8] = image_gray_scale_transformation(input_image, 5)
    square_power_image_histogram: np.ndarray[np.float32] = cv2.calcHist([square_power_image], [0], None, [256],
                                                                        [0, 256])
    cv2.imshow("Imagem com potencia quadrada", square_power_image)
    plt.plot(square_power_image_histogram)
    """
    plt.plot(input_image_histogram)
    plt.show()
    cv2.waitKey(0)
    cv2.destroyAllWindows()
