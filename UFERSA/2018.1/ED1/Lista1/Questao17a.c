#include <stdio.h>

int main()
{
	int numeroInicial, numeroFinal;
	
	printf("Digite um numero inteiro inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero inteiro final: ");
	scanf("%d", &numeroFinal);
	
	while(numeroInicial <= numeroFinal)
	{
		printf("%d ", numeroInicial);
		numeroInicial++;
	}
	
	return 0;
}
