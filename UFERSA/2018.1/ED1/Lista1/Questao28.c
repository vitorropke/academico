#include <stdio.h>

void vetorAoContrario(int *, int);

int main()
{
	int vetor[5] = { 1, 2, 3, 4, 5 };
	
	vetorAoContrario(vetor, 5);
	
	return 0;
}

void vetorAoContrario(int * vetorNormal, int tamanhoDoVetor)
{
	int contador;
	
	vetorNormal = vetorNormal + (tamanhoDoVetor - 1);
	
	for(contador = 0; contador < tamanhoDoVetor; contador++)
	{
		printf(" %d ", *(vetorNormal - contador));
	}
}
