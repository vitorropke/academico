#include <iostream> //Diretiva de pr�-processamento para adicionar o arquivo 'iostream'
#include "binario.h" //Diretiva de pr�-processamento para adicionar o arquivo 'binario.h'

using namespace std; //Diretiva simplificar o uso de c�digos como std::cout, std::cin, etc...

bool avaliacao(int solucao) //Fun��o 'avaliacao' que retorna vari�vel booleana e recebe um valor inteiro
{
	int massaA, massaB, massaC, massaD, massaE, massaF, massaG, massaH, massaI, //Declara��o de vari�veis referentes ao peso de cada objeto
		massaJ, massaK, massaL, massaM, massaN, massaO, massaP, massaTotal;
	int valorA, valorB, valorC, valorD, valorE, valorF, valorG, valorH, valorI, //Declara��o de vari�veis referentes ao valor de cada objeto
		valorJ, valorK, valorL, valorM, valorN, valorO, valorP, valorTotal;

	massaA = 12; massaB = 3; massaC = 5; massaD = 4; massaE = 9; massaF = 1; massaG = 2; massaH = 3; //Fornecimento de valores �s vari�veis referentes ao peso de cada objeto
	massaI = 4; massaJ = 1; massaK = 2; massaL = 4; massaM = 5; massaN = 2; massaO = 4; massaP = 1;
	massaTotal = 0; //Fornecimento do valor inicial � massa somada de todos os objetos que est�o na mochila
	valorA = 4; valorB = 4; valorC = 8; valorD = 10; valorE = 15; valorF = 3; valorG = 1; valorH = 1; //Fornecimento de valores �s vari�veis referentes ao valor de cada objeto
	valorI = 2; valorJ = 10; valorK = 20; valorL = 15; valorM = 10; valorN = 3; valorO = 4; valorP= 12;
	valorTotal = 0; //Fornecimento do valor inicial ao valor somado de todos os objetos que est�o na mochila

	//As pr�ximas 16 condicionais servem para incrementar �s vari�veis 'massaTotal' e 'valorTotal', valores referentes a cada objeto
	//Caso a condi��o seja verdadeira o n�mero da massa e do valor em quest�o ser�o acrecidos �s vari�veis 'massaTotal' e 'valorTotal'
	//Se a condi��o n�o for verdadeira o n�mero da massa e do valor n�o ser�o acrecidos �s vari�veis 'massaTotal' e 'valorTotal'
	//Em cada fun��o testarBit ser�o recebidas os argumentos 'solu��o' e 'posi��o'.
	//A 'solu��o' ter� um formato de 16 bits e a 'posi��o' ir� deslocar um bit de verifica��o para averiguar a situa��o deste bit. Se est� ligado ou desligado.
	//Tenho como exemplo a primeira condicional. A fun��o 'testarBit(solucao, 15)'. O n�mero 15 informa quantas posi��es o bit de verifica��o ir� se deslocar.
	//A posi��o inicial deste bit � 1. Ent�o ele ser� deslocado 15 posi��es na esquerda, portanto terminar� na posi��o 16.
	//Se o bit da 'solu��o' for 1 o objeto desta posi��o ser� acrescentado �s vari�veis 'massaTotal' e 'valorTotal'
	//Se o bit da 'solu��o' for 0 o objeto desta posi��o n�o ser� acrescentado �s vari�veis 'massaTotal' e 'valorTotal'

	if (testarBit(solucao, 15)) //A condi��o � que se o resultado da fun��o 'testarBit' for verdadeiro as instru��es a seguir ser�o execultadas
	{
		massaTotal = massaTotal + massaA; //Se a condi��o for verdadeira a vari�vel 'massaTotal' receber� como incremento o valor de 'massaA'
		valorTotal = valorTotal + valorA; //Se a condi��o for verdadeira a vari�vel 'valorTotal' receber� como incremento o valor de 'valorA'
	}

	if (testarBit(solucao, 14))
	{
		massaTotal = massaTotal + massaB;
		valorTotal = valorTotal + valorB;
	}

	if (testarBit(solucao, 13))
	{
		massaTotal = massaTotal + massaC;
		valorTotal = valorTotal + valorC;
	}

	if (testarBit(solucao, 12))
	{
		massaTotal = massaTotal + massaD;
		valorTotal = valorTotal + valorD;
	}

	if (testarBit(solucao, 11))
	{
		massaTotal = massaTotal + massaE;
		valorTotal = valorTotal + valorE;
	}

	if (testarBit(solucao, 10))
	{
		massaTotal = massaTotal + massaF;
		valorTotal = valorTotal + valorF;
	}

	if (testarBit(solucao, 9))
	{
		massaTotal = massaTotal + massaG;
		valorTotal = valorTotal + valorG;
	}

	if (testarBit(solucao, 8))
	{
		massaTotal = massaTotal + massaH;
		valorTotal = valorTotal + valorH;
	}

	if (testarBit(solucao, 7))
	{
		massaTotal = massaTotal + massaI;
		valorTotal = valorTotal + valorI;
	}

	if (testarBit(solucao, 6))
	{
		massaTotal = massaTotal + massaJ;
		valorTotal = valorTotal + valorJ;
	}

	if (testarBit(solucao, 5))
	{
		massaTotal = massaTotal + massaK;
		valorTotal = valorTotal + valorK;
	}

	if (testarBit(solucao, 4))
	{
		massaTotal = massaTotal + massaL;
		valorTotal = valorTotal + valorL;
	}

	if (testarBit(solucao, 3))
	{
		massaTotal = massaTotal + massaM;
		valorTotal = valorTotal + valorM;
	}

	if (testarBit(solucao, 2))
	{
		massaTotal = massaTotal + massaN;
		valorTotal = valorTotal + valorN;
	}

	if (testarBit(solucao, 1))
	{
		massaTotal = massaTotal + massaO;
		valorTotal = valorTotal + valorO;
	}

	if (testarBit(solucao, 0))
	{
		massaTotal = massaTotal + massaP;
		valorTotal = valorTotal + valorP;
	}
	
	cout << "$"; //Imprime o s�mbolo '$'
	cout << left; cout.width(3); cout << valorTotal; //Imprime na tela o 'valorTotal' alinhado � esquerda
	cout << " - ";
	cout << right; cout.width(2); cout << massaTotal << "Kg"; //Imprime na tela a 'massaTotal' e Kg alinhado � direita
	cout << " - "; //Imprime um tra�o
	
	if (massaTotal <= 20) //Condicional indicando se o valor da vari�vel 'massaTotal' for menor ou igual a 20 que � o peso da mochila, deve retornar verdadeiro ou falso
		return true; //Se o valor da vari�vel 'massaTotal' for menor que 20 o retorno � true(verdadeiro)
	else //Se o valor da vari�vel 'massaTotal' for maior que 20
		return false; //O retorno ser� false(falso)
}

