#include <stdio.h>

int main()
{
	double raio;
	
	printf("Digite o raio do circulo: ");
	scanf("%lf", &raio);
	
	if(raio >= 0)
	{
		printf("\nArea do circulo = %.2lf\n", 3.1415926535898 * raio * raio);
	}
	else
	{
		printf("\nSem circulo\n");
	}
	
	return 0;
}
