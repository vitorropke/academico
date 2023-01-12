linhas=3
colunas=3
matrix_1=[[0 for x in range(colunas)] for y in range(linhas)]
matrix_2=[[0 for x in range(colunas)] for y in range(linhas)]

for x in range(linhas):
    for y in range(colunas):
        matrix_1[x][y]=float(input("Digite um número para matriz 1: "))
print()
for x in range(linhas):
    for y in range(colunas):
        matrix_2[x][y]=float(input("Digite um número para matriz 2: "))

for x in range(linhas):
    for y in range(colunas):
        print(matrix_1[x][y]+matrix_2[x][y], end=' ')
    print()