int cruzamentoPontoUnico(int solucao1, int solucao2) //Fun��o 'cruzamentoPontoUnico' que retorna vari�vel inteira e recebe dois valores inteiros
{
	return orBinario(bitsAltos(solucao1), bitsBaixos(solucao2)); //Retornando o resultado da opera��o entre bitsAltos(solucao1) OU bitsBaixos(solucao2)
}

int cruzamentoAritmetico(int solucao1, int solucao2) //Fun��o 'cruzamentoAritmetico' que retorna vari�vel inteira e recebe dois valores inteiros
{
	return andBinario(solucao1, solucao2); //Retornando o resultado da opera��o entre solucao1 E solucao2
}

int mutacaoSimples(int solucao) //Fun��o 'mutacaoSimples' que retorna vari�vel inteira e recebe um valor inteiro
{
	if (testarBit(solucao, 9))
		return desligarBit(solucao, 9); //Retornando o resultado da fun��o desligarBit(solucao, 9), onde 'solucao' � o valor a ser modificado e 9 � o n�mero de casas que o bit de verifica��o deve se deslocar at� desligar o bit
	else
		return ligarBit(solucao, 9); //Retornando o resultado da fun��o ligarBit(solucao, 9), onde 'solucao' � o valor a ser modificado e 9 � o n�mero de casas que o bit de verifica��o deve se deslocar at� ligar o bit
}

int mutacaoDupla(int solucao) //Fun��o 'mutacaoDupla' que retorna vari�vel inteira e recebe um valor inteiro
{
	if (testarBit(solucao, 12))
	{
		solucao = desligarBit(solucao, 12); //Retornando o resultado da fun��o desligarBit(solucao, 12), onde 'solucao' � o valor a ser modificado e 12 � o n�mero de casas que o bit de verifica��o deve se deslocar at� desligar o bit
		if (testarBit(solucao, 3))
			return desligarBit(solucao, 3); //Retornando o resultado da fun��o desligarBit(solucao, 3), onde 'solucao' � o valor a ser modificado e 3 � o n�mero de casas que o bit de verifica��o deve se deslocar at� desligar o bit
		else
			return ligarBit(solucao, 3); //Retornando o resultado da fun��o ligarBit(solucao, 3), onde 'solucao' � o valor a ser modificado e 3 � o n�mero de casas que o bit de verifica��o deve se deslocar at� ligar o bit
	}
	else
	{
		solucao = ligarBit(solucao, 12); //Retornando o resultado da fun��o ligarBit(solucao, 12), onde 'solucao' � o valor a ser modificado e 12 � o n�mero de casas que o bit de verifica��o deve se deslocar at� ligar o bit
		if (testarBit(solucao, 3))
			return desligarBit(solucao, 3); //Retornando o resultado da fun��o desligarBit(solucao, 3), onde 'solucao' � o valor a ser modificado e 3 � o n�mero de casas que o bit de verifica��o deve se deslocar at� desligar o bit
		else
			return ligarBit(solucao, 3); //Retornando o resultado da fun��o ligarBit(solucao, 3), onde 'solucao' � o valor a ser modificado e 3 � o n�mero de casas que o bit de verifica��o deve se deslocar at� ligar o bit
	}
}