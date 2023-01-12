#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sElemento {
	int id;
    char nome[30];
    float valor;
    struct sElemento* pAnte;
    struct sElemento* pProx;
} tElemento;

tElemento* inicializarLista();
int inserirInicio(tElemento* inicio, char* nome);
int percorrer(tElemento* inicio);
tElemento* buscar(tElemento* inicio, int key);
int inserirFim(tElemento* inicio, char* nome);
void inserirDepoisDe(tElemento* pInicio, char* nome, int key);
tElemento* remover(tElemento* inicio, int key);

tElemento* inicializarLista()
{
	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento) );
	
	pNovo->id = 1;
    strcpy(pNovo->nome, "");
    pNovo->valor = 0;
    pNovo->pAnte = NULL;
    pNovo->pProx = NULL;
    
    return pNovo;
}

tElemento* criarNovo(tElemento* pInicio, char* nome)
{
	tElemento *p = (tElemento*) calloc( 1, sizeof(tElemento) );
	p->id = pInicio->id;
	strcpy(p->nome, nome);
	p->valor = 0;
	p->pAnte = NULL;
    p->pProx = NULL;
    
    pInicio->id = pInicio->id + 1;
    
    return p;
}

int inserirInicio(tElemento* pInicio, char* nome)
{
    tElemento *pNovo = criarNovo(pInicio, nome);
    
    pNovo->pAnte = pInicio;
    pNovo->pProx = pInicio->pProx;
    
    tElemento *pDireita = pInicio->pProx;
    pInicio->pProx = pNovo;
    
    if(pDireita == NULL) {
    	pInicio->pAnte = pNovo;
    }
    else {
        pDireita->pAnte = pNovo;
    }
}

int percorrer(tElemento* inicio)
{
    int i = 0;
    tElemento* p = inicio->pProx;
    
    if(p == NULL) {
        printf("Lista Vazia!!! \n");
		return 0;
    }
    
    while(p != NULL)
    {
        i++;
        printf("i: %d \n", i );
        printf("ID: %d \n", p->id );
        printf("NOME: %s \n", p->nome );
        printf("Valor: %f \n", p->valor);
        printf("p = %d \n", p);
        printf("pAnte = %d \n", p->pAnte);
        printf("pProx = %d \n\n", p->pProx);
        p = p->pProx;
    }
    
	printf("Quantidade de Elementos = %d \n", i);
    return i;
}

tElemento* buscar(tElemento* inicio, int key)
{
    tElemento* p = inicio->pProx;
    
    while(p != NULL)
    {
        if(p->id == key) {
            return p;
        }
        
        p = p->pProx;
    }
    
    return NULL;
}

int inserirFim(tElemento* pInicio, char* nome)
{
    tElemento *pNovo = criarNovo(pInicio, nome);
    
    tElemento *pUltimo = pInicio->pAnte;
    
    if(pUltimo == NULL) {
        pUltimo = pInicio;
    }
    
    pNovo->pAnte = pUltimo;
	pNovo->pProx = NULL;
	
    pUltimo->pProx = pNovo;
    
    pInicio->pAnte = pNovo;
}

void inserirDepoisDe(tElemento* pInicio, char* nomeNovo, int key)
{
    tElemento* p = buscar(pInicio, key);
    
	if(p == NULL)
	{
        printf("Criterio invalido \n");
	}
	else
	{
    	tElemento* pNovo = (tElemento*) calloc( 1, sizeof(tElemento));
    	pNovo->id = pInicio->id;
    	strcpy(pNovo->nome, nomeNovo);
    	pNovo->valor = 0;
        pNovo->pAnte = NULL;
        pNovo->pProx = NULL;
        
        pInicio->id = pInicio->id + 1;
        
    	pNovo->pProx = p->pProx;
		pNovo->pAnte = p;
		
	    tElemento *pSegundo = p->pProx;
	    p->pProx = pNovo;
	    
	    if(pSegundo != NULL) {
	        pSegundo->pAnte = pNovo;
	    }
        else {
            pInicio->pAnte = pNovo;
        }
	}
}

tElemento* remover(tElemento* pInicio, int key)
{
    tElemento* p = buscar(pInicio, key);
    
    if(p == NULL) {
        printf("ID nao encontrado \n");
    }
    else
    {
        tElemento* pEsquerda = p->pAnte;
        tElemento* pDireita  = p->pProx;            
        
        pEsquerda->pProx = pDireita;
        
        if(pDireita != NULL) {
            pDireita->pAnte = pEsquerda;
        }
        else {
            pInicio->pAnte = pEsquerda;
        }
        
        p->pAnte = NULL;
        p->pProx = NULL;
    }
    
    return p;
}

int main()
{    
    tElemento* lista1 = inicializarLista();
    
    int op;
    int id;
    char nome[30];
    float valor;
    tElemento *result;
    
    do
    {
    	printf("MENU: Lista duplamente encadeada \n");
        printf("1 - Percorrer \n");
		printf("2 - Proximo ID (na cabeca) \n");
	    printf("3 - Buscar Elemento \n");
        printf("4 - Inserir no Inicio \n");
        printf("5 - Inserir no Fim \n");
		printf("6 - Inserir (depois de...) \n");
        printf("7 - Remover \n");
        printf("0 - Sair \n");
        
        printf("Opcao: ");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1:
                printf("PERCORRER \n");
                percorrer(lista1);
                break;
                
			case 2: 
                printf("PROXIMO ID (na cabeca) \n");
                printf("maior = %d \n", lista1->id);
                break;
                
            case 3:
                printf("BUSCAR ELEMENTO \n");
                printf("Qual a chave? ");
                scanf("%d", &id);
                result = buscar(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                    printf("Valor: %f \n\n", result->valor );
                }
                else {
                    printf("result VAZIO");
                }
                break;
                
            case 4:
                printf("Inserir no Inicio \n");
                printf("Nome: ");
                scanf("%s", &nome);
                printf("Valor: ");
                scanf("%f", &valor);
                inserirInicio(lista1, nome);
                break;
                
            case 5:
                printf("Inserir no Fim \n");
                printf("Nome: ");
                scanf("%s", nome);
                printf("Valor: ");
                scanf("%f", &valor);
                inserirFim(lista1, nome);
                break;
                
            case 6: 
                printf("INSERIR DEPOIS DE... \n");
                printf("Inserir depois de qual chave? ");
                scanf("%d", &id);
				printf("Qual o nome? ");
                scanf("%s", &nome);
                printf("Valor: ");
                scanf("%f", &valor);
                inserirDepoisDe(lista1, nome, id);
                break;
                
            case 7:
                printf("Remover \n");
                printf("ID: ");
                scanf("%d", &id);
                result = remover(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                    printf("Valor: %f \n\n", result->valor );
                    free(result);
                }
                else {
                    printf("result VAZIO");
                }
                break;
                
            case 0:
                printf("Saindo... \n");
                break;
                
            default: 
                printf("INVALIDO \n");
                break;
        }
        
		printf("\n\n");
        system("pause");
        system("cls");
        
    }
    while( op != 0 );
    
    system("pause");
    return 0;
}
