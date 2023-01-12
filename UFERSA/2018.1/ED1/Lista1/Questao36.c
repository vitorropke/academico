#include <stdio.h>
#include <string.h>

typedef struct sString{
	char palavraStruct[30];
} tString;

int main()
{
	tString dicionario[10];
	char frase[] = "estude muito sempre sempre estude", palavras[30], c;
	int contador, tamanhoDicionario = 0, palavraAtual = 0, size = strlen(frase);
	
	for(contador = 0; contador <= size; contador++)
	{
		c = frase[contador];
		printf("%c ", c);
		
		if(c != ' ' && c != '\0')
		{
			palavras[palavraAtual] = c;
			palavraAtual++;
		}
		else
		{
			palavras[palavraAtual] = '\0';
			strcpy(dicionario[tamanhoDicionario].palavraStruct, palavras);
			palavraAtual = 0;
			tamanhoDicionario++;
		}
	}
	
	printf("\n\n");
	
	for(contador = 0; contador <= tamanhoDicionario - 1; contador++)
	{
		printf("[%s] ", dicionario[contador].palavraStruct);
	}
	
	return 0;
}
