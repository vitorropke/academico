#include <stdio.h>

int main()
{
	int idade;
	double altura;
	char primeiraLetra;
	char nomeCompleto[50];
	
	printf("Digite sua idade: ");
	scanf("%d", &idade);
	printf("Digite sua altura: ");
	scanf("%lf", &altura);
	fflush(stdin);
	printf("Digite a primeira letra do seu nome: ");
	scanf("%c", &primeiraLetra);
	fflush(stdin);
	printf("Digite seu nome completo: ");
	fgets(nomeCompleto, 50, stdin);
	
	printf("\nIdade = %d\n", idade);
	printf("Altura = %.2lf\n", altura);
	printf("Primeira letra = %c\n", primeiraLetra);
	printf("Nome completo = %s", nomeCompleto);
	
	return 0;
}
