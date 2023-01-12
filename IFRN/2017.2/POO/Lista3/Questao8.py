numero=[0 for x in range(10)]
numero_par=[0 for x in range(10)]
numero_impar=[0 for x in range(10)]
cont_par=0
cont_impar=0

for x in range(10):
    numero[x]=float(input("Digite um numero: "))
    if numero[x]%2==0:
        numero_par[cont_par]=numero[x]
        cont_par+=1
    else:
        numero_impar[cont_impar]=numero[x]
        cont_impar+=1

print("Vetor total: ")
for x in range(10):
    print(numero[x], end=' ')
print()
print("Vetor par: ")
for x in range(cont_par):
    print(numero_par[x], end=' ')
print()
print("Vetor impar: ")
for x in range(cont_impar):
    print(numero_impar[x], end=' ')
