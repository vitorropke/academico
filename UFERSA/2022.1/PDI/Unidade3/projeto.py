"""
Sistema para detecção e classificação de doenças em plantas: área da folha destruída.

Classificação de severidade de Oídio em folhas de melão
"""
import glob

import cv2
import numpy as np


def get_green(image: np.ndarray[np.uint8]) -> np.ndarray[np.uint8]:
    """
    Pega a parte verde da imagem
    :param image:
    """
    output = np.zeros((image.shape[0], image.shape[1]), np.uint8)

    for row in range(image.shape[0]):
        for column in range(image.shape[1]):
            if image[row, column, 1] > 100:
                output[row, column] = 255

    print(output)
    """
    image[..., 0] = 0
    image[image[..., 1] > 100, 1] = 255
    image[..., 2] = 0

    lower_green: np.ndarray[np.uint8] = np.uint8([255, 100, 255])
    upper_green: np.ndarray[np.uint8] = np.uint8([255, 255, 255])

    return cv2.inRange(image, lower_green, upper_green)
    return cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    """
    return output


def gray_mask_image(image: np.ndarray[np.uint8]) -> np.ndarray[np.uint8]:
    """
    Mostra somente a cor cinza da imagem, escurecendo o resto.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :return: parte cinza da imagem, com o resto, preto
    :rtype: np.ndarray[np.uint8]
    """
    hsv_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    """
    lower_gray: np.ndarray[np.uint8] = np.uint8([0, 50, 90])
    upper_gray: np.ndarray[np.uint8] = np.uint8([180, 120, 120])
    """
    lower_gray: np.ndarray[np.uint8] = np.uint8([30, 90, 90])
    upper_gray: np.ndarray[np.uint8] = np.uint8([40, 200, 120])

    return cv2.inRange(hsv_image, lower_gray, upper_gray)


def gray_percentage(image: np.ndarray[np.uint8]) -> float:
    """
    Mede a porcentagem de cinza em relação à quantidade de verde e amarelo na folha.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :return: porcentagem de cinza em relação a verde e amarelo
    :rtype: float
    """
    hsv_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    lower_gray: np.ndarray[np.uint8] = np.uint8([30, 90, 90])
    upper_gray: np.ndarray[np.uint8] = np.uint8([40, 200, 120])

    gray_mask: np.ndarray[np.uint8] = cv2.inRange(hsv_image, lower_gray, upper_gray)

    leaf_gray_pixel_count: int = np.count_nonzero(gray_mask)
    leaf_pixel_count: int = np.count_nonzero(gray_image)

    return (leaf_gray_pixel_count / leaf_pixel_count) * 100.0


def illness_level_classification(image: np.ndarray[np.uint8]) -> int:
    """
    Classifica a infecção duma folha baseada na quantidade de doença (píxeis cinza) encontrada nela.

    Nível de infecção:
        0 -> Sem infecção\n
        1 -> Sem infecção visível\n
        2 -> Baixa infecção\n
        3 -> Média infecção\n
        4 -> Alta infecção\n
        5 -> Altíssima infecção

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :return: valor que indica o nível de infecção da folha
    :rtype: int
    """
    illness_level: float = gray_percentage(image)
    print(illness_level)

    # Valores são considerados com margem de erro em caso de falsa detecção
    # Sem infecção
    if illness_level < 3.0:
        return 0
    # Sem infecção visível
    elif illness_level < 10.0:
        return 1
    # Baixa infecção
    elif illness_level < 20.0:
        return 2
    # Média infecção
    elif illness_level < 30.0:
        return 3
    # Alta infecção
    elif illness_level < 40.0:
        return 4
    # Altíssima infecção
    else:
        return 5


"""
position = (100, 100)
font = cv2.FONT_HERSHEY_SIMPLEX
fontScale = 3
color = (0, 50, 255)
thickness = 2

for i, file in enumerate(glob.glob("imagens/Ensaio Fito 2022 - Langdon/*.jpg")):
    input_image: np.ndarray[np.uint8] = cv2.imread(file)
    print(file)

    illness_class: str = str(illness_level_classification(input_image))

    gray_part_image: np.ndarray[np.uint8] = gray_mask_image(input_image)
    labelled_image: np.ndarray[np.uint8] = cv2.putText(input_image, illness_class, position, font, fontScale, color,
                                                       thickness, cv2.LINE_AA)

    cv2.imwrite("imagens/output_mask/ill_" + illness_class + f"_{i}.jpg", gray_part_image)
    cv2.imwrite("imagens/output_image/ill_" + illness_class + f"_{i}.jpg", labelled_image)
"""

input_image: np.ndarray[np.uint8] = cv2.imread("imagens/folhas/folha-5.png")
cv2.imshow("Imagem normal 0", input_image)
cv2.imshow("Máscara cinza 0", gray_mask_image(input_image))

input_image0: np.ndarray[np.uint8] = cv2.imread("imagens/folhas/folha-1.png")
cv2.imshow("Imagem normal 5", input_image0)
cv2.imshow("Máscara cinza 5", gray_mask_image(input_image0))

cv2.imwrite("imagens/folhas/folha-0_mask.png", gray_mask_image(input_image))
cv2.imwrite("imagens/folhas/folha-1_mask.png", gray_mask_image(input_image0))

print(illness_level_classification(input_image))

cv2.waitKey(0)
cv2.destroyAllWindows()
