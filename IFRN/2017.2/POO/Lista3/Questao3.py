numero=[0 for x in range(10)]
soma=0

for x in range(10):
    numero[x]=float(input("Digite um número: "))
    soma+=numero[x]

print("A soma dos números digitados é igual a ", soma)
