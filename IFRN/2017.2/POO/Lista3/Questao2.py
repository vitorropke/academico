numero=[0 for x in range(10)]

for x in range(10):
    numero[x]=float(input("Digite um número: "))

for x in range(9,-1, -1):
    print(numero[x])