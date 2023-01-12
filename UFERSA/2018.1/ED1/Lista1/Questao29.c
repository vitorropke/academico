#include <stdio.h>

int main()
{
	int vetor[5] = { 23, 44, 12, 6, 30 }, maiorNumero = vetor[0], menorNumero = vetor[0], contador;
	
	for(contador = 0; contador < 5; contador++)
	{
		if(vetor[contador] > maiorNumero)
		{
			maiorNumero = vetor[contador];
		}
		
		if(vetor[contador] < menorNumero)
		{
			menorNumero = vetor[contador];
		}
	}
	
	printf("Maior numero = %d\n", maiorNumero);
	printf("Menor numero = %d\n", menorNumero);
	
	return 0;
}
