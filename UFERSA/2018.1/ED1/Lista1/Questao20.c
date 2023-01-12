#include <stdio.h>

int main()
{
	int numeroInicial, numeroFinal, contador, soma = 0;
	
	printf("Digite um numero inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero final: ");
	scanf("%d", &numeroFinal);
	
	for(contador = numeroInicial; contador <= numeroFinal; contador++)
	{
		soma += contador;
	}
	
	printf("\n%d\n", soma);
	
	return 0;
}
