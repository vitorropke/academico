#include <iostream> //Inclus�o da biblioteca 'iostream' que controla a leitura e grava��o para fluxos padr�o
#include <math.h> //Inclus�o da biblioteca 'math.h' para realizar opera��es de potencia��o e radicia��o
#include "concurso.h" //Inclus�o do cabe�alho 'concurso' que possui os prot�tipos e registros

int numeroDeMinutos(horario inicio, horario fim) //Declara��o da fun��o 'numeroDeMinutos' de tipo inteiro que recebe dois registros e retorna o resultado da operacao
{
	return sqrt(pow((inicio.hora * 60 + inicio.minuto) - (fim.hora * 60 + fim.minuto),2)); //Retorno do n�mero de minutos na diferen�a do hor�rio inicial e final
}

struct estatistica mediaDasCoisas(questoes vetorQuestoes[], int tamanhoDoVetor, int indiceInicial, int tamanhoDoPasso) //Fun��o-registro 'mediaDasCoisas' que recebe quatro par�metros e retorna um registro
{
	struct estatistica dados = { 0 }; //Declara��o de uma vari�vel de um registro e inser��o de valor inicial
	float somaDificuldade = 0, somaMinutos = 0; //Declara��o de uma vari�vel de tipo float com inser��o de valor inicial

	for (int i = indiceInicial; i < tamanhoDoVetor; i += tamanhoDoPasso) //Laco de repeti��o que possui condi��o de in�cio determinado pela vari�vel 'indice inicial' e n�mero de loops que vem do par�metro da fun��o chamado 'tamanhoDoVetor' e passo determinado pela vari�vel 'tamanhoDoPasso'
	{
		somaDificuldade += vetorQuestoes->dificuldade; //Fornecimento de valor a uma vari�vel
		somaMinutos += numeroDeMinutos(vetorQuestoes->inicio, vetorQuestoes->fim); //Fornecimento de valor a uma vari�vel
	}

	dados.dificuldadeMedia = somaDificuldade / tamanhoDoVetor; //C�lculo da media de uma vari�vel de registro
	dados.tempoMedio = somaMinutos / tamanhoDoVetor; //C�lculo da media de uma vari�vel de registro

	return(dados); //Retorno da fun��o
}

void imprimirSeparadores(char simbolo, int numeroDeSimbolos) //Fun��o 'imprimirSeparadores' que possui dois valores como par�metros e retorna nada
{
	for (int i = 0; i < numeroDeSimbolos; ++i) //Laco de repeti��o que possui condi��o de in�cio 0 e n�mero de loops que vem do par�metro da fun��o e passo 1
		std::cout << simbolo; //Imprime o valor que vem do par�metro da fun��o
}