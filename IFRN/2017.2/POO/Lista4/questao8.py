def media(vetor):
    resultado=0
    for x in range(len(vetor)):
        resultado+=vetor[x]/len(vetor)
    return resultado
