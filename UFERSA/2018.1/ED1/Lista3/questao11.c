#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

void heapSort(tElemento*, int);

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
	
	heapSort(estruturaDinamica, tamanho);
	
	free(estruturaDinamica);
	
	return 0;
}

void heapSort(tElemento *estruturaDinamica, int tamanho) {
	int i = tamanho / 2, pai, filho, t;
	
	while(true) {
		if (i > 0) {
			i--;
			t = estruturaDinamica[i].id;
		} else {
			tamanho--;
			
			if (tamanho == 0)
				return;
			
			t = estruturaDinamica[tamanho].id;
			estruturaDinamica[tamanho].id = estruturaDinamica[0].id;
		}
		
		pai = i;
		filho = i * 2 + 1;
		
		while (filho < tamanho) {
			if ((filho + 1 < tamanho)  &&  (estruturaDinamica[filho + 1].id > estruturaDinamica[filho].id))
				filho++;
			
			if (estruturaDinamica[filho].id > t) {
				estruturaDinamica[pai].id = estruturaDinamica[filho].id;
				pai = filho;
				filho = pai * 2 + 1;
			} else {
				break;
			}
		}
		
		estruturaDinamica[pai].id = t;
	}
}
