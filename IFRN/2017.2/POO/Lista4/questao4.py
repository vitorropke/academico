import questão3

vetor=[0 for x in range(10)]
vetor_par=[0 for x in range(10)]
vetor_impar=[0 for x in range(10)]
cont_par=0
cont_impar=0

for x in range(10):
    vetor[x]=float(input("Digite um número: "))
    if questão3.par(vetor[x]):
        vetor_par[cont_par]=vetor[x]
        cont_par+=1        
    else:
        vetor_impar[cont_impar]=vetor[x]
        cont_impar+=1        

print("Vetor total: ")
for x in range(10):
    print(vetor[x], end=' ')
print()
print("Vetor par: ")
for x in range(cont_par):
    print(vetor_par[x], end=' ')
print()
print("Vetor impar: ")
for x in range(cont_impar):
    print(vetor_impar[x], end=' ')
