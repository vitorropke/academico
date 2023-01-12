#include <stdio.h>
#include<stdlib.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

void insertSort(tElemento*, int);

int main()
{
	int tamanho, contador, contadorString, chave;
	tElemento *estruturaDinamica;
    
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    estruturaDinamica = (tElemento *)malloc(tamanho * sizeof(tElemento));
    
	for (contador = 0; contador < tamanho; contador++)
	{
		estruturaDinamica[contador].id = rand() % 100; //Valores aleat�rios na estrutura est�tica
		
		for(contadorString = 0; contadorString < 30; contadorString++)
			estruturaDinamica[contador].nome[contadorString] = rand() % 100; //Letras aleat�rias na estrutura est�tica
	}
	
	insertSort(estruturaDinamica, tamanho);
	
	free(estruturaDinamica);
	
	return 0;
}

void insertSort(tElemento* estruturaDinamica, int tamanho) {
	int i, j, atual;
	
	for (i = 1; i < tamanho; i++) {
		atual = estruturaDinamica[i].id;
		
		for (j = i - 1; (j >= 0) && (atual < estruturaDinamica[j].id); j--)
			estruturaDinamica[j + 1].id = estruturaDinamica[j].id;
        
		estruturaDinamica[j + 1].id = atual;
	}
}
