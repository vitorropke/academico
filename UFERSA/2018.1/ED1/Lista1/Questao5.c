#include <stdio.h>

int main()
{
	int numero1, numero2, numero3;
	
	printf("Digite um numero: ");
	scanf("%d", &numero1);
	printf("Digite outro numero: ");
	scanf("%d", &numero2);
	printf("Digite outro numero: ");
	scanf("%d", &numero3);
	
	printf("\nMedia = %.2lf\n", ((double)numero1 + (double)numero2 + (double)numero3) / 3);
	
	return 0;
}
