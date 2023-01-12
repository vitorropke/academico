#include <stdio.h>

int main()
{
	int vetor[5] = { 1, 2, 3, 4, 5 }, numeroAtual, contador, controle;
	
	for(numeroAtual = 4; numeroAtual >= 0; numeroAtual--)
	{
		for(contador = numeroAtual; contador > 0; contador--)
		{
			controle = vetor[numeroAtual - contador];
			vetor[numeroAtual - contador] = vetor[numeroAtual - contador + 1];
			vetor[numeroAtual - contador + 1] = controle;
		}
	}
	
	for(contador = 0; contador < 5; contador++)
	{
		printf(" %d ", vetor[contador]);
	}
	
	return 0;
}
