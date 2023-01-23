"""
Implementar as técnicas de halftoning apresentados na aula.
"""
import cv2
import numpy as np


def image_ordered_dithering(image: np.ndarray[np.uint8], technic: int) -> np.ndarray[np.uint8]:
    """
    Aplica as técnicas de pontilhado ordenado do halftoning (meio-tom) na imagem.

    Técnicas:
        0 -> Matriz 2x2\n
        1 -> Matriz 2x3\n
        2 -> Matriz 3x3

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param technic: técnica de pontilhado ordenado a ser aplicado na imagem
    :type technic: int
    :return: imagem com halftoning usando técnica de pontilhado ordenado
    :rtype: np.ndarray[np.uint8]
    """
    gray_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    dither_matrix: np.ndarray[np.uint8]
    dither_matrix_row_count: int
    dither_matrix_column_count: int

    # matriz 2x2
    if technic == 0:
        dither_matrix_row_count = 2
        dither_matrix_column_count = 2

        dither_matrix = np.uint8([[0, 128],
                                  [192, 64]])
    # matrix 2x3
    elif technic == 1:
        dither_matrix_row_count = 2
        dither_matrix_column_count = 3

        dither_matrix = np.uint8([[128, 0, 171],
                                  [213, 85, 43]])
    # matrix 3x3
    elif technic == 2:
        dither_matrix_row_count = 3
        dither_matrix_column_count = 3

        dither_matrix = np.uint8([[171, 228, 114],
                                  [28, 0, 85],
                                  [142, 57, 199]])
    # nenhuma técnica
    else:
        return image

    for row in range(gray_image.shape[0]):
        i: int = row % dither_matrix_row_count
        for column in range(gray_image.shape[1]):
            j: int = column % dither_matrix_column_count

            if gray_image[row, column] <= dither_matrix[i][j]:
                gray_image[row, column] = 0
            else:
                gray_image[row, column] = 255

    return gray_image


