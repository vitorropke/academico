#include <stdio.h>

int main()
{
	int numero, contador, fatorial;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	for(contador = 1; contador <= numero; contador++)
	{
		fatorial = fatorial * contador;
	}
	
	printf("\n%d\n", fatorial);
	
	return 0;
}
