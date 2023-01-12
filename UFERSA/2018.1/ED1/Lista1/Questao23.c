#include <stdio.h>
#include <math.h>

int resultadoAnterior(int);

int main()
{
	int numero, expoente, fatorial = 1, contador, resultado, loop = 0, opcao;
	
	do
	{
		printf("\nMenu de opcoes\n");
		printf("1 - Potenciacao\n");
		printf("2 - raiz quadrada\n");
		printf("3 - fatorial\n");
		printf("0 - sair\n");
		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);
		
		if(loop > 0)
		{
			resultado = resultadoAnterior(resultado);
			
			printf("\nResultado anterior = %d\n", resultado);
		}
		
		switch(opcao)
		{
			case 0:
				printf("\nTchau\n");
			break;
			
			case 1:
				printf("\nDigite um numero: ");
				scanf("%d", &numero);
				printf("Digite o expoente do numero: ");
				scanf("%d", &expoente);
				
				resultado = pow(numero, expoente);
				
				printf("\n%d\n", resultado);
			break;
			
			case 2:
				printf("\nDigite um numero: ");
				scanf("%d", &numero);
				
				resultado = sqrt(numero);
				
				printf("\n%d\n", resultado);
			break;
			
			case 3:
				printf("\nDigite um numero: ");
				scanf("%d", &numero);
				
				for(contador = 1; contador <= numero; contador++)
				{
					fatorial = fatorial * contador;
				}
				
				resultado = fatorial;
				fatorial = 1;
				
				printf("\n%d\n", resultado);
			break;
			
			default:
				printf("\nNao sei\n");
		}
		loop++;
	}while(opcao != 0);
	
	return 0;
}

int resultadoAnterior(int resultado)
{
	return resultado;
}
