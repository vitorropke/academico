dimensao=int(input("Digite a dimensão desta matriz quadrada: "))
linhas=dimensao
colunas=dimensao
matrix=[[0 for x in range(colunas)] for y in range(linhas)]

for x in range(linhas):
    for y in range(colunas):
        matrix[x][y]=float(input("Digite um número: "))

for x in range(linhas):
    for y in range(colunas):
        if x==y:
            print(matrix[x][y])
