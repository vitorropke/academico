#include <stdio.h>

int main()
{
	double numero1, numero2, numero3;
	
	printf("Digite um numero: ");
	scanf("%lf", &numero1);
	printf("Digite outro numero: ");
	scanf("%lf", &numero2);
	printf("Digite outro numero: ");
	scanf("%lf", &numero3);
	
	printf("\nMedia = %.2lf\n", (numero1 + numero2 + numero3) / 3);
	
	return 0;
}
