import questão16

numero=int(input("Digite um numero: "))
vetor=[0 for x in range(1000)]
cont=0

while numero>0:
    vetor[cont]=numero%10
    cont+=1
    numero=numero//10

for x in range(cont-1,-1,-1):
    print(questão16.extenso(vetor[x]), end=' ')
