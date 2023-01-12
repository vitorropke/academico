#include <stdio.h>
#include <string.h>

typedef struct sElemento
{
    int id;
	char nome[30];
	float valor;
	struct sElemento* pProx;
} tLista;

int getProxID(tLista* pInicio);
void inserirInicio(tLista** ppInicio, char* nome);
int percorrer(tLista* pInicio);
tLista* buscar(tLista* pInicio, int id);
void inserirFim(tLista** ppInicio, char* nome);
void inserirDepoisDe(tLista* pInicio, char* nome, int id);
tLista* buscarAnterior(tLista* pInicio, int id);
tLista* remover(tLista** ppInicio, int id);

int getProxID(tLista* pInicio)
{
    int maior = 0;
    tLista* p = NULL;
	
	p = pInicio;
	
    while( p != NULL )
    {
        if( p->id > maior  ) {
            maior = p->id;
        }
		
        p = p->pProx;
    }
	
    return (maior + 1);
}

void inserirInicio(tLista** ppInicio, char* nome)
{
    tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) ); 
    pNovo->id = getProxID(*ppInicio);
    strcpy( pNovo->nome, nome);
    pNovo->pProx = NULL;
	
    if( *ppInicio == NULL )
    {
        *ppInicio = pNovo;
    }
    else
    {
        pNovo->pProx = *ppInicio;
        *ppInicio = pNovo;
    }
}

int percorrer(tLista* pInicio)
{
	int i = 0;
    tLista *p = pInicio;
	
	if(p == NULL) {
		printf("Tem nada aqui \n");
	}
	else 
    {
        while( p != NULL )
        {
            i++;
            printf("\n");
            printf("i : %d \n", i);
            printf("Ponteiro: %d \n", p);
            printf("Ponteiro Proximo: %d \n", p->pProx);
            printf("ID: %d \n", p->id);
            printf("Nome: %s \n", p->nome);
            printf("Valor: %f \n", p->valor);
            printf("\n");
            p = p->pProx;
        }
    }
	
	printf("Quantidade de Elementos = %d \n", i);
    return i;
}

void inserirFim(tLista** ppInicio, char* nome)
{
    tLista *p = *ppInicio;
	
    tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
    pNovo->id = getProxID(*ppInicio);
    strcpy( pNovo->nome, nome);
    pNovo->pProx = NULL;
    
    if( *ppInicio == NULL ) {
        *ppInicio = pNovo;
    }
    else
    {
        while( p->pProx != NULL) {
            p = p->pProx;
        }
        
        p->pProx = pNovo;
    }
}

tLista* buscar(tLista* pInicio, int id)
{
    tLista* p = pInicio;
	
    while( p != NULL )
    {
        if( p->id == id ) {
            return p;
        }
        
        p = p->pProx;
    }
    
    return NULL;
}

void inserirDepoisDe(tLista* pInicio, char* nome, int id)
{
    tLista* p = buscar(pInicio, id);

    if( p == NULL )
    {
        printf("Criterio invalido \n");
    }
    else
    {
        tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
		 
        pNovo->id = getProxID(pInicio);
        strcpy( pNovo->nome, nome);
        pNovo->pProx = NULL;
        
        pNovo->pProx = p->pProx;
	    p->pProx = pNovo;
    }
}

tLista* buscarAnterior(tLista* pInicio, int id)
{
    tLista* p = pInicio;
	tLista* anterior = NULL;
	
    while (p != NULL)
    {
        if (p->id == id) {
           return anterior;
        }
		
		anterior = p;
        p = p->pProx;
    }
    
    return NULL;
}

tLista* remover(tLista** ppInicio, int id)
{	
	tLista* anterior = NULL;
	tLista* atual = NULL;
	
	if( *ppInicio == NULL ) {
        printf("Tem nada aqui \n");
        return NULL;
    }
    else { 
		anterior = buscarAnterior(*ppInicio, id);
		
		if( anterior == NULL ) {
			if( (*ppInicio)->id == id ) {
				atual = *ppInicio;
				
				if( atual->pProx == NULL ) {
					printf("Remove o primeiro e unico elemento \n");
					*ppInicio = NULL;
				}
				else {
	        		printf("Remove o primeiro elemento \n");
        			*ppInicio = atual->pProx;
                	atual->pProx = NULL;
				}
			}
    	}
		else
		{
			atual = anterior->pProx;

    		printf("Remove elemento meio ou ultimo \n");
    		anterior->pProx = atual->pProx; 
            atual->pProx = NULL;
		}
    }
	
	return atual;
}

int main()
{
    tLista* pInicio = NULL;
	
    int opcao;
    int id;
    char nome[30];
    float valor;
	
    do 
    {
     	printf("\n");
        printf("1-Percorrer \n");
        printf("2-Buscar Maior ID \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no pInicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
        printf("0-Sair \n");
		
        printf("Qual sua opcao? ");
		fflush(stdin);
        scanf("%d", &opcao);
        printf("\n");
		
        switch(opcao)
        {
            case 1: printf("PERCORRER LISTA \n");
                    percorrer(pInicio);
                    break;
					
    		case 2: printf("OBTER MAIOR ID \n");
                    int maiorID = getProxID(pInicio);
                    printf("Maior ID = %d \n", maiorID);
                    break;
					
			case 3: printf("BUSCAR ATUAL \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    tLista *resultBusca = buscar(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                        printf("Valor: %s \n", resultBusca->valor);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;
					
			case 4: printf("BUSCAR ANTERIOR \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    resultBusca = buscarAnterior(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                        printf("Valor: %s \n", resultBusca->valor);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;
					
            case 5: printf("INSERIR no pInicio \n");
                    printf("Digite o nome do novo individuo: ");
                    scanf("%s", &nome);
                    printf("Digite o valor do novo individuo: ");
                    scanf("%f", &valor);
                    inserirInicio(&pInicio, nome);
                    break;
            		
            case 6: printf("INSERIR no FIM \n");
                    printf("Digite o nome do novo individuo: ");
                    scanf("%s", &nome);
                    printf("Digite o valor do novo individuo: ");
                    scanf("%f", &valor);
                    inserirFim(&pInicio, nome);
                    break;
					
            case 7: printf("INSERIR (depois de ...) \n");
					printf("Digite o nome do novo individuo: ");
                    scanf("%s", &nome);
                    printf("Digite o valor do novo individuo: ");
                    scanf("%f", &valor);
                    inserirDepoisDe(pInicio, nome, id);
                    break;
					
            case 8: printf("REMOVER \n");
					printf("Qual a chave a ser removida? ");
                    scanf("%d", &id);
                    tLista* resultRemocao = remover(&pInicio, id); 
                    printf("resultRemocao = %d \n", resultRemocao);
                    if(resultRemocao != NULL) {
	        			printf("Matr: %d\n",  resultRemocao->id);
	        			printf("Nome: %s\n",  resultRemocao->nome);
	        			printf("Valor: %d\n",  resultRemocao->valor);
	        			printf("pProx: %d\n", resultRemocao->pProx);
                        free(resultRemocao);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;
					
            case 0: printf("SAINDO... \n");
                    break;
					
            default: printf("Valor invalido \n");
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
