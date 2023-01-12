#include <stdio.h>
#include <string.h>

typedef struct sElemento
{
    int id;
	char nome[30];
	float valor;
	struct sElemento* pProx;
} tLista;

tLista* inicializarListaComCabeca();
void inserirInicio(tLista* pInicio, char* nome);
int percorrer(tLista* pInicio);
tLista* buscar(tLista* pInicio, int id);
void inserirFim(tLista* pInicio, char* nome);
void inserirDepoisDe(tLista* pInicio, char* nome, int id);
tLista* buscarAnterior(tLista* pInicio, int id);
tLista* remover(tLista* pInicio, int id);

tLista* inicializarListaComCabeca()
{
    tLista* p = (tLista*) calloc( 1, sizeof(tLista) );
	
	strcpy(p->nome, "");
	p->id = 1;
    p->pProx = NULL;

    return p;
}

void inserirInicio(tLista* pInicio, char* nome)
{
	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
	strcpy(pNovo->nome, nome);
	pNovo->valor = pInicio->valor;
    pNovo->id = pInicio->id;
	pNovo->pProx = NULL;
    
    pInicio->id = pInicio->id + 1;
	
	pNovo->pProx = pInicio->pProx;
	pInicio->pProx = pNovo;
}

int percorrer(tLista* pInicio)
{
    int i = 0;
    tLista* p = pInicio->pProx;
    
	if(p == NULL) {
		printf("OPS! LISTA VAZIA!!! \n");
		return 0;
	}
	
	while (p != NULL)
	{
        i++;
        printf("\n");
        printf("i: %d\n", i);
		printf("p: %d \n", p);
        printf("ID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("Valor: %.2f\n", p->valor);
        printf("pProx: %d\n", p->pProx);
        printf("\n");
        p = p->pProx;
	}
	
	printf("Quantidade de Elementos = %d \n", i);
    return i;
}

tLista* buscar(tLista* pInicio, int id)
{
    tLista* p = pInicio->pProx;
	
    while (p != NULL)
    {
        if (p->id == id) {
           return p;
        }
        
        p = p->pProx;
    }
    
    return NULL;
}

void inserirFim(tLista* pInicio, char* nome)
{
	tLista* pNovo = (tLista*) calloc(1, sizeof(tLista) );
	
	strcpy(pNovo->nome, nome);
	pNovo->valor = pInicio->valor;
    pNovo->id = pInicio->id;
    pNovo->pProx = NULL; 
	
    pInicio->id = pInicio->id + 1;
    
    tLista* p = pInicio;
	
    while (p->pProx != NULL) {
        p = p->pProx;
    }
    
    p->pProx = pNovo;
}

void inserirDepoisDe(tLista* pInicio, char* nome, int idCriterio)
{
    tLista* p = buscar(pInicio, idCriterio);
	
	if(p == NULL)
	{
        printf("Criterio invalido \n");
	}
	else
	{
    	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
    	
    	strcpy(pNovo->nome, nome);
        pNovo->id = pInicio->id;
        pNovo->pProx = NULL;
    	
        pInicio->id = pInicio->id + 1;
		
    	pNovo->pProx = p->pProx;
    	p->pProx = pNovo;
	}
}

tLista* buscarAnterior(tLista* pInicio, int id)
{
    tLista* p = pInicio;
	tLista* result = NULL;
	
	if(pInicio->pProx == NULL)
	{
		result = NULL;
	}	
	else
	{
        result = pInicio;
		
		while (p != NULL)
    	{
	        if (p->id == id) {
	           return result;
	        }
			
			result = p;
        	p = p->pProx;
    	}
	}
	
    return NULL;
}

tLista* remover(tLista* pInicio, int id)
{
    tLista* anterior = buscarAnterior(pInicio, id);
    tLista* p = NULL;
    
    if(anterior == NULL)
    {
    	printf("anterior NULL. Nao existe elemento com esse id \n");
    	return NULL;
    }
    else
    {
    	p = anterior->pProx;
    	
        anterior->pProx = p->pProx;
        p->pProx = NULL;
    }
	
	return p;
}

int main()
{
	int opcao, id;
	char nome[30];
	float valor;
	
    tLista* pInicio = inicializarListaComCabeca();
	
    do 
    {
    	printf("\n");
		printf("MENU: Lista simplesmente encadeada \n");
        printf("1-Percorrer \n");
        printf("2-Proximo ID (na cabeca) \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no Inicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
        printf("0-Sair \n");
        printf("Qual sua opcao? ");
        scanf("%d", &opcao);
        printf("\n");
		
        switch(opcao)
        {
            case 1: printf("PERCORRER \n");
                    percorrer(pInicio);
                    break;
			
			case 2: printf("PROXIMO ID (na cabeca) \n");
                    printf("maior = %d \n", pInicio->id);
                    break;
            
			case 3: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tLista* result = NULL;
                    result = buscar(pInicio, id);
                    printf("result = %d \n", result);
                    if(result != NULL) {
	        			printf("ID: %d\n", result->id);
	        			printf("Nome: %s\n", result->nome);
	        			printf("Valor: %s\n", result->valor);
	        			printf("pProx: %d\n", result->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;
			
			case 4: printf("BUSCAR ANTERIOR \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tLista* resultAnterior = NULL;
                    resultAnterior = buscarAnterior(pInicio, id);
                    printf("resultAnterior = %d \n", resultAnterior);
                    if(result != NULL) {
	        			printf("ID: %d\n", resultAnterior->id);
	        			printf("Nome: %s\n", resultAnterior->nome);
	        			printf("Nome: %s\n", resultAnterior->valor);
	        			printf("pProx: %d\n", resultAnterior->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;
			
            case 5: printf("INSERIR INICIO \n");
					printf("Qual o nome do individuo? ");
                    scanf("%s", &nome);
                    printf("Qual o valor? ");
                    scanf("%f", &valor);
                    inserirInicio(pInicio, nome);
                    break;
			
            case 6: printf("INSERIR FIM \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    printf("Qual o valor? ");
                    scanf("%f", &valor);
                    inserirFim(pInicio, nome);
                    break;
			
            case 7: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome? ");
                    scanf("%s", &nome);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, nome, id);
                    break;
			
            case 8: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tLista* resultRemove = NULL;
                    resultRemove = remover(pInicio, id);
                    printf("result = %d \n", result);
                    if(resultRemove != NULL) {
	        			printf("ID: %d\n", resultRemove->id);
	        			printf("Nome: %s\n", resultRemove->nome);
	        			printf("Valor: %s\n", resultRemove->valor);
	        			printf("pProx: %d\n", resultRemove->pProx);
                        free(resultRemove);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;
			
            case 0: printf("Saindo... \n");
                    break;
			
            default: printf("OPCAO INVALIDA \n");
                     break;
        }
        
        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(opcao != 0);
	
    system("pause");
    return 0;
}
