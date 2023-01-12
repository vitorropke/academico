#include <stdio.h>

int main()
{
	int numeroInicial, numeroFinal;
	
	printf("Digite um numero inteiro inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero inteiro final: ");
	scanf("%d", &numeroFinal);
	
	do
	{
		printf("%d ", numeroInicial);
		numeroInicial++;
	}while(numeroInicial <= numeroFinal);
	
	return 0;
}
