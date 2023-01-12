ptive_inf = 999999999999999999
dimensao=5
aresta=[[1 for x in range(dimensao)] for y in range(dimensao)]

aresta[1][1] = 0
aresta[1][2] = ptive_inf
aresta[1][3] = -2
aresta[1][4] = ptive_inf
aresta[2][1] = 4
aresta[2][2] = 0
aresta[2][3] = 3
aresta[2][4] = ptive_inf
aresta[3][1] = ptive_inf
aresta[3][2] = ptive_inf
aresta[3][3] = 0
aresta[3][4] = 2
aresta[4][1] = ptive_inf
aresta[4][2] = -1
aresta[4][3] = ptive_inf
aresta[4][4] = 0

for x in range(1, dimensao):
    for y in range(1, dimensao):
        print(aresta[x][y], end=' ')
    print()
print()

for k in range (1, dimensao):
    for i in range (1, dimensao):
        for j in range (1, dimensao):
            if aresta[i][j] > aresta[i][k] + aresta[k][j]:
                aresta[i][j] = aresta[i][k] + aresta[k][j]

for x in range(1, dimensao):
    for y in range(1, dimensao):
        print(aresta[x][y], end=' ')
    print()
