#include <stdio.h>

int main()
{
	int numero;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	if(numero % 2 == 0)
	{
		printf("\nPar\n");
	}
	else
	{
		printf("\nImpar\n");
	}
	
	return 0;
}
