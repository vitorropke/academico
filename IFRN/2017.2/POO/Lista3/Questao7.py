numero=[0 for x in range(10)]
soma=0

for x in range(10):
    numero[x]=float(input("Digite um numero: "))
    soma+=numero[x]

media=soma/10

for x in range(10):
    if numero[x]>media:
        print(numero[x])
