num_alunos=int(input("Digite o número de alunos na turma: "))

nome=[0 for x in range(num_alunos)]
altura=[0 for x in range(num_alunos)]
genero=[0 for x in range(num_alunos)]
soma_total=0
soma_mulheres=0
num_mulheres=0

for x in range(num_alunos):
    nome[x]=input("Digite o nome do aluno: ")
    altura[x]=float(input("Digite a altura do aluno: "))
    if x==0:
        maior=altura[0]
        menor=altura[0]
        indexmaior=0
        indexmenor=0
    if altura[x]>maior:
        maior=altura[x]
        indexmaior=x
    if altura[x]<menor:
        menor=altura[x]
        indexmenor=x
    soma_total+=altura[x]
    genero[x]=input("Digite o gênero do aluno (M/F): ")
    if genero[x]=='F':
        soma_mulheres+=altura[x]
        num_mulheres+=1

#Primeiro Ponto
print("Maior altura: ", maior, " de ", nome[indexmaior])
print("Menor altura: ", menor, " de ", nome[indexmenor])
print()

#Segundo Ponto
print("Mulheres acima da média das mulheres da turma: ")
media_mulheres=soma_mulheres/num_mulheres
for x in range(num_alunos):
    if genero[x]=='F' and altura[x]>media_mulheres:
        print("Nome: ", nome[x], "| Altura: ", altura[x])
print()

#Terceiro Ponto
print("Pessoas com altura abaixo da média da turma: ")
media_total=soma_total/num_alunos
for x in range(num_alunos):
    if altura[x]<media_total:
        print("Nome: ", nome[x], "| Altura: ", altura[x])
