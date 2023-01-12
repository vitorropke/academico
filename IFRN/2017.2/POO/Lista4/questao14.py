import questão8
import questão9
import questão10

nome=[0 for x in range(10)]
salario=[0 for x in range(10)]

for x in range(10):
    nome[x]=input("Digite o nome do indivíduo: ")
    salario[x]=float(input("Digite o salário do indivíduo: "))

for x in range(10):
    if questão9.maior(salario)==x:
        print("Maior salário é: ", salario[x], " de ", nome[x])

for x in range(10):
    if questão10.menor(salario)==x:
        print("Menor salário é: ", salario[x], " de ", nome[x])

print("Pessoas que recebem abaixo da média salarial: ")
for x in range(10):
    if salario[x]<questão8.media(salario):
        print("Nome: ", nome[x], "| Altura: ", salario[x])
