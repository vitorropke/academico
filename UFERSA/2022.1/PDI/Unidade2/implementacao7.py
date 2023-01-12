"""
Implementar a técnica de fatiamento de bits:
    — Apresentar os planos de bits duma imagem. Ex.: para 8 bits, serão 8 planos e consequentemente 8 imagens.
"""
import cv2
import numpy as np


def image_bit_plane_slicing(image: np.ndarray[np.uint8], planes_number: int) -> np.ndarray[np.uint8]:
    """
    Fatia a imagem em bits e mostra várias imagens, cada uma com seu bit.

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param planes_number: número fatias que devem ser feitas e, consequentemente, o número de imagens na saída
    :type planes_number: int
    :return: número “n” de imagens definido em “planes_number”. Cada uma com seus respectivos bits
    :rtype: np.ndarray[np.uint8]
    """
    planes_list: list[np.ndarray[np.uint8]] = []
    current_pixel: int = 0
    for plane in range(planes_number):
        number: int = 0
        bit_1_per_plane_number: int = 8 // planes_number

        for bit in range(bit_1_per_plane_number):
            number += 2 ** current_pixel
            current_pixel += 1

        planes_list.append(np.bitwise_and(image, np.full_like(image, number)) * 255)

    return planes_list


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/lena.pgm")

    for x in range(2):
        cv2.imshow(f"Imagem com 2 bits fatiados (bit {x + 1})", image_bit_plane_slicing(input_image, 2)[x])

    for x in range(4):
        cv2.imshow(f"Imagem com 4 bits fatiados (bit {x + 1})", image_bit_plane_slicing(input_image, 4)[x])

    for x in range(8):
        cv2.imshow(f"Imagem com 8 bits fatiados (bit {x + 1})", image_bit_plane_slicing(input_image, 8)[x])

    cv2.waitKey(0)
    cv2.destroyAllWindows()
