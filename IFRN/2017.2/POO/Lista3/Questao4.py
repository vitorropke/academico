numero=[0 for x in range(10)]
repetido=0

for x in range(10):
    numero[x]=float(input("Digite um número: "))

for x in range(10):
    for y in range(x+1, 10):
        if numero[x]==numero[y]:
            repetido+=1

print("Números repetidos: ", repetido)
