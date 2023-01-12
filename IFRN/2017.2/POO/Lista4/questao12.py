import questão8

vetor=[0 for x in range(10)]

for x in range(10):
    vetor[x]=int(input("Digite um número: "))

for x in range(10):
    if vetor[x]>questão8.media(vetor):
        print(vetor[x])
