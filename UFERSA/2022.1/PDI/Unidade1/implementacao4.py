"""
Realizar a pseudo colorização de “Fatiamento por Densidade”: para cada nível (ou níveis) de cinza atribuir uma valor no
espaço de cor.

Realizar a pseudo colorização de “Redistribuição de cores”: as cores duma imagem colorida são redistribuídas para
recolorir a imagem.
"""
import cv2
import numpy as np


def image_pseudo_coloring(image: np.ndarray[np.uint8], colormap: int) -> np.ndarray[np.uint8]:
    """
    Realiza a pseudo colorização de imagens de todos os tipos (preto e branco, escala de cinza e colorida).

    Mapeamento de cores do openCV (valor do parâmetro da função, colormap):
        0 -> COLORMAP_AUTUMN\n
        1 -> COLORMAP_BONE\n
        2 -> COLORMAP_JET\n
        3 -> COLORMAP_WINTER\n
        4 -> COLORMAP_RAINBOW\n
        5 -> COLORMAP_OCEAN\n
        6 -> COLORMAP_SUMMER\n
        7 -> COLORMAP_SPRING\n
        8 -> COLORMAP_COOL\n
        9 -> COLORMAP_HSV\n
        10 -> COLORMAP_PINK\n
        11 -> COLORMAP_HOT\n
        12 -> COLORMAP_PARULA\n
        13 -> COLORMAP_MAGMA\n
        14 -> COLORMAP_INFERNO\n
        15 -> COLORMAP_PLASMA\n
        16 -> COLORMAP_VIRIDIS\n
        17 -> COLORMAP_CIVIDIS\n
        18 -> COLORMAP_TWILIGHT\n
        19 -> COLORMAP_TWILIGHT_SHIFTED\n
        20 -> COLORMAP_TURBO\n
        21 -> COLORMAP_DEEPGREEN

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param colormap: mapeamento de cor a ser utilizado na saída
    :type colormap: int
    :return: imagem pseudo colorizada
    :rtype: np.ndarray[np.uint8]
    """
    # transforma qualquer número para positivo
    colormap = abs(colormap)

    if colormap > 21:
        colormap %= 22

    return cv2.applyColorMap(image, colormap)


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")

    cv2.imshow("Imagem pseudo colorizada", image_pseudo_coloring(input_image, 0))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
