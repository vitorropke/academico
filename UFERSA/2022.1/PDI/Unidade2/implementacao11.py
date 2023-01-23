"""
Implementar as técnicas de detecção de pontos, linhas e bordas apresentados na aula.

Implementar as técnicas de Limiarização Global e Local.

Implementar a segmentação por crescimento de região:
    — Proximidade de valor escalar.\n
    — Watershed.

OBS.: implementação de técnicas para detecção de junção valerá 1,5 pontos extra!
"""
import math

import cv2
import numpy as np


def image_point_detection(image: np.ndarray[np.uint8], threshold: int) -> np.ndarray[np.uint8]:
    """
    Detecta os pontos da imagem baseado num limiar.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param threshold: limiar de sensibilidade para detecção dos pontos
    :type threshold: int
    :return: imagem com os pontos acima do limiar
    :rtype: np.ndarray[np.uint8]
    """
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    output: np.ndarray[np.uint8] = np.zeros_like(gray_image)
    kernel: np.ndarray[np.float64] = np.float64([[-1.0, -1.0, -1.0],
                                                 [-1.0, 8.0, -1.0],
                                                 [-1.0, -1.0, -1.0]])

    filtered_image = cv2.filter2D(gray_image, -1, kernel)
    output[filtered_image > threshold] = 255

    return output


def image_line_detection(image: np.ndarray[np.uint8], direction: int) -> np.ndarray[np.uint8]:
    """
    Detecta as linhas da imagem numa direção definida.

    Direções:
        0 -> Horizontal\n
        1 -> Diagonal (45º)\n
        2 -> Vertical\n
        3 -> Diagonal (135º)

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param direction: direção das linhas a serem detectadas
    :type direction: int
    :return: imagem mostrando as linhas na direção definida
    :rtype: np.ndarray[np.uint8]
    """
    kernel: np.ndarray[np.float64]

    # horizontal
    if direction == 0:
        kernel = np.float64([[-1.0, -1.0, -1.0],
                             [2.0, 2.0, 2.0],
                             [-1.0, -1.0, -1.0]])
    # diagonal (45º)
    elif direction == 1:
        kernel = np.float64([[-1.0, -1.0, 2.0],
                             [-1.0, 2.0, -1.0],
                             [2.0, -1.0, -1.0]])
    # vertical
    elif direction == 2:
        kernel = np.float64([[-1.0, 2.0, -1.0],
                             [-1.0, 2.0, -1.0],
                             [-1.0, 2.0, -1.0]])
    # diagonal (135º)
    elif direction == 3:
        kernel = np.float64([[2.0, -1.0, -1.0],
                             [-1.0, 2.0, -1.0],
                             [-1.0, -1.0, 2.0]])
    # nenhuma direção
    else:
        return image

    return cv2.filter2D(image, -1, kernel)


