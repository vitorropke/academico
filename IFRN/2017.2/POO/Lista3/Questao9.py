numero=[0 for x in range(10)]

for x in range(10):
    numero[x]=float(input("Digite um número: "))

for x in range(10):
    numero=sorted(numero)

for x in range(10):
    print(numero[x])
