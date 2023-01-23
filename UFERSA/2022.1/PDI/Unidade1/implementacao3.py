"""
Abrir uma imagem colorida e apresentar suas componentes do espaço de cor.

Realizar a conversão entre os seguintes espaços de cores e também apresentar suas componentes:
    — RGB para HSV.\n
    — RGB para YUV.\n
    — RGB para CMYK.
"""
import cv2
import numpy as np


def image_color_splitting(image: np.ndarray[np.uint8], output_color_space: int) -> np.ndarray[np.uint8]:
    """
    Separa as componentes de cores da imagem segundo o espaço de cor definido em “output_color_space”.

    Espaço de cores da saída:
        0 -> RGB\n
        1 -> HSV\n
        1 -> YUV\n
        2 -> CMYK

    :param image: imagem do openCV
    :type image: np.ndarray[np.uint8]
    :param output_color_space: espaço de cor de saída conforme a lista acima
    :type output_color_space: int
    :return: imagem com os componentes da imagem
    :rtype: np.ndarray[np.uint8]
    """
    zeros: np.ndarray[np.uint8] = np.zeros(image.shape[:2], np.uint8)

    # rgb
    if output_color_space == 0:
        b: np.ndarray[np.uint8]
        g: np.ndarray[np.uint8]
        r: np.ndarray[np.uint8]

        b, g, r = cv2.split(image)

        red: np.ndarray[np.uint8] = cv2.merge([zeros, zeros, r])
        green: np.ndarray[np.uint8] = cv2.merge([zeros, g, zeros])
        blue: np.ndarray[np.uint8] = cv2.merge([b, zeros, zeros])

        return np.uint8([red, green, blue])
    # hsv
    elif output_color_space == 1:
        hsv_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

        h: np.ndarray[np.uint8]
        s: np.ndarray[np.uint8]
        v: np.ndarray[np.uint8]

        h, s, v = cv2.split(hsv_image)

        return np.uint8([h, s, v])
    # yuv
    elif output_color_space == 2:
        yuv_image: np.ndarray[np.uint8] = cv2.cvtColor(image, cv2.COLOR_BGR2YUV)

        y: np.ndarray[np.uint8]
        u: np.ndarray[np.uint8]
        v: np.ndarray[np.uint8]

        y, u, v = cv2.split(yuv_image)

        return np.uint8([y, u, v])
    # cmyk
    elif output_color_space == 3:
        bgr_dash: np.ndarray[np.float64] = np.float64(image / 255.0)

        k: np.ndarray[np.float64] = 1.0 - np.max(bgr_dash, 2)
        c: np.ndarray[np.uint8] = np.uint8(((1.0 - bgr_dash[..., 2] - k) / (1.0 - k)) * 255.0)
        m: np.ndarray[np.uint8] = np.uint8(((1.0 - bgr_dash[..., 1] - k) / (1.0 - k)) * 255.0)
        y: np.ndarray[np.uint8] = np.uint8(((1.0 - bgr_dash[..., 0] - k) / (1.0 - k)) * 255.0)

        k_uint8: np.ndarray[np.uint8] = np.uint8(k * 255.0)

        cyan: np.ndarray[np.uint8] = cv2.merge([c, c, zeros])
        magenta: np.ndarray[np.uint8] = cv2.merge([m, zeros, m])
        yellow: np.ndarray[np.uint8] = cv2.merge([zeros, y, y])
        key: np.ndarray[np.uint8] = cv2.merge([k_uint8, k_uint8, k_uint8])

        return np.uint8([cyan, magenta, yellow, key])

    # nenhum espaço de cor
    return image


if __name__ == "__main__":
    input_image: np.ndarray[np.uint8] = cv2.imread("imagens/imagem2.jpeg")

    cv2.imshow("Componente R (RGB)", image_color_splitting(input_image, 0)[0])
    cv2.imshow("Componente G (RGB)", image_color_splitting(input_image, 0)[1])
    cv2.imshow("Componente B (RGB)", image_color_splitting(input_image, 0)[2])
    """
    cv2.imshow("Componente H (HSV)", image_color_splitting(input_image, 1)[0])
    cv2.imshow("Componente S (HSV)", image_color_splitting(input_image, 1)[1])
    cv2.imshow("Componente V (HSV)", image_color_splitting(input_image, 1)[2])
    """
    """
    cv2.imshow("Componente Y (YUV)", image_color_splitting(input_image, 2)[0])
    cv2.imshow("Componente U (YUV)", image_color_splitting(input_image, 2)[1])
    cv2.imshow("Componente V (YUV)", image_color_splitting(input_image, 2)[2])
    """
    """
    cv2.imshow("Componente C (CMYK)", image_color_splitting(input_image, 3)[0])
    cv2.imshow("Componente M (CMYK)", image_color_splitting(input_image, 3)[1])
    cv2.imshow("Componente Y (CMYK)", image_color_splitting(input_image, 3)[2])
    cv2.imshow("Componente K (CMYK)", image_color_splitting(input_image, 3)[3])
    """

    cv2.waitKey(0)
    cv2.destroyAllWindows()