def image_edge_detection(image: np.ndarray[np.uint8], operator: int) -> np.ndarray[np.uint8]:
    """
    Detecta as bordas duma imagem de acordo com o operador escolhido.

    Operadores:
        0 -> Roberts\n
        1 -> Roberts cruzado\n
        2 -> Prewitt Gx\n
        3 -> Prewitt Gy\n
        4 -> Prewitt magnitude\n
        5 -> Sobel Gx\n
        6 -> Sobel Gy\n
        7 -> Sobel magnitude\n
        8 -> Kirsch\n
        9 -> Robinson\n
        10 -> Frey-Chen\n
        11 -> Laplaciano H1\n
        12 -> Laplaciano H2

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param operator: operador usado para detectar a borda
    :type operator: int
    :return: imagem mostrando as bordas
    :rtype: np.ndarray[np.uint8]
    """
    # Roberts e Prewitt
    if (operator >= 0) and (operator <= 4):
        kernel_x: np.ndarray[np.float64]
        kernel_y: np.ndarray[np.float64]
        # Roberts
        if operator == 0:
            kernel_x = np.float64([[1.0, 0.0],
                                   [-1.0, 0.0]])
            kernel_y = np.float64([[1.0, -1.0],
                                   [0.0, 0.0]])
        # Roberts cruzado
        elif operator == 1:
            kernel_x = np.float64([[1.0, 0.0],
                                   [0.0, -1.0]])
            kernel_y = np.float64([[0.0, 1.0],
                                   [-1.0, 0.0]])
        # Prewitt
        else:
            # Prewitt Gx
            kernel_x = np.float64([[-1.0, 0.0, 1.0],
                                   [-1.0, 0.0, 1.0],
                                   [-1.0, 0.0, 1.0]])
            # Prewitt Gy
            kernel_y = np.float64([[-1.0, -1.0, -1.0],
                                   [0.0, 0.0, 0.0],
                                   [1.0, 1.0, 1.0]])
            # Prewitt Gx
            if operator == 2:
                return cv2.filter2D(image, -1, kernel_x)
            # Prewitt Gy
            elif operator == 3:
                return cv2.filter2D(image, -1, kernel_y)

        filtered_image_x: np.ndarray[np.uint8] = cv2.filter2D(image, -1, kernel_x)
        filtered_image_y: np.ndarray[np.uint8] = cv2.filter2D(image, -1, kernel_y)

        # Roberts (os dois) ou Prewitt magnitude
        # retorne "cv2.addWeighted(filtered_image_x, 0.5, filtered_image_y, 0.5, 0)" para bordas mais finas
        # ou
        # cv2.add(filtered_image_x, filtered_image_y) para bordas mais grossas.
        # return cv2.addWeighted(filtered_image_x, 0.5, filtered_image_y, 0.5, 0)
        return cv2.add(filtered_image_x, filtered_image_y)
    # Sobel Gx
    elif operator == 5:
        return cv2.Sobel(image, cv2.CV_8U, 1, 0, ksize=3)
    # Sobel Gy
    elif operator == 6:
        return cv2.Sobel(image, cv2.CV_8U, 0, 1, ksize=3)
    # Sobel magnitude
    elif operator == 7:
        return cv2.Sobel(image, cv2.CV_8U, 1, 1, ksize=3)
    # Kirsch e Robinson
    elif (operator == 8) or (operator == 9):
        kernel: np.ndarray[np.float64]
        # Kirsch
        if operator == 8:
            kernel = np.float64([[5.0, -3.0, -3.0],
                                 [5.0, 0.0, -3.0],
                                 [5.0, -3.0, -3.0]])
        # Robinson
        else:
            kernel = np.float64([[1.0, 0.0, -1.0],
                                 [2.0, 0.0, -2.0],
                                 [1.0, 0.0, -1.0]])

        kernel_list: list[np.ndarray[np.float64]] = []
        # gira a máscara 8 vezes em torno do centro
        for x in range(8):
            kernel_list.append(kernel)
            kernel = np.float64([[kernel[0, 1], kernel[0, 2], kernel[1, 2]],
                                 [kernel[0, 0], kernel[1, 1], kernel[2, 2]],
                                 [kernel[1, 0], kernel[2, 0], kernel[2, 1]]])

        filtered_image_list: list[np.ndarray[np.uint8]] = []
        for x in range(8):
            filtered_image_list.append(cv2.filter2D(image, -1, kernel_list[x]))

        return np.amax(filtered_image_list, axis=0)
    # Frey-Chen
    elif operator == 10:
        sqrt_2: float = 2.0 ** 0.5
        kernel: np.ndarray[np.float64] = np.float64([[[1.0, sqrt_2, 1.0],
                                                      [0.0, 0.0, 0.0],
                                                      [-1.0, -sqrt_2, -1.0]],
                                                     [[1.0, 0.0, -1.0],
                                                      [sqrt_2, 0.0, -sqrt_2],
                                                      [1.0, 0.0, -1.0]],
                                                     [[0.0, -1.0, sqrt_2],
                                                      [1.0, 0.0, -1.0],
                                                      [-sqrt_2, 1.0, 0.0]],
                                                     [[sqrt_2, -1.0, 0.0],
                                                      [-1.0, 0.0, 1.0],
                                                      [0.0, 1.0, -sqrt_2]],
                                                     [[0.0, 1.0, 0.0],
                                                      [-1.0, 0.0, -1.0],
                                                      [0.0, 1.0, 0.0]],
                                                     [[-1.0, 0.0, 1.0],
                                                      [0.0, 0.0, 0.0],
                                                      [1.0, 0.0, -1.0]],
                                                     [[1.0, -2.0, 1.0],
                                                      [-2.0, 4.0, -2.0],
                                                      [1.0, -2.0, 1.0]],
                                                     [[-2.0, 1.0, -2.0],
                                                      [1.0, 4.0, 1.0],
                                                      [-2.0, 1.0, -2.0]],
                                                     [[1.0, 1.0, 1.0],
                                                      [1.0, 1.0, 1.0],
                                                      [1.0, 1.0, 1.0]]])

        filtered_image_list: list[np.ndarray[np.uint8]] = []
        for x in range(9):
            filtered_image_list.append(cv2.filter2D(image, -1, kernel[x]))

        output: np.ndarray[np.uint8] = np.zeros_like(image)
        for x in range(9):
            # output = cv2.add(filtered_image_list[x], output)
            output = cv2.addWeighted(filtered_image_list[x], 0.5, output, 0.5, 0)

        return output
    # Laplacian
    elif (operator == 11) or (operator == 12):
        kernel: np.ndarray[np.float64]
        # Laplaciano H1
        if operator == 11:
            kernel = np.float64([[0.0, -1.0, 0.0],
                                 [-1.0, 4.0, -1.0],
                                 [0.0, -1.0, 0.0]])
        # Laplaciano H2
        else:
            kernel = np.float64([[-1.0, -4.0, -1.0],
                                 [-4.0, 20.0, -4.0],
                                 [-1.0, -4.0, -1.0]])

        return cv2.filter2D(image, -1, kernel)

    # nenhum operador
    return image


