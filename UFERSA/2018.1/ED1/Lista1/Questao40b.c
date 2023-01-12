#include <stdio.h>

int somatorioIntervaloLacoRepeticao(int, int);

int main()
{
	int numeroInicial, numeroFinal, resultado;
	
	printf("Digite um numero inicial: ");
	scanf("%d", &numeroInicial);
	printf("Digite um numero final: ");
	scanf("%d", &numeroFinal);
	
	resultado = somatorioIntervaloLacoRepeticao(numeroInicial, numeroFinal);
	
	printf("\n");
	printf("Somatoria = %d", resultado);
	
	return 0;
}

int somatorioIntervaloLacoRepeticao(int numeroInicial, int numeroFinal)
{
	int somatorio = 0, contador;
	
	for(contador = numeroInicial; contador <= numeroFinal; contador++)
	{
		somatorio += contador;
	}
	
	return somatorio;
}
