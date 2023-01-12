def maior(vetor):
    maior=vetor[0]
    indice=0
    for x in range(len(vetor)):
        if vetor[x]>maior:
            indice=x
    return indice
