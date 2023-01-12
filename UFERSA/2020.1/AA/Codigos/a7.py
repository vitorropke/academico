n = 4
vetor = [[0 for x in range(n)] for y in range(n)] 

for linha in range(n):
	for coluna in range(linha + 1):
		if coluna == 0 or coluna == linha:
			vetor[linha][coluna] = 1
			print(1, end = ' ');
		else:
			vetor[linha][coluna] = vetor[linha - 1][coluna - 1] + vetor[linha - 1][coluna]

			if vetor[linha][coluna] != 0:
				print(vetor[linha][coluna], end = ' ')
	print()
