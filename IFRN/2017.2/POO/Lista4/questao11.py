import questão8
import questão9
import questão10

vetor=[0 for x in range(10)]

for x in range(10):
    vetor[x]=float(input("Digite um número: "))

print("Média: ", questão8.media(vetor))
for x in range(10):
    if questão9.maior(vetor)==x:
        print("Maior: ", vetor[x])

for x in range(10):
    if questão10.menor(vetor)==x:
        print("Menor: ", vetor[x])
