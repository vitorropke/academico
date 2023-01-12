#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **matrizDeNumeros, linha, coluna, numeroDeLinhas, numeroDeColunas;
	
	printf("Digite o numero de linhas da matriz: ");
	scanf("%d", &numeroDeLinhas);
	printf("Digite o numero de colunas da matriz: ");
	scanf("%d", &numeroDeColunas);
	printf("\n");
	
	matrizDeNumeros = (int **) malloc(numeroDeLinhas * sizeof(int*));
	
	for(linha = 0; linha < numeroDeLinhas; linha++)
	{
		matrizDeNumeros[linha] = (int*) malloc(numeroDeColunas * sizeof(int));
		for(coluna = 0; coluna < numeroDeColunas; coluna++)
		{
			printf("Digite um numero: ");
			scanf("%d", &matrizDeNumeros[linha][coluna]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(linha = 0; linha < numeroDeLinhas; linha++)
	{
		for(coluna = 0; coluna < numeroDeColunas; coluna++)
		{
			printf("%d ", matrizDeNumeros[linha][coluna]);
		}
		printf("\n");
	}
	
	free(matrizDeNumeros);
	
	return 0;
}
