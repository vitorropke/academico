import numpy as np

numeroIteracoesDentro = 0
numeroIteracoesFora = 0
repeticoes = 8
vetor = np.array([10, 9, 8, 7, 6, 5, 4, 3])

print(vetor)

for i in range(1, repeticoes-1):
	k = i

	for j in range(i+1, repeticoes):
		if(vetor[j] < vetor[i]):
			k = j
		numeroIteracoesDentro += 1
	numeroIteracoesFora += 1
	temp = vetor[k]
	vetor[k] = vetor[i]
	vetor[i] = temp

print(vetor)
print(numeroIteracoesDentro)
print(numeroIteracoesFora)
