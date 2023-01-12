def menor(vetor):
    menor=vetor[0]
    indice=0
    for x in range(len(vetor)):
        if vetor[x]<menor:
            indice=x
    return indice
