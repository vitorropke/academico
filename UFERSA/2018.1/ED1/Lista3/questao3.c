#include <stdio.h>
#include<stdlib.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

int buscaBinaria(tElemento*, int, int);

int main()
{
	int tamanho, contador, contadorString, chave;
	tElemento *estruturaDinamica;
    
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    estruturaDinamica = (tElemento *)malloc(tamanho * sizeof(tElemento));
    
	for (contador = 0; contador < tamanho; contador++)
	{
		estruturaDinamica[contador].id = rand() % 100; //Valores aleatórios na estrutura estática
		
		for(contadorString = 0; contadorString < 30; contadorString++)
			estruturaDinamica[contador].nome[contadorString] = rand() % 100; //Letras aleatórias na estrutura estática
	}
	
	printf("Digite qual valor voce deseja procurar: ");
	scanf("%d",&chave);
	
	if ( buscaBinaria(estruturaDinamica, chave , tamanho) != -1 )
		printf("\nValor encontrado!\n");
	else
		printf("\nValor nao encontrado!\n");
	
	free(estruturaDinamica);
	
	return 0;
}

int buscaBinaria(tElemento *estruturaDinamica, int chave, int tamanho)
{
	int baixo = 0;
	int cima = tamanho-1;
	int meio;
	
	while (baixo <= cima)
	{
		meio = (baixo + cima) / 2;
		
		if (chave == estruturaDinamica[meio].id){
			printf("\nID: %d\n", estruturaDinamica[meio].id);
			printf("Nome: %s\n", estruturaDinamica[meio].nome);
			
			return meio;
		}
		
		if (chave < estruturaDinamica[meio].id)
			cima = meio - 1;
		else
			baixo = meio + 1;
	}
	
	return -1;
}
