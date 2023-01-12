#include <stdio.h>
#include<stdlib.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

void shellSort(tElemento*, int);

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
	
	shellSort(estruturaDinamica, tamanho);
	
	free(estruturaDinamica);
	
	return 0;
}

void shellSort(tElemento *estruturaDinamica, int tamanho) {
	int i , j , valor, gap = 1;
	
	while(gap < tamanho)
		gap = 3 * gap + 1;
	
	while (gap > 1) {
		gap /= 3;
		
		for(i = gap; i < tamanho; i++) {
			valor = estruturaDinamica[i].id;
			j = i;
			
			while (j >= gap && valor < estruturaDinamica[j - gap].id) {
				estruturaDinamica[j].id = estruturaDinamica[j - gap].id;
				j = j - gap;
			}
			
			estruturaDinamica[j].id = valor;
		}
	}
}
