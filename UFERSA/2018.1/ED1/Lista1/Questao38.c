#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct sString{
	char palavraStruct[30];
	int repeticoes;
} tString;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE* arquivo = fopen("arquivo38.csv", "r");
	char frase[] = "estude muito sempre sempre estude", palavras[30], c;
	int contador, contadorI, contadorJ , tamanhoDicionario = 0, palavraAtual = 0, size = strlen(frase);
	
	if(arquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }
	
	while(fscanf(arquivo, "%c\n", &frase) != EOF) 		// IMPORTANTE!!! Usar %[^;] em vez de %s
    {		
		printf("frase=%s\n", frase);
		tamanhoDicionario+=1;
    }
    
    tString* dicionario = (tString*) calloc(tamanhoDicionario, sizeof(tString));
	
	fclose(arquivo);
	
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
	
	for(contadorI = 0; contadorI <= tamanhoDicionario - 1; contadorI++)
	{
		for(contadorJ = contadorI + 1; contadorJ <= tamanhoDicionario - 1; contadorJ++)
		{
			if(dicionario[contadorI].palavraStruct == dicionario[contadorJ].palavraStruct)
			{
				dicionario[contadorI].repeticoes += 1;
			}
		}
	}
	
	printf("\n\n");
	
	for(contador = 0; contador <= tamanhoDicionario - 1; contador++)
	{
		printf("[%s] [%d] ", dicionario[contador].palavraStruct, dicionario[contador].repeticoes);
	}
	
	return 0;
}
