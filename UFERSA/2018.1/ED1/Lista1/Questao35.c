#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE* arquivo = fopen("arquivo.csv", "a+");
	char produto[30];
	float valor;
	
	if(arquivo == NULL) {
	    printf("ERRO: nao foi possivel abrir o arquivo \n");
		return 1;
    }
    
    while(fscanf(arquivo, "%s	%.2f\n", &produto, &valor) != EOF)
    {
		printf("produto=%s	valor=%.2f \n", produto, valor);
    }
    
    fprintf(arquivo, "%s	%.2f\n", "arroz", 7.5);
	fprintf(arquivo, "%s	%.2f\n", "feijão", 15.3);
    
	fclose(arquivo);
	
	return 0;
}
