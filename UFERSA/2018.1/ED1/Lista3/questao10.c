#include <stdio.h>
#include<stdlib.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

void quickSort(tElemento*, int, int);

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
	
	quickSort(estruturaDinamica, 0, tamanho);
	
	free(estruturaDinamica);
	
	return 0;
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
