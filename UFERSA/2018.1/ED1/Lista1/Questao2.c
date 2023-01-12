#include <stdio.h>

int main()
{
	int idade = 18;
	double altura = 1.62;
	char primeiraLetra = 'v';
	char nomeCompleto[21] = "Vitor Oliveira Ropke";
	
	printf("Idade = %d\n", idade);
	printf("Altura = %.2lf\n", altura);
	printf("Primeira letra = %c\n", primeiraLetra);
	printf("Nome completo = %s\n", nomeCompleto);
	
	return 0;
}
