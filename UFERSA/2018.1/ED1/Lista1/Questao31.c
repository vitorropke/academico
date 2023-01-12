#include <stdio.h>

int main()
{
	char frase[10];
	int contador;
	
	printf("Digite uma frase: ");
	fgets(frase, 10, stdin);
	
	for(contador = strlen(frase); contador >= 0; contador--)
	{
		printf("%c", frase[contador]);
	}
	
	return 0;
}
