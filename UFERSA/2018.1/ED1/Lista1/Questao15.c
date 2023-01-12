#include <stdio.h>

int main()
{
	int numero;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &numero);
	
	if((numero >= 1) && (numero <= 5))
	{
		switch(numero)
		{
			case 1:
				printf("Um");
				break;
			case 2:
				printf("Dois");
				break;
			case 3:
				printf("Tres");
				break;
			case 4:
				printf("Quatro");
				break;
			case 5:
				printf("Cinco");
				break;
		}
	}
	else
	{
		printf("valor invalido");
	}
	
	return 0;
}
