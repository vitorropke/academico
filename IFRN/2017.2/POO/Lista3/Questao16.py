linhas=3
colunas=3
matrix=[[0 for x in range(colunas)] for y in range(linhas)]

for x in range(linhas):
    for y in range(colunas):
        matrix[x][y]=float(input("Digite um número: "))

for x in range(linhas):
    for y in range(colunas):
        print(matrix[x][y]*2, end=' ')
    print()
