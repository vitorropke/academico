#include <stdio.h>

int main()
{
	int matrizDeNumeros[5][5], linha, coluna;
	
	for(linha = 0; linha < 5; linha++)
	{
		for(coluna = 0; coluna < 5; coluna++)
		{
			printf("Digite um numero: ");
			scanf("%d", &matrizDeNumeros[linha][coluna]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(linha = 0; linha < 5; linha++)
	{
		for(coluna = 0; coluna < 5; coluna++)
		{
			printf("%d ", matrizDeNumeros[linha][coluna]);
		}
		printf("\n");
	}
	
	return 0;
}
