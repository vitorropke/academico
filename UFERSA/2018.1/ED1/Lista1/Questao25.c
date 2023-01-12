#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *vetorDeNumeros, contador, tamanhoDoVetor;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanhoDoVetor);
	printf("\n");
	
	vetorDeNumeros = (int *) malloc(tamanhoDoVetor * sizeof(int));
	
	for(contador = 0; contador < tamanhoDoVetor; contador++)
	{
		printf("Digite um numero: ");
		scanf("%d", &vetorDeNumeros[contador]);
	}
	
	printf("\n");
	
	for(contador = 0; contador < tamanhoDoVetor; contador++)
	{
		printf("%d ", vetorDeNumeros[contador]);
	}
	
	free(vetorDeNumeros);
	
	return 0;
}
