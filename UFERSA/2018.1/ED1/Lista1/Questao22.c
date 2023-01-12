#include <stdio.h>

int main()
{
	int numero, contador, divisores = 0;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	for(contador = 1; contador <= numero; contador++)
	{
		if(numero % contador == 0)
		{
			divisores += 1;
		}
	}
	
	if(divisores == 2)
	{
		printf("\nPrimo\n");
	}
	else
	{
		printf("\nNao primo\n");
	}
	
	return 0;
}
