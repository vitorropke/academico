#include <iostream> //Inclusão da biblioteca 'iostream' que controla a leitura e gravação para fluxos padrão
#include <math.h> //Inclusão da biblioteca 'math.h' para realizar operações de potenciação e radiciação
#include "concurso.h" //Inclusão do cabeçalho 'concurso' que possui os protótipos e registros

int numeroDeMinutos(horario inicio, horario fim) //Declaração da função 'numeroDeMinutos' de tipo inteiro que recebe dois registros e retorna o resultado da operacao
{
	return sqrt(pow((inicio.hora * 60 + inicio.minuto) - (fim.hora * 60 + fim.minuto),2)); //Retorno do número de minutos na diferença do horário inicial e final
}

struct estatistica mediaDasCoisas(questoes vetorQuestoes[], int tamanhoDoVetor, int indiceInicial, int tamanhoDoPasso) //Função-registro 'mediaDasCoisas' que recebe quatro parâmetros e retorna um registro
{
	struct estatistica dados = { 0 }; //Declaração de uma variável de um registro e inserção de valor inicial
	float somaDificuldade = 0, somaMinutos = 0; //Declaração de uma variável de tipo float com inserção de valor inicial

	for (int i = indiceInicial; i < tamanhoDoVetor; i += tamanhoDoPasso) //Laco de repetição que possui condição de início determinado pela variável 'indice inicial' e número de loops que vem do parâmetro da função chamado 'tamanhoDoVetor' e passo determinado pela variável 'tamanhoDoPasso'
	{
		somaDificuldade += vetorQuestoes->dificuldade; //Fornecimento de valor a uma variável
		somaMinutos += numeroDeMinutos(vetorQuestoes->inicio, vetorQuestoes->fim); //Fornecimento de valor a uma variável
	}

	dados.dificuldadeMedia = somaDificuldade / tamanhoDoVetor; //Cálculo da media de uma variável de registro
	dados.tempoMedio = somaMinutos / tamanhoDoVetor; //Cálculo da media de uma variável de registro

	return(dados); //Retorno da função
}

void imprimirSeparadores(char simbolo, int numeroDeSimbolos) //Função 'imprimirSeparadores' que possui dois valores como parâmetros e retorna nada
{
	for (int i = 0; i < numeroDeSimbolos; ++i) //Laco de repetição que possui condição de início 0 e número de loops que vem do parâmetro da função e passo 1
		std::cout << simbolo; //Imprime o valor que vem do parâmetro da função
}