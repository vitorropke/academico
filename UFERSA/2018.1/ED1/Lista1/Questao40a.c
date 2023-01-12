#include <stdio.h>

int somatorioIntervaloRecursividade(int, int);

int main()
{
	int numeroInicial, numeroFinal, resultado;
	
	printf("Digite um numero inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero final: ");
	scanf("%d", &numeroFinal);
	
	resultado = somatorioIntervaloRecursividade(numeroInicial, numeroFinal);
	
	printf("\n");
	printf("Somatoria = %d", resultado);
	
	return 0;
}

int somatorioIntervaloRecursividade(int numeroInicial, int numeroFinal)
{
	if(numeroInicial > numeroFinal)
	{
		return 0;
	}
	else
	{
		return numeroInicial + somatorioIntervaloRecursividade(numeroInicial + 1, numeroFinal);
	}
}
