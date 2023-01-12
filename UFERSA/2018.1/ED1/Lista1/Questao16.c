#include <stdio.h>
#include <math.h>

double delta(double, double, double);
void calculoRaizes(double, double, double);

int main()
{
	double a, b, c;
	
	printf("Digite um valor para a: ");
	scanf("%lf", &a);
	printf("Digite um valor para b: ");
	scanf("%lf", &b);
	printf("Digite um valor para c: ");
	scanf("%lf", &c);
	
	calculoRaizes(a, b, c);
	
	return 0;
}

double delta(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

void calculoRaizes(double a, double b, double c)
{
	double raizPositiva = (-b + sqrt(delta(a, b, c))) / (2 * a);
	double raizNegativa = (-b - sqrt(delta(a, b, c))) / (2 * a);
	
	if(delta(a, b, c) > 0)
	{
		printf("\nPossui duas raizes\n");
		printf("\nX1 = %.2lf\n", raizPositiva);
		printf("X2 = %.2lf\n", raizNegativa);
	}
	else if(delta(a, b, c) == 0)
	{
		printf("\nPossui uma raiz\n");
		printf("\nX1 = %.2lf\n", raizPositiva);
	}
	else
	{
		printf("\nNao possui raizes\n");
	}
}
