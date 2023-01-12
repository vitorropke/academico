"""
Implementar todos os filtros passa-baixas apresentados na aula:
    — Filtros estatísticos e não-estatísticos.\n
    — Filtros com prevenção de bordas.
"""
from PIL import Image
from PIL import ImageFilter
from pykuwahara import kuwahara
import cv2
import numpy as np


def image_low_pass_filtering(image: np.ndarray[np.uint8], filter_method: int,
                             kernel_matrix_size: int = 0) -> np.ndarray[np.uint8]:
    """
    Aplica filtros passa-baixa na imagem.

    Filtros:
        0 -> Média\n
        1 -> Mediana\n
        2 -> Mínima\n
        3 -> Máxima\n
        4 -> Moda\n
        5 -> Kuwahara\n
        6 -> Tomita e Tsuji\n
        7 -> Nagao e Matsuyama\n
        8 -> Somboonkaew

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param filter_method: filtro a ser aplicado na imagem de saída
    :type filter_method: int
    :param kernel_matrix_size: dimensão n × n do ‘kernel_matrix’ do filtro a ser aplicado
    :type kernel_matrix_size: int
    :return: imagem com o filtro passa-baixa aplicado
    :rtype: np.ndarray[np.uint8]
    """
    # média
    if filter_method == 0:
        return cv2.blur(image, (kernel_matrix_size, kernel_matrix_size))
    # mediana
    elif filter_method == 1:
        if (kernel_matrix_size % 2) == 1:
            return cv2.medianBlur(image, kernel_matrix_size)
        else:
            return np.zeros_like(image)
    # mínima ou máxima
    elif (filter_method == 2) or (filter_method == 3):
        kernel_matrix: np.ndarray[np.int32] = np.ones_like((kernel_matrix_size, kernel_matrix_size))

        # mínima
        if filter_method == 2:
            return cv2.erode(image, kernel_matrix)
        # máxima
        else:
            return cv2.dilate(image, kernel_matrix)
    # moda
    elif filter_method == 4:
        pil_image: PIL.Image.Image = Image.fromarray(image)

        return np.uint8(pil_image.filter(ImageFilter.ModeFilter(kernel_matrix_size)))
    # kuwahara
    elif filter_method == 5:
        return kuwahara(image, radius=kernel_matrix_size)
    # Tomita e Tsuji, Nagao e Matsuyama ou Somboonkaew
    else:
        output: np.ndarray[np.uint8] = np.zeros_like(image)

        for row in range(image.shape[0] - 2):
            for column in range(image.shape[1] - 2):
                kernel: (list[np.ndarray[np.uint8]] | list[np.ndarray[np.float64]]) = []
                # valor de preenchimento para máscaras com diferentes números de píxeis
                if len(image.shape) == 3:
                    empty: np.ndarray[np.float64] = np.float64([np.nan, np.nan, np.nan])
                else:
                    empty: float = np.nan

                # Tomita e Tsuji
                if filter_method == 6:
                    # de acordo como foi mostrado nos ‘slides’
                    # (a)
                    kernel.append([image[row - 2, column - 2], image[row - 2, column - 1], image[row - 2, column],
                                   image[row - 1, column - 2], image[row - 1, column - 1], image[row - 1, column],
                                   image[row, column - 2], image[row, column - 1], image[row, column]])
                    # (b)
                    kernel.append([image[row - 2, column], image[row - 2, column + 1], image[row - 2, column + 2],
                                   image[row - 1, column], image[row - 1, column + 1], image[row - 1, column + 2],
                                   image[row, column], image[row, column + 1], image[row, column + 2]])
                    # (c)
                    kernel.append([image[row, column - 2], image[row, column - 1], image[row, column],
                                   image[row + 1, column - 2], image[row + 1, column - 1], image[row + 1, column],
                                   image[row + 2, column - 2], image[row + 2, column - 1], image[row + 2, column]])
                    # (d)
                    kernel.append([image[row, column], image[row, column + 1], image[row, column + 2],
                                   image[row + 1, column], image[row + 1, column + 1], image[row + 1, column + 2],
                                   image[row + 2, column], image[row + 2, column + 1], image[row + 2, column + 2]])
                    # (e)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column], image[row + 1, column + 1]])
                # Nagao e Matsuyama
                elif filter_method == 7:
                    # (a)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column], image[row + 1, column + 1]])
                    # (b)
                    kernel.append([image[row - 2, column - 1], image[row - 2, column], image[row - 2, column + 1],
                                   image[row - 1, column - 1], image[row - 1, column], image[row - 1, column + 1],
                                   empty, image[row, column], empty])
                    # (c)
                    kernel.append([empty, image[row - 1, column + 1], image[row - 1, column + 2],
                                   image[row, column], image[row, column + 1], image[row, column + 2],
                                   empty, image[row + 1, column + 1], image[row + 1, column + 2]])
                    # (d)
                    kernel.append([empty, image[row, column], empty,
                                   image[row + 1, column - 1], image[row + 1, column], image[row + 1, column + 1],
                                   image[row + 2, column - 1], image[row + 2, column], image[row + 2, column + 1]])
                    # (e)
                    kernel.append([image[row - 1, column - 2], image[row - 1, column - 1], empty,
                                   image[row, column - 2], image[row, column - 1], image[row, column],
                                   image[row + 1, column - 2], image[row + 1, column - 1], empty])
                    # (f)
                    kernel.append([image[row - 2, column - 2], image[row - 2, column - 1], empty,
                                   image[row - 1, column - 2], image[row - 1, column - 1], image[row - 1, column],
                                   empty, image[row, column - 1], image[row, column]])
                    # (g)
                    kernel.append([empty, image[row - 2, column + 1], image[row - 2, column + 2],
                                   image[row - 1, column], image[row - 1, column + 1], image[row - 1, column + 2],
                                   image[row, column], image[row, column + 1], empty])
                    # (h)
                    kernel.append([image[row, column], image[row, column + 1], empty,
                                   image[row + 1, column], image[row + 1, column + 1], image[row + 1, column + 2],
                                   empty, image[row + 2, column + 1], image[row + 2, column + 2]])
                    # (i)
                    kernel.append([empty, image[row, column - 1], image[row, column],
                                   image[row + 1, column - 2], image[row + 1, column - 1], image[row + 1, column],
                                   image[row + 2, column - 2], image[row + 2, column - 1], empty])
                # Somboonkaew
                elif filter_method == 8:
                    # (a)
                    kernel.append([image[row - 2, column - 2],
                                   image[row - 1, column - 1], image[row - 1, column + 1],
                                   image[row, column],
                                   image[row + 1, column - 1], image[row + 1, column + 1],
                                   image[row + 2, column + 2]])
                    # (b)
                    kernel.append([image[row - 2, column + 2],
                                   image[row - 1, column - 1], image[row - 1, column + 1],
                                   image[row, column],
                                   image[row + 1, column - 1], image[row + 1, column + 1],
                                   image[row + 2, column - 2]])
                    # (c)
                    kernel.append([image[row - 1, column],
                                   image[row, column - 2], image[row, column - 1], image[row, column],
                                   image[row, column + 1], image[row, column + 2],
                                   image[row + 1, column]])
                    # (d)
                    kernel.append([image[row - 2, column],
                                   image[row - 1, column],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column],
                                   image[row + 2, column]])
                    # (e)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column],
                                   image[row + 1, column - 1], image[row + 1, column], image[row + 1, column + 1]])
                    # (f)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column + 1]])
                    # (g)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column], image[row + 1, column + 1]])
                    # (h)
                    kernel.append([image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column]])
                    # (i)
                    kernel.append([image[row - 1, column],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column], image[row + 1, column + 1]])
                    # (j)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column - 1], image[row + 1, column]])
                    # (k)
                    kernel.append([image[row - 1, column - 1], image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column]])
                    # (l)
                    kernel.append([image[row - 1, column], image[row - 1, column + 1],
                                   image[row, column - 1], image[row, column], image[row, column + 1],
                                   image[row + 1, column], image[row + 1, column + 1]])
                # nenhum filtro
                else:
                    return image

                # lista para numpy
                kernel_numpy: np.ndarray[np.uint8] = np.uint8(kernel)

                # cálculo da variância de cada máscara e a menor variância é escolhida
                variances: np.ndarray[np.float64] = np.nanvar(kernel_numpy, axis=1)
                smallest_variance_index: (np.ndarray[np.int64] | np.int64) = np.argmin(variances, axis=0)

                # se “smallest_variance_index” é uma lista, então pode ser uma imagem RGB ou multi-canais
                if type(smallest_variance_index) == np.ndarray:
                    output[row, column] = [np.nanmean(kernel_numpy[smallest_variance_index[0], :, 0]),
                                           np.nanmean(kernel_numpy[smallest_variance_index[1], :, 1]),
                                           np.nanmean(kernel_numpy[smallest_variance_index[2], :, 2])]
                # se “smallest_variance_index” é um número inteiro, então pode ser uma imagem em escala de cinza
                else:
                    output[row, column] = np.nanmean(kernel_numpy[smallest_variance_index])

        return output


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")

    cv2.imshow("Imagem com filtro de média", image_low_pass_filtering(input_image, 0, 3))
    cv2.imshow("Imagem com filtro de mediana", image_low_pass_filtering(input_image, 1, 3))
    cv2.imshow("Imagem com filtro de mínima", image_low_pass_filtering(input_image, 2, 3))
    cv2.imshow("Imagem com filtro de máxima", image_low_pass_filtering(input_image, 3, 3))
    cv2.imshow("Imagem com filtro de moda", image_low_pass_filtering(input_image, 4, 3))
    cv2.imshow("Imagem com filtro do Kuwahara", image_low_pass_filtering(input_image, 5, 3))
    cv2.imshow("Imagem com filtro do Tomita e Tsuji", image_low_pass_filtering(input_image, 6))
    cv2.imshow("Imagem com filtro do Nagao e Matsuyama", image_low_pass_filtering(input_image, 7))
    cv2.imshow("Imagem com filtro do Somboonkaew", image_low_pass_filtering(input_image, 8))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
