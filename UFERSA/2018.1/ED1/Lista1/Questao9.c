#include <stdio.h>

int main()
{
	double massa, altura;
	
	printf("Digite sua massa em quilogramas: ");
	scanf("%lf", &massa);
	printf("Digite sua altura em metros: ");
	scanf("%lf", &altura);
	
	printf("\nIMC = %.2lf\n", massa / (altura * altura));
	
	return 0;
}