def image_global_thresholding(image: np.ndarray[np.uint8], threshold: int) -> np.ndarray[np.uint8]:
    """
    Realiza a limiarização global da imagem.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param threshold: limite que define quais a faixa de píxeis que serão modificados. Todos os píxeis abaixo do
        "threshold" serão 0 e todos acima serão 255
    :type threshold: int
    :return: imagem preta e branca
    :rtype: np.ndarray[np.uint8]
    """
    return cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)[1]


def image_local_thresholding(image: np.ndarray[np.uint8], technic: int,
                             block_size: int, constant: float) -> np.ndarray[np.uint8]:
    """
    Realiza a limiarização local da imagem, segundo a técnica selecionada.

    Técnicas:
        0 -> Média\n
        1 -> Máximo\n
        2 -> Mínimo\n
        3 -> Niblack

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param technic: técnica usada para limiarização local
    :type technic: int
    :param block_size: tamanho da janela de vizinhança
    :type block_size: int
    :param constant: constante subtraída da média, mínima ou máxima dos píxeis de vizinhança
    :type constant: float
    :return: imagem preta e branca
    :rtype: np.ndarray[np.uint8]
    """
    # tamanho do bloco deve ser um número ímpar. Se for par, retorna a imagem original
    if block_size % 2 == 0:
        return image

    gray_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # média
    if technic == 0:
        return cv2.adaptiveThreshold(gray_image, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, block_size,
                                     constant)
    # outras técnicas
    output: np.ndarray[np.uint8] = np.zeros_like(gray_image)
    for row in range(gray_image.shape[0]):
        for column in range(gray_image.shape[1]):
            local_pixels_list: list[np.ndarray[np.uint8]] = []

            for neighbour_x in range((-block_size // 2) + 1, (block_size // 2) + 1):
                for neighbour_y in range((-block_size // 2) + 1, (block_size // 2) + 1):
                    try:
                        local_pixels_list.append(gray_image[row + neighbour_x, column + neighbour_y])
                    except IndexError:
                        local_pixels_list.append(np.nan)

            local_pixels_numpy: np.ndarray[np.float64] = np.float64(local_pixels_list)
            threshold: np.float64
            # máximo
            if technic == 1:
                threshold = np.nanmax(local_pixels_numpy) + constant * np.nanstd(local_pixels_numpy)
            # mínimo
            elif technic == 2:
                threshold = np.nanmin(local_pixels_numpy) + constant * np.nanstd(local_pixels_numpy)
            # Niblack
            elif technic == 3:
                threshold = np.nanmean(local_pixels_numpy) + constant * np.nanstd(local_pixels_numpy)
            # nenhuma técnica
            else:
                return image

            if gray_image[row, column] > threshold:
                output[row, column] = 255
            else:
                output[row, column] = 0

    return output


def image_region_growing_segmentation(image: np.ndarray[np.uint8], tolerance: int) -> np.ndarray[np.uint8]:
    """
    Realiza a segmentação de regiões usando crescimento de região.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param tolerance: intervalo que cada região cobre. Ex: valor 10 significa que cada região possui 10 píxeis
    :type tolerance: int
    :return: imagem com os limites das regiões marcados em vermelho
    :rtype: np.ndarray[np.uint8]
    """
    if tolerance == 0:
        return image

    gray_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    pseudo_colorized_regions: np.ndarray[np.uint8] = np.zeros((image.shape[0], image.shape[1], 3), np.uint8)

    maximum_region_number: int = math.ceil(256 / tolerance)

    for row in range(gray_image.shape[0]):
        for column in range(gray_image.shape[1]):
            # equação encontrada por tentativa e erro
            # ex: se a tolerância for 100, serão 3 regiões
            # a primeira de 0 a 99
            # segunda de 100 a 199
            # terceira de 200 a 255
            # a seguinte fórmula encontra a região conforme o valor do píxel
            region: int = int(gray_image[row, column] / tolerance % maximum_region_number)

            integer_color: int = 0
            # o valor "16 777 216" são o número de cores possíveis para uma tela RGB
            if region != 0:
                integer_color = 16777215 // region

            red: int = integer_color & 255
            green: int = (integer_color >> 8) & 255
            blue: int = (integer_color >> 16) & 255

            pseudo_colorized_regions[row, column] = [blue, green, red]

    return pseudo_colorized_regions


def image_watershed_segmentation(image: np.ndarray[np.uint8]) -> np.ndarray[np.uint8]:
    """
    Realiza a segmentação de regiões usando watershed.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :return: imagem com os limites das regiões marcados em vermelho
    :rtype: np.ndarray[np.uint8]
    """
    gray_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    thresholded_image: np.ndarray[np.uint8] = cv2.threshold(gray_image, 0, 255, cv2.THRESH_BINARY_INV +
                                                            cv2.THRESH_OTSU)[1]

    # remoção de ruído
    kernel: np.ndarray[np.uint8] = np.ones((3, 3), np.uint8)
    opening: np.ndarray[np.uint8] = cv2.morphologyEx(thresholded_image, cv2.MORPH_OPEN, kernel, iterations=2)

    # encontrando o plano de fundo
    background: np.ndarray[np.uint8] = cv2.dilate(opening, kernel, iterations=3)

    # encontrando o primeiro plano
    distance_transform: np.ndarray[np.float32] = cv2.distanceTransform(opening, cv2.DIST_L2, 5)
    foreground_float: np.ndarray[np.float32] = cv2.threshold(distance_transform, 0.7 * distance_transform.max(), 255,
                                                             0)[1]

    # encontrando regiões desconhecidas
    foreground_int: np.ndarray[np.uint8] = np.uint8(foreground_float)
    unknown: np.ndarray[np.uint8] = cv2.subtract(background, foreground_int)

    # define as regiões
    markers: np.ndarray[np.intc] = cv2.connectedComponents(foreground_int)[1]

    # define background como região 1
    markers += 1

    # define área desconhecida como região 0
    markers[unknown == 255] = 0

    image_copy: np.ndarray[np.uint8] = image.copy()
    markers = cv2.watershed(image_copy, markers)
    image_copy[markers == -1] = [0, 0, 255]

    return image_copy


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")
    """
    cv2.imshow("Imagem com deteccao de pontos", image_point_detection(input_image, 150))
    """
    """
    cv2.imshow("Imagem com deteccao de retas horizontais", image_line_detection(input_image, 0))
    cv2.imshow("Imagem com deteccao de retas diagonais (45º)", image_line_detection(input_image, 1))
    cv2.imshow("Imagem com deteccao de retas verticais", image_line_detection(input_image, 2))
    cv2.imshow("Imagem com deteccao de retas diagonais (135º)", image_line_detection(input_image, 3))
    """
    """
    cv2.imshow("Imagem com deteccao de bordas (Roberts)", image_edge_detection(input_image, 0))
    cv2.imshow("Imagem com deteccao de bordas (Roberts cruzado)", image_edge_detection(input_image, 1))
    cv2.imshow("Imagem com deteccao de bordas (Prewitt Gx)", image_edge_detection(input_image, 2))
    cv2.imshow("Imagem com deteccao de bordas (Prewitt Gy)", image_edge_detection(input_image, 3))
    cv2.imshow("Imagem com deteccao de bordas (Prewitt magnitude)", image_edge_detection(input_image, 4))
    
    cv2.imshow("Imagem com deteccao de bordas (Sobel Gx)", image_edge_detection(input_image, 5))
    cv2.imshow("Imagem com deteccao de bordas (Sobel Gy)", image_edge_detection(input_image, 6))
    cv2.imshow("Imagem com deteccao de bordas (Sobel magnitude)", image_edge_detection(input_image, 7))
    
    cv2.imshow("Imagem com deteccao de bordas (Kirsch)", image_edge_detection(input_image, 8))
    cv2.imshow("Imagem com deteccao de bordas (Robinson)", image_edge_detection(input_image, 9))
    
    cv2.imshow("Imagem com deteccao de bordas (Frei-Chen)", image_edge_detection(input_image, 10))
    
    cv2.imshow("Imagem com deteccao de bordas (Laplaciano H1)", image_edge_detection(input_image, 11))
    cv2.imshow("Imagem com deteccao de bordas (Laplaciano H2)", image_edge_detection(input_image, 12))
    """
    """
    cv2.imshow("Imagem com limiarizacao global", image_global_thresholding(input_image, 150))
    
    cv2.imshow("Imagem com limiarizacao local (media)", image_local_thresholding(input_image, 0, 21, 0.1))
    cv2.imshow("Imagem com limiarizacao local (maxima)", image_local_thresholding(input_image, 1, 21, 0.1))
    cv2.imshow("Imagem com limiarizacao local (minima)", image_local_thresholding(input_image, 2, 21, 0.1))
    cv2.imshow("Imagem com limiarizacao local (Niblack)", image_local_thresholding(input_image, 3, 21, 0.1))
    """
    """
    cv2.imshow("Imagem segmentada com crescimento de regiao", image_region_growing_segmentation(input_image, 128))
    
    cv2.imshow("Imagem segmentada com watershed", image_watershed_segmentation(input_image))
    """
    cv2.waitKey(0)
    cv2.destroyAllWindows()
