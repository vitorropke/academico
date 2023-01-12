#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

void bubbleSort(tElemento*, int); //6
void insertSort(tElemento*, int); //7
void selectSort(tElemento*, int); //8
void shellSort(tElemento*, int); //9
void quickSort(tElemento*, int, int); //10
void heapSort(tElemento*, int); //11

int main()
{
	int tamanho, contador, contadorString, chave, escolha;
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
	
	printf("\n1 - Bubble Sort");
	printf("\n2 - Insert Sort");
	printf("\n3 - Select Sort");
	printf("\n4 - Shell Sort");
	printf("\n5 - Quick Sort");
	printf("\n6 - Heap Sort");
	printf("\nDigite o metodo de ordenacao que desejas: ");
	scanf("%d", &escolha);
	
	switch(escolha)
	{
		case 1:
			bubbleSort(estruturaDinamica, tamanho); //6
			break;
		case 2:
			insertSort(estruturaDinamica, tamanho); //7
			break;
		case 3:
			selectSort(estruturaDinamica, tamanho); //8
			break;
		case 4:
			shellSort(estruturaDinamica, tamanho); //9
			break;
		case 5:
			quickSort(estruturaDinamica, 0, tamanho); //10
			break;
		case 6:
			heapSort(estruturaDinamica, tamanho); //11
			break;
		default:
			printf("\nInválido");
	}
	
	free(estruturaDinamica);
	
	return 0;
}

void bubbleSort(tElemento* estruturaDinamica, int tamanho) {
	int i, j, auxiliar;
	
	for (i = 0; i < tamanho - 1; i++){
		for (j = (i + 1); j < tamanho; j++){
			if (estruturaDinamica[j].id < estruturaDinamica[i].id){
				auxiliar = estruturaDinamica[i].id;
				estruturaDinamica[i].id = estruturaDinamica[j].id;
				estruturaDinamica[j].id = auxiliar;
			}
		}
	}
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

void selectSort(tElemento *estruturaDinamica, int tamanho) { 
	int i, j, minimo, auxiliar;
	
	for (i = 0; i < (tamanho-1); i++) {
		minimo = i;
		
		for (j = (i + 1); j < tamanho; j++) {
			if(estruturaDinamica[j].id < estruturaDinamica[minimo].id)
				minimo = j;
		}
	
		if (estruturaDinamica[i].id != estruturaDinamica[minimo].id) {
			auxiliar = estruturaDinamica[i].id;
			estruturaDinamica[i].id = estruturaDinamica[minimo].id;
			estruturaDinamica[minimo].id = auxiliar;
		}
	}
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

void quickSort(tElemento *estruturaDinamica, int inicio, int fim){
	int pivo, aux, i = inicio, j = fim, meio;
	
	meio = (int) ((i + j) / 2);
	pivo = estruturaDinamica[meio].id;
	
	do{
		while (estruturaDinamica[i].id < pivo)
			i = i + 1;
		
		while (estruturaDinamica[j].id > pivo)
			j = j - 1;
		
		if(i <= j){
			aux = estruturaDinamica[i].id;
			estruturaDinamica[i].id = estruturaDinamica[j].id;
			estruturaDinamica[j].id = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);
	
	if(inicio < j)
		quickSort(estruturaDinamica, inicio, j);
	
	if(i < fim)
		quickSort(estruturaDinamica, i, fim);
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
