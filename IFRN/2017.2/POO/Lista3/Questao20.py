gabarito=[0 for x in range(10)]

for x in range(10):
    gabarito[x]=input("Digite a resposta da questão {}: ".format(x+1))

num_alunos=int(input("Digite o número de alunos na turma: "))

boletim=[[0 for x in range(3)] for y in range(num_alunos)]
marcado=[0 for x in range(10)]
soma_nota=0
num_reprovados=0

for x in range(num_alunos):
    boletim[x][0]=input("Digite o nome do aluno: ")
    for y in range(10):
        marcado[y]=input("Digite o item marcado na questão {}: ".format(y+1))
        if marcado[y]==gabarito[y]:
            boletim[x][1]+=10
    soma_nota+=boletim[x][1]
    if boletim[x][1]>70:
        boletim[x][2]="Aprovado"
    else:
        boletim[x][2]="Reprovado"
        num_reprovados+=1

media=soma_nota/num_alunos

print("NOME | NOTA | SITUAÇÃO")
for x in range(num_alunos):
    for y in range(3):
        print(boletim[x][y], end='  ')
    print()

print("Média da turma é ", media)
print("Número de reprovados é ", num_reprovados)
