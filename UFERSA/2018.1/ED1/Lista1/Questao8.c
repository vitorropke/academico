#include <stdio.h>

int main()
{
	double numero1, numero2;
	
	printf("Digite um numero: ");
	scanf("%lf", &numero1);
	printf("Digite outro numero: ");
	scanf("%lf", &numero2);
	
	if(numero2 == 0)
	{
		printf("\nNao e possivel dividir por 0!\n");
	}
	else
	{
		printf("\nDivisao = %.2lf\n", numero1 / numero2);
	}
	
	return 0;
}
