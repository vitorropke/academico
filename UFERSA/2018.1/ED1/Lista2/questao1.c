#include <stdio.h>
#define MAX 3
#define FLAG_OK 1
#define FLAG_FAIL 0

typedef struct sPilha {
    char nome[10];
    float valor;
} tPilha;

int empilhar(tPilha* pilha, int* topo, int valor)
{
	printf("Empilhando\n");
    int flag = FLAG_OK;
	
    if (*topo == MAX-1)
    {
    	printf("A pilha encheu\n");
    	flag = FLAG_FAIL;
    }
    else
    {
    	*topo = *topo + 1;
    	pilha->valor = valor;
    }
	
    return flag;
}

int desempilhar(tPilha* pilha, int* topo, int* retorno)
{
	printf("Desempilhando\n");
    int flag = FLAG_OK;
	
    if (*topo == -1)
    {
    	printf("\n Não tem nada aqui\n");
        flag = FLAG_FAIL;
    }
    else
    {
        *retorno = pilha->nome[*topo];
        *topo = *topo - 1;
    }
	
   return flag;
}

void exibir(tPilha* pilha, int topo)
{
    int i;
	
	printf("\nExibindo pilha...\n");
	
    for(i=0; i<=topo; i++)
    {
        printf("posicao %d = %d \n", i, pilha->nome[i] );
    }
	printf("Topo = %d \n\n", topo );
}

int main()
{
    int Vetor[MAX];
    int topo1 = -1;
	
    empilhar(Vetor, &topo1, 3);
    empilhar(Vetor, &topo1, 5);
    empilhar(Vetor, &topo1, 7);
    empilhar(Vetor, &topo1, 12);
	
    int retorno = 0;
    if( desempilhar(Vetor, &topo1, &retorno) == FLAG_OK) {
        printf("retorno (em MAIN) = %d \n", retorno);
    }
    else {
        printf("nao retornou nada pois deu erro... \n");
    }
	
    exibir(Vetor, topo1);
	
    return 0;
}
