def fatorial(numero):
    resultado=1
    for x in range(numero):
        resultado=numero*resultado
        numero-=1
    return resultado
