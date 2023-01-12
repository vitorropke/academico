#include <stdio.h>

int main()
{
	int numero1, numero2;
	
	printf("Digite um numero: ");
	scanf("%d", &numero1);
	printf("Digite outro numero: ");
	scanf("%d", &numero2);
	
	printf("\nSoma = %d\n", numero1 + numero2);
	printf("Subtracao = %d\n", numero1 - numero2);
	printf("Multiplicacao = %d\n", numero1 * numero2);
	printf("Divisao = %.2lf\n", (double)numero1 / (double)numero2);
	printf("Resto = %d\n", numero1 % numero2);
	
	return 0;
}
