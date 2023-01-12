"""
Escrever um programa que consegue abrir e exibir as imagens nos principais formatos: .jpeg, bitmap, .png, .gif, .tiff e
.pgm.

O programa deve permitir que se realize as operações:
    — Aritméticas: Adição, Subtração, Multiplicação e Divisão.\n
    — Lógicas: AND, OR e XOR.
"""
import cv2
import numpy as np


def image_operation(image1: np.ndarray[np.uint8], image2: np.ndarray[np.uint8],
                    operation: int, normalize: bool) -> np.ndarray[np.uint8]:
    """
    Retorna uma imagem após realizar operações aritméticas ou lógicas entre as imagens 1 e 2, conforme o número
    definido em “operation”.

    Operações:
        0 -> Adição\n
        1 -> Subtração\n
        2 -> Multiplicação\n
        3 -> Divisão\n
        4 -> AND\n
        5 -> OR\n
        6 -> XOR

    :param image1: imagem do openCV
    :type image1: np.ndarray[np.uint8]
    :param image2: imagem do openCV
    :type image2: np.ndarray[np.uint8]
    :param operation: operação a ser realizada entre as duas imagens, conforme a lista acima
    :type operation: int
    :param normalize: flag que indica se o resultado da operação deve ser normalizado ou truncado
    :type normalize: bool
    :return: imagem do resultado da operação entre a imagem 1 e 2
    :rtype: np.ndarray[np.uint8]
    """
    # retorna a imagem do primeiro parâmetro se as dimensões de image1 e image2 forem diferentes
    if image1.shape != image2.shape:
        return image1

    # operações lógicas não precisam ser truncadas, pois, não geram valores menores que 0 e/ou maiores que 255
    # and
    if operation == 4:
        return cv2.bitwise_and(image1, image2)
    # or
    elif operation == 5:
        return cv2.bitwise_or(image1, image2)
    # xor
    elif operation == 6:
        return cv2.bitwise_xor(image1, image2)

    # com a normalização ativada, as operações são feitas com opencv
    if normalize:
        # adição
        if operation == 0:
            return cv2.add(image1, image2)
        # subtração
        elif operation == 1:
            return cv2.subtract(image1, image2)
        # multiplicação
        elif operation == 2:
            return cv2.multiply(image1, image2)
        # divisão
        elif operation == 3:
            return cv2.divide(image1, image2)
    # com a normalização desativada, as operações são feitas com numpy
    else:
        # adição
        if operation == 0:
            return np.add(image1, image2)
        # subtração
        elif operation == 1:
            return np.subtract(image1, image2)
        # multiplicação
        elif operation == 2:
            return np.multiply(image1, image2)
        # divisão
        elif operation == 3:
            # código adicional para tratar divisões com 0
            return np.divide(image1, image2, np.zeros(image1.shape, np.float64), where=(image2 != 0))

    # nenhuma operação
    return image1


if __name__ == "__main__":
    input_image1: np.ndarray[np.uint8] = cv2.imread("imagens/imagem1.jpeg")
    input_image2: np.ndarray[np.uint8] = cv2.imread("imagens/imagem2.jpeg")

    cv2.imshow("Imagem resultante truncada", image_operation(input_image1, input_image2, 3, False))
    cv2.imshow("Imagem resultante normalizada", image_operation(input_image1, input_image2, 3, True))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
