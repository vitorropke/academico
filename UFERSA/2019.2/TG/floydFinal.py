#Abrindo arquivo de entrada
arquivoEntrada = open("grafo.txt")

#Dados vão para variável
entrada = arquivoEntrada.read()

#Fecha arquivo de entrada
arquivoEntrada.close()

#Achando a dimensão da matriz de adjacência
dimensao = 0
i = 0
numeroAnterior = False
while entrada[i] != "\n":
	if entrada[i] != '\t' and entrada[i] != ' ' and numeroAnterior == False:
		dimensao += 1
		numeroAnterior = True

		if entrada[i] == '\t' and entrada[i] != ' ':
			numeroAnterior = False

		i += 1

#String para matriz
aresta=[[0 for i in range(dimensao)] for j in range(dimensao)]

i = 0
j = 0
indice = 0
charNumeroAtual = ''
negativo = False
while entrada[indice] != None:
	while entrada[indice] != '\t' and entrada[indice] != ' ' and entrada[indice] != '\n':
		if entrada[indice] == '-':
			negativo = True
		else:
			charNumeroAtual += entrada[indice]

			#Incrementa índice da string
			indice += 1

			#Se for o último caractere, saia da repetição
			if indice == len(entrada):
				break

		#Verifica se o número é negativo ou não
		if negativo:
			aresta[i][j] = int(charNumeroAtual) * -1
			negativo = False
		else:
			aresta[i][j] = int(charNumeroAtual)

		#O número atual é esvaziado e a coluna é incrementada
		charNumeroAtual = ''
		j += 1

		#Se for o último caractere, saia da repetição
		if indice == len(entrada):
			break

		#Se houver uma quebra de linha, incremente a linha e retorne à primeira coluna
		if entrada[indice] == '\n':
			i += 1
			j = 0

		#Incrementa índice da string
		indice += 1

#Imprime matriz de adjacência
print("Antes do algoritmo\n")
for x in range(dimensao):
	for y in range(dimensao):
		print(aresta[x][y], end=' ')
	print()
print()

#Não temos como representar números infinitos em um computador. Portanto teremos que pegar o maior número e incrementá-lo em uma unidade e chamá-lo de infinito
infinito = aresta[0][0]
for i in range(dimensao):
	for j in range(dimensao):
		if infinito <aresta[i][j]:
			infinito = aresta[i][j]
infinito += 1

#Adjacências com valor zero, exceto valores na diagonal principal, receberão o número infinito
for i in range(dimensao):
	for j in range(dimensao):
		if i != j and aresta[i][j] == 0:
			aresta[i][j] = infinito

print("Após definir os valores infinitos\n")
for x in range(dimensao):
	for y in range(dimensao):
		print(aresta[x][y], end=' ')
	print()
print()

#Algoritmo de Floyd
for k in range (dimensao):
	for i in range (dimensao):
		for j in range (dimensao):
			if aresta[i][j] > aresta[i][k] + aresta[k][j]:
				aresta[i][j] = aresta[i][k] + aresta[k][j]

print("Após o algoritmo\n")
for i in range(dimensao):
	for j in range(dimensao):
		print(aresta[i][j], end=' ')
	print()

#Abrindo arquivo de saída
arquivoSaida = open("menorCaminho.txt", "w")

#Escrevendo a matriz no arquivo de saida
for i in range(dimensao):
	for j in range(dimensao):
		if not j == dimensao-1:
			arquivoSaida.write("%s\t" %aresta[i][j])
		else:
			arquivoSaida.write("%s" %aresta[i][j])
	
	if not i == dimensao-1:
		arquivoSaida.write("\n")

#Fechando arquivo de saída
arquivoSaida.close()
