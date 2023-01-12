#include <stdio.h>

int main()
{
	char frase[10], fraseInvertida[10];
	int contador, conReg = 0;
	
	printf("Digite uma frase: ");
	fgets(frase, 10, stdin);
	
	for(contador = strlen(frase) - 1; contador >= 0; contador--)
	{
		fraseInvertida[conReg] = frase[contador];
		conReg++;
	}
	
	printf("%s", fraseInvertida);
	
	return 0;
}
