numero=[0 for x in range(10)]
soma=0

for x in range(10):
    numero[x]=float(input("Digite um numero: "))
    maior=numero[0]
    menor=numero[0]
    if numero[x]>maior:
        maior=numero[x]
    if numero[x]<menor:
        menor=numero[x]
    soma+=numero[x]

media=soma/10

print("Maior: ", maior)
print("Menor: ", menor)
print("Média: ", media)
