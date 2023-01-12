#include <stdio.h>

int main()
{
	int vetorDeNumeros[5], contador;
	
	for(contador = 0; contador < 5; contador++)
	{
		printf("Digite um numero: ");
		scanf("%d", &vetorDeNumeros[contador]);
	}
	
	printf("\n");
	
	for(contador = 0; contador < 5; contador++)
	{
		printf("%d ", vetorDeNumeros[contador]);
	}
	
	return 0;
}
