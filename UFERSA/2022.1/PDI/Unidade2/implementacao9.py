"""
Implementar todos os filtros passa-altas apresentados na aula.
"""
import cv2
import numpy as np


def image_high_pass_filtering(image: np.ndarray[np.uint8], filter_method: int,
                              amplification: float = 0.0) -> np.ndarray[np.uint8]:
    """
    Aplica filtro passa-alta sobre a imagem.

    Filtros:
        0 -> h1\n
        1 -> h2\n
        2 -> M1\n
        3 -> M2\n
        4 -> M3\n
        5 -> High-Boost

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param filter_method: filtro a ser aplicado na imagem de saída
    :type filter_method: int
    :param amplification: fator de amplificação para o High-Boost
    :type amplification: float
    :return: imagem com o filtro passa-alta aplicado
    :rtype: np.ndarray[np.uint8]
    """
    kernel: np.ndarray[np.float64]
    # h1
    if filter_method == 0:
        kernel = np.float64([[0.0, -1.0, 0.0],
                             [-1.0, 4.0, -1.0],
                             [0.0, -1.0, 0.0]])
    # h2
    elif filter_method == 1:
        kernel = np.float64([[-1.0, -1.0, -1.0],
                             [-1.0, 8.0, -1.0],
                             [-1.0, -1.0, -1.0]])
    # M1
    elif filter_method == 2:
        kernel = np.float64([[-1.0, -1.0, -1.0],
                             [-1.0, 9.0, -1.0],
                             [-1.0, -1.0, -1.0]])
    # M2
    elif filter_method == 3:
        kernel = np.float64([[1.0, -2.0, 1.0],
                             [-2.0, 5.0, -2.0],
                             [1.0, -2.0, 1.0]])
    # M3
    elif filter_method == 4:
        kernel = np.float64([[0.0, -1.0, 0.0],
                             [-1.0, 5.0, -1.0],
                             [0.0, -1.0, 0.0]])
    # High-Boost
    elif filter_method == 5:
        w: float = 9.0 * amplification - 1.0

        kernel = np.float64([[-1.0, -1.0, -1.0],
                             [-1.0, w, -1.0],
                             [-1.0, -1.0, -1.0]])

        # kernel /= np.sum(kernel) if np.sum(kernel) != 0 else 1
    # nenhum filtro
    else:
        return image

    return cv2.filter2D(image, -1, kernel)


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")

    cv2.imshow("Imagem com filtro H1", image_high_pass_filtering(input_image, 0))
    cv2.imshow("Imagem com filtro H2", image_high_pass_filtering(input_image, 1))
    cv2.imshow("Imagem com filtro M1", image_high_pass_filtering(input_image, 2))
    cv2.imshow("Imagem com filtro M2", image_high_pass_filtering(input_image, 3))
    cv2.imshow("Imagem com filtro M3", image_high_pass_filtering(input_image, 4))
    cv2.imshow("Imagem com filtro High-Boost", image_high_pass_filtering(input_image, 5, 1.0))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
