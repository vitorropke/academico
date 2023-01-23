"""
Implementar as transformações apresentadas na aula:
    — Rotação.\n
    — Translação.\n
    — Escala.\n
    — Reflexão.\n
    — Cisalhamento.

OBS: qualquer formato de imagem ou desenhos feitos em OpenGL, ou “graphicsPaint()”.

Implementar as transformações apresentadas na aula sob a forma de Transformações Compostas:
    — Deve-se permitir o usuário escolher quais operações serão efetuadas na imagem e sua ordem.
"""
import math

import cv2
import numpy as np


def image_transformation(image: np.ndarray[np.uint8], transformation: int,
                         x: (int | bool), y: (int | bool) = 0) -> np.ndarray[np.uint8]:
    """
    Retorna uma imagem após realizar transformações conforme a transformação escolhida e o valor em x e y.
    
    Transformações:
        0 -> Rotação\n
        1 -> Translação\n
        2 -> Escala\n
        3 -> Reflexão\n
        4 -> Cisalhamento
    
    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param transformation: transformação a ser realizada na imagem conforme a lista acima
    :type transformation: int
    :param x: valor da transformação sobre o eixo x ou ângulo caso a transformação seja rotação
    :type x: (int | bool)
    :param y: valor da transformação sobre o eixo y
    :type y: (int | bool)
    :return: imagem do resultado da transformação
    :rtype: np.ndarray[np.uint8]
    """
    affine_matrix: np.ndarray[np.float64] = np.float64([[1, 0, 0],
                                                        [0, 1, 0],
                                                        [0, 0, 1]])
    height: int = image.shape[0]
    width: int = image.shape[1]

    # rotação
    if transformation == 0:
        angle: np.float64 = np.radians(x)

        affine_matrix = np.float64([[math.cos(angle), -math.sin(angle), 0],
                                    [math.sin(angle), math.cos(angle), 0],
                                    [0, 0, 1]])
    # translação
    elif transformation == 1:
        affine_matrix = np.float64([[1, 0, x],
                                    [0, 1, y],
                                    [0, 0, 1]])
    # escala
    elif transformation == 2:
        affine_matrix = np.float64([[x, 0, 0],
                                    [0, y, 0],
                                    [0, 0, 1]])
        width *= x
        height *= y
    # reflexões
    elif transformation == 3:
        # reflexão em torno do eixo x. Cima vai para a baixo e vice-versa
        if x and not y:
            affine_matrix = np.float64([[1, 0, 0],
                                        [0, -1, height],
                                        [0, 0, 1]])
        # reflexão em torno do eixo y. Direita vai para a esquerda e vice-versa
        elif not x and y:
            affine_matrix = np.float64([[-1, 0, width],
                                        [0, 1, 0],
                                        [0, 0, 1]])
        # reflexão em torno dos eixos x e y. Cima vai para a baixo, direita vai para a esquerda e vice-versa
        elif x and y:
            affine_matrix = np.float64([[-1, 0, width],
                                        [0, -1, height],
                                        [0, 0, 1]])
    # cisalhamento
    elif transformation == 4:
        affine_matrix = np.float64([[1, x / height, 0],
                                    [y / width, 1, 0],
                                    [0, 0, 1]])
        width += x
        height += y
    # nenhuma transformação
    else:
        return image

    return cv2.warpPerspective(image, affine_matrix, (width, height))


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/imagem2.jpeg")

    cv2.imshow("Imagem rotacionada", image_transformation(input_image, 0, 45))
    # cv2.imshow("Imagem deslocada", image_transformation(input_image, 1, 100, 100))
    # cv2.imshow("Imagem escalonada", image_transformation(input_image, 2, 2, 2))
    # cv2.imshow("Imagem refletida", image_transformation(input_image, 3, True, True))
    # cv2.imshow("Imagem cisalhada", image_transformation(input_image, 4, 1302, 100))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
