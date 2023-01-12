linhas_1=int(input("Digite o número de linhas para a primeira matriz: "))
colunas_1=int(input("Digite o número de colunas para a primeira matriz: "))
linhas_2=int(input("Digite o número de linhas para a segunda matriz: "))
colunas_2=int(input("Digite o número de colunas para a segunda matriz: "))



linhas=3
colunas=3
matrix_1=[[0 for x in range(colunas_1)] for y in range(linhas_1)]
matrix_2=[[0 for x in range(colunas_2)] for y in range(linhas_2)]
matriz_p=[[0 for x in range(colunas_2)] for y in range(linhas_1)]

for x in range(linhas_1):
    for y in range(colunas_1):
        matrix_1[x][y]=float(input("Digite um número para matriz 1: "))
print()
for x in range(linhas_2):
    for y in range(colunas_2):
        matrix_2[x][y]=float(input("Digite um número para matriz 2: "))

if colunas_1==linhas_2:
    for x in range(linhas_1):
        for y in range(colunas_2):
            for z in range(linhas_2):
                matriz_p[x][y]+=matrix_1[x][z]*matrix_2[z][y]

    for x in range(linhas_1):
        for y in range(colunas_2):
            print(matriz_p[x][y], end=' ')
        print()
else:
    print("Não é possível calcular o produto desta raiz.")
