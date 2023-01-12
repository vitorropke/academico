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
		if(numeroInicial % 2 == 1)
		{
			printf("%d ", numeroInicial);
		}
		numeroInicial++;
	}while(numeroInicial <= numeroFinal);
	
	return 0;
}
