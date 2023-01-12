import questão8
import questão9
import questão10

num_alunos=int(input("Digite o número de alunos na turma: "))

nome=[0 for x in range(num_alunos)]
altura=[0 for x in range(num_alunos)]
genero=[0 for x in range(num_alunos)]
soma_total=0
num_mulheres=0
soma_mulheres=0

for x in range(num_alunos):
    nome[x]=input("Digite o nome do aluno: ")
    altura[x]=float(input("Digite a altura do aluno: "))
    soma_total+=altura[x]
    genero[x]=input("Digite o gênero do aluno(M/F): ")
    if genero[x]=='F':
        num_mulheres+=1
        soma_mulheres+=altura[x]

#Primeiro Ponto
for x in range(num_alunos):
    if questão9.maior(altura)==x:
        print("Maior altura é: ", altura[x], "m de ", nome[x])

for x in range(num_alunos):
    if questão10.menor(altura)==x:
        print("Menor altura é: ", altura[x], "m de ", nome[x])

#Segundo Ponto
print("Mulheres com altura acima da média das mulheres da turma: ")
media_mulheres=soma_mulheres/num_mulheres
for x in range(num_alunos):
    if genero[x]=='F' and altura[x]>media_mulheres:
        print("Nome: ", nome[x], "| Altura: ", altura[x])

#Terceiro Ponto
print("Pessoas com altura abaixo da média da turma: ")
for x in range(num_alunos):
    if altura[x]<questão8.media(altura):
        print("Nome: ", nome[x], "| Altura: ", altura[x])