def image_error_diffusion_dithering(image: np.ndarray[np.uint8], technic: int) -> np.ndarray[np.uint8]:
    """
    Aplica as técnicas de pontilhado com difusão de erro do halftoning (meio-tom) na imagem.

    Técnicas:
        0 -> Floyd e Steinberg\n
        1 -> Rogers\n
        2 -> Jarvis, Judice & Ninke\n
        3 -> Stucki\n
        4 -> Stevenson e Arce

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param technic: técnica de pontilhado com difusão de erro a ser aplicado na imagem
    :type technic: int
    :return: imagem com halftoning usando técnica de pontilhado com difusão de erro
    :rtype: np.ndarray[np.uint8]
    """
    gray_image: np.ndarray[np.float64] = np.float64(cv2.cvtColor(image, cv2.COLOR_BGR2GRAY))
    output: np.ndarray[np.uint8] = np.zeros(gray_image.shape, np.uint8)

    row_limit: int = 0
    column_limit: int = 0

    # Floyd e Steinberg ou Rogers
    if (technic == 0) or (technic == 1):
        row_limit = gray_image.shape[0] - 1
        column_limit = gray_image.shape[1] - 1
    # Jarvis, Judice & Ninke ou Stucki
    elif (technic == 2) or (technic == 3):
        row_limit = gray_image.shape[0] - 2
        column_limit = gray_image.shape[1] - 2
    # Stevenson e Arce
    elif technic == 4:
        row_limit = gray_image.shape[0] - 3
        column_limit = gray_image.shape[1] - 3

    for row in range(row_limit):
        for column in range(column_limit):
            if gray_image[row, column] >= 128:
                output[row, column] = 255

            error: np.ndarray[np.float64] = gray_image[row, column] - output[row, column]

            # Floyd e Steinberg
            if technic == 0:
                gray_image[row, column + 1] += (7.0 / 16.0) * error

                gray_image[row + 1, column - 1] += (3.0 / 16.0) * error
                gray_image[row + 1, column] += (5.0 / 16.0) * error
                gray_image[row + 1, column + 1] += (1.0 / 16.0) * error
            # Rogers
            elif technic == 1:
                gray_image[row, column + 1] += (3.0 / 8.0) * error

                gray_image[row + 1, column] += (3.0 / 8.0) * error
                gray_image[row + 1, column + 1] += (2.0 / 8.0) * error
            # Jarvis, Judice & Ninke ou Stucki
            elif (technic == 2) or (technic == 3):
                constants: np.ndarray[np.float64]
                # Jarvis, Judice & Ninke
                if technic == 2:
                    constants = np.float64([(1.0 / 48.0), (3.0 / 48.0), (5.0 / 48.0), (7.0 / 48.0)])
                # Stucki
                else:
                    constants = np.float64([(1.0 / 42.0), (2.0 / 42.0), (4.0 / 42.0), (8.0 / 42.0)])

                gray_image[row, column + 1] += constants[3] * error
                gray_image[row, column + 2] += constants[2] * error

                gray_image[row + 1, column - 2] += constants[1] * error
                gray_image[row + 1, column - 1] += constants[2] * error
                gray_image[row + 1, column] += constants[3] * error
                gray_image[row + 1, column + 1] += constants[2] * error
                gray_image[row + 1, column + 2] += constants[1] * error

                gray_image[row + 2, column - 2] += constants[0] * error
                gray_image[row + 2, column - 1] += constants[1] * error
                gray_image[row + 2, column] += constants[2] * error
                gray_image[row + 2, column + 1] += constants[1] * error
                gray_image[row + 2, column + 2] += constants[0] * error
            # Stevenson e Arce
            elif technic == 4:
                gray_image[row, column + 2] += (32.0 / 200.0) * error

                gray_image[row + 1, column - 3] += (12.0 / 200.0) * error
                gray_image[row + 1, column - 1] += (26.0 / 200.0) * error
                gray_image[row + 1, column + 1] += (30.0 / 200.0) * error
                gray_image[row + 1, column + 3] += (16.0 / 200.0) * error

                gray_image[row + 2, column - 2] += (12.0 / 200.0) * error
                gray_image[row + 2, column] += (26.0 / 200.0) * error
                gray_image[row + 2, column + 2] += (12.0 / 200.0) * error

                gray_image[row + 3, column - 3] += (5.0 / 200.0) * error
                gray_image[row + 3, column - 1] += (12.0 / 200.0) * error
                gray_image[row + 3, column + 1] += (12.0 / 200.0) * error
                gray_image[row + 3, column + 3] += (5.0 / 200.0) * error
            # nenhuma técnica
            else:
                return image

    return output


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena_cor.jpg")

    cv2.imshow("Imagem com pontilhado ordenado (2x2)", image_ordered_dithering(input_image, 0))
    # cv2.imshow("Imagem com pontilhado ordenado (2x3)", image_ordered_dithering(input_image, 1))
    # cv2.imshow("Imagem com pontilhado ordenado (3x3)", image_ordered_dithering(input_image, 2))
    """
    cv2.imshow("Imagem com pontilhado com difusao de erro (Floyd e Steinberg)",
               image_error_diffusion_dithering(input_image, 0))
    """
    # cv2.imshow("Imagem com pontilhado com difusao de erro (Rogers)", image_error_diffusion_dithering(input_image, 1))
    """
    cv2.imshow("Imagem com pontilhado com difusao de erro (Jarvis, Judice & Ninke)",
               image_error_diffusion_dithering(input_image, 2))
    """
    # cv2.imshow("Imagem com pontilhado com difusao de erro (Stucki)", image_error_diffusion_dithering(input_image, 3))
    """
    cv2.imshow("Imagem com pontilhado com difusao de erro (Stevenson e Arce)",
               image_error_diffusion_dithering(input_image, 4))
    """
    cv2.waitKey(0)
    cv2.destroyAllWindows()
