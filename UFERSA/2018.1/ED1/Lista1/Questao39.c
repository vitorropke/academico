#include <stdio.h>

int fatorial(int);

int main()
{
	printf("\n%d\n", fatorial(5));
	
	return 0;
}

int fatorial(int numero)
{
	int fat = 0;
	
	if(numero == 0)
	{
		fat = 1;
	}
	else
	{
		fat = numero*fatorial(numero-1);
	}
	
	return fat;
}
