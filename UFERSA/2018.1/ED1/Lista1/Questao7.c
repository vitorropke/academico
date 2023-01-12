#include <stdio.h>

int main()
{
	double precoDoRefrigerante = 1.5, precoDaFatiaDePizza = 3, taxaDoGarcom = 1.1, precoTotal;
	int quantidadeDeRefrigerantes, quantidadeDeFatias, quantidadeDePessoas;
	
	printf("Digite a quantidade de refrigerante que desejas: ");
	scanf("%d", &quantidadeDeRefrigerantes);
	printf("Digite a quantidade de fatias que desejas: ");
	scanf("%d", &quantidadeDeFatias);
	printf("Digite a quantidade de pessoas que existem na mesa: ");
	scanf("%d", &quantidadeDePessoas);
	
	precoTotal = quantidadeDeRefrigerantes * precoDoRefrigerante + quantidadeDeFatias * precoDaFatiaDePizza;
	
	printf("\nPreco total com taxa = %.2lf\n", precoTotal * taxaDoGarcom);
	printf("Preco total sem taxa = %.2lf\n", precoTotal);
	printf("Preco com taxa para cada pessoa= %.2lf\n", (precoTotal * taxaDoGarcom) / quantidadeDePessoas);
	
	return 0;
}
