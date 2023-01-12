#include <stdio.h>
#define MAX 4
#define FLAG_FAIL 0
#define FLAG_OK 1

typedef struct sFila{
	char nome[10];
	float valor;
} tFila;

int inserir(tFila* fila, int* inicio, int* fim, int valor)
{
    printf("Inserindo \n");
	
    int fimTemp = (*fim + 1) % MAX;
	
    if (fimTemp == *inicio) {
       printf("A fila encheu \n");
       return FLAG_FAIL;
    }
	
    *fim = fimTemp;
    fila->nome[*fim] = valor;
    
    if (*inicio == -1) { 
        *inicio = 0;
    }
    
    printf("Valor: %d \n", valor);
	
    return FLAG_OK;
}

int remover(tFila* fila, int* inicio, int* fim, int* retorno)
{
    if (*inicio == -1) {
    	printf("A fila encheu \n");
        return FLAG_FAIL;
    }
	
    *retorno = fila->nome[*inicio];
    
    if (*inicio == *fim) {
        *inicio = -1;
        *fim = -1;
    }
    else {
      *inicio = (*inicio + 1) % MAX;
    }
    
    printf("OK: %d \n", *retorno);
    
   return FLAG_OK;
}

void exibir(tFila *fila, int inicio, int fim)
{
    printf("Exibir... \n");
    
    int cont = inicio;
	
    while(cont != fim)
    {
        printf(" posicao %d = %d \n", cont, fila->nome[cont] );
        cont++;

        if (cont == MAX) {
            cont = 0;
        }
    }
    
    printf(" posicao %d = %d \n", cont, fila->nome[cont]);
	printf(" inicio = %d    fim = %d \n\n", inicio, fim);
}

int main()
{
    int fila1[MAX];
    int inicio = -1;
    int fim = -1;
	
    inserir(fila1, &inicio, &fim, 3);
    inserir(fila1, &inicio, &fim, 5);
    inserir(fila1, &inicio, &fim, 7);
    inserir(fila1, &inicio, &fim, 9);
    inserir(fila1, &inicio, &fim, 12);
    
    int retorno = 0;
    if( remover(fila1, &inicio, &fim, &retorno) == FLAG_OK )
    {
        printf("retorno = %d \n", retorno);
    }
    else
    {
        printf("retorno impossivel \n");
    }
	
    inserir(fila1, &inicio, &fim, 15);
	
    exibir(fila1, inicio, fim);
	
    inserir(fila1, &inicio, &fim, 17);
    
    return 0;
}
