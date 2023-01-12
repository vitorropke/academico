#include<stdio.h>
#include<malloc.h>

typedef struct lista_no {
	int info;
	struct lista_no *ant;
	struct lista_no *prox;
}LISTA;

LISTA* criar(void);
LISTA* inserir(LISTA* l, int v);
LISTA* buscar(LISTA* l, int v);
LISTA* remover(LISTA* l, int v);

int main() 
{
	int v;
	
	printf("\nEntre com a chave: ");
	scanf("%d",&v); 
	
	LISTA *p;
	p=criar();
	p=inserir(p,v);
	printf("Fim P -->%p\n",p);
	
	getch();
	return (0);
}

LISTA* criar(void)
{
	return NULL;
}

LISTA* inserir(LISTA* l, int v)
{
	LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
	
	novo->info = v;
	novo->prox = l;
	novo->ant  = NULL;
	
	if(l != NULL)
		l->ant = novo;
	
	return novo;
}

LISTA* buscar(LISTA* l, int v)
{
	LISTA* p;
	
	for(p=l;p!=NULL;p=p->prox)
	{ 
		if(p->info == v)
			return p;
	}
	
	return NULL;
}

LISTA* remover(LISTA* l, int v)
{
	LISTA* p = buscar(l,v);
	
	if(p == NULL)
		return l;
	
	if(l == p)
		l = p->prox;
	else
		p->ant->prox = p->prox;
	
	if(p->prox != NULL)
		p->prox->ant = p->ant;
	
	free(p);
	
	return l;
}
