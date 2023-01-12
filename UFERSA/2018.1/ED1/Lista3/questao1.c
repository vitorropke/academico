#include <stdio.h>

typedef struct sElemento{
	int id;
	char nome[30];
} tElemento;

int buscaLinear(tElemento*, int, int);

int main()
{
	int tamanho = 100, contador, contadorString, chave;
	tElemento estruturaEstatica[tamanho];
    
	for (contador = 0; contador < tamanho; contador++)
	{
		estruturaEstatica[contador].id = rand() % 100; //Valores aleatórios na estrutura estática
		
		for(contadorString = 0; contadorString < 30; contadorString++)
			estruturaEstatica[contador].nome[contadorString] = rand() % 100; //Letras aleatórias na estrutura estática
	}
	
	printf("Digite qual valor voce deseja procurar: ");
	scanf("%d",&chave);
	
	if ( buscaLinear(estruturaEstatica, chave , tamanho) != -1 )
		printf("\nValor encontrado!\n");
	else
		printf("\nValor nao encontrado!\n");
	
	return 0;
}

int buscaLinear(tElemento *estruturaEstatica, int chave , int tamanho)
{
	int contador;
	
	for ( contador = 0; contador < tamanho; contador++ )
	{
		if ( chave == estruturaEstatica[contador].id ){
			printf("\nID: %d\n", estruturaEstatica[contador].id);
			printf("Nome: %s\n", estruturaEstatica[contador].nome);
			
			return contador;
		}
	}
	
	return -1;
}
