#include <stdio.h>

int main()
{
	int numeroInicial, numeroFinal, contador;
	
	printf("Digite um numero inteiro inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero inteiro final: ");
	scanf("%d", &numeroFinal);
	
	for(contador = numeroInicial; contador <= numeroFinal; contador++)
	{
		printf("%d ", contador);
	}
	
	return 0;
}
