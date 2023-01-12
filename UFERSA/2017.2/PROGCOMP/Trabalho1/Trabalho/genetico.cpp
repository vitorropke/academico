#include <iostream> //Diretiva de pré-processamento para adicionar o arquivo 'iostream'
#include "binario.h" //Diretiva de pré-processamento para adicionar o arquivo 'binario.h'

using namespace std; //Diretiva simplificar o uso de códigos como std::cout, std::cin, etc...

bool avaliacao(int solucao) //Função 'avaliacao' que retorna variável booleana e recebe um valor inteiro
{
	int massaA, massaB, massaC, massaD, massaE, massaF, massaG, massaH, massaI, //Declaração de variáveis referentes ao peso de cada objeto
		massaJ, massaK, massaL, massaM, massaN, massaO, massaP, massaTotal;
	int valorA, valorB, valorC, valorD, valorE, valorF, valorG, valorH, valorI, //Declaração de variáveis referentes ao valor de cada objeto
		valorJ, valorK, valorL, valorM, valorN, valorO, valorP, valorTotal;

	massaA = 12; massaB = 3; massaC = 5; massaD = 4; massaE = 9; massaF = 1; massaG = 2; massaH = 3; //Fornecimento de valores às variáveis referentes ao peso de cada objeto
	massaI = 4; massaJ = 1; massaK = 2; massaL = 4; massaM = 5; massaN = 2; massaO = 4; massaP = 1;
	massaTotal = 0; //Fornecimento do valor inicial à massa somada de todos os objetos que estão na mochila
	valorA = 4; valorB = 4; valorC = 8; valorD = 10; valorE = 15; valorF = 3; valorG = 1; valorH = 1; //Fornecimento de valores às variáveis referentes ao valor de cada objeto
	valorI = 2; valorJ = 10; valorK = 20; valorL = 15; valorM = 10; valorN = 3; valorO = 4; valorP= 12;
	valorTotal = 0; //Fornecimento do valor inicial ao valor somado de todos os objetos que estão na mochila

	//As próximas 16 condicionais servem para incrementar às variáveis 'massaTotal' e 'valorTotal', valores referentes a cada objeto
	//Caso a condição seja verdadeira o número da massa e do valor em questão serão acrecidos às variáveis 'massaTotal' e 'valorTotal'
	//Se a condição não for verdadeira o número da massa e do valor não serão acrecidos às variáveis 'massaTotal' e 'valorTotal'
	//Em cada função testarBit serão recebidas os argumentos 'solução' e 'posição'.
	//A 'solução' terá um formato de 16 bits e a 'posição' irá deslocar um bit de verificação para averiguar a situação deste bit. Se está ligado ou desligado.
	//Tenho como exemplo a primeira condicional. A função 'testarBit(solucao, 15)'. O número 15 informa quantas posições o bit de verificação irá se deslocar.
	//A posição inicial deste bit é 1. Então ele será deslocado 15 posições na esquerda, portanto terminará na posição 16.
	//Se o bit da 'solução' for 1 o objeto desta posição será acrescentado às variáveis 'massaTotal' e 'valorTotal'
	//Se o bit da 'solução' for 0 o objeto desta posição não será acrescentado às variáveis 'massaTotal' e 'valorTotal'

	if (testarBit(solucao, 15)) //A condição é que se o resultado da função 'testarBit' for verdadeiro as instruções a seguir serão execultadas
	{
		massaTotal = massaTotal + massaA; //Se a condição for verdadeira a variável 'massaTotal' receberá como incremento o valor de 'massaA'
		valorTotal = valorTotal + valorA; //Se a condição for verdadeira a variável 'valorTotal' receberá como incremento o valor de 'valorA'
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
	
	cout << "$"; //Imprime o símbolo '$'
	cout << left; cout.width(3); cout << valorTotal; //Imprime na tela o 'valorTotal' alinhado à esquerda
	cout << " - ";
	cout << right; cout.width(2); cout << massaTotal << "Kg"; //Imprime na tela a 'massaTotal' e Kg alinhado à direita
	cout << " - "; //Imprime um traço
	
	if (massaTotal <= 20) //Condicional indicando se o valor da variável 'massaTotal' for menor ou igual a 20 que é o peso da mochila, deve retornar verdadeiro ou falso
		return true; //Se o valor da variável 'massaTotal' for menor que 20 o retorno é true(verdadeiro)
	else //Se o valor da variável 'massaTotal' for maior que 20
		return false; //O retorno será false(falso)
}

int cruzamentoPontoUnico(int solucao1, int solucao2) //Função 'cruzamentoPontoUnico' que retorna variável inteira e recebe dois valores inteiros
{
	return orBinario(bitsAltos(solucao1), bitsBaixos(solucao2)); //Retornando o resultado da operação entre bitsAltos(solucao1) OU bitsBaixos(solucao2)
}

int cruzamentoAritmetico(int solucao1, int solucao2) //Função 'cruzamentoAritmetico' que retorna variável inteira e recebe dois valores inteiros
{
	return andBinario(solucao1, solucao2); //Retornando o resultado da operação entre solucao1 E solucao2
}

int mutacaoSimples(int solucao) //Função 'mutacaoSimples' que retorna variável inteira e recebe um valor inteiro
{
	if (testarBit(solucao, 9))
		return desligarBit(solucao, 9); //Retornando o resultado da função desligarBit(solucao, 9), onde 'solucao' é o valor a ser modificado e 9 é o número de casas que o bit de verificação deve se deslocar até desligar o bit
	else
		return ligarBit(solucao, 9); //Retornando o resultado da função ligarBit(solucao, 9), onde 'solucao' é o valor a ser modificado e 9 é o número de casas que o bit de verificação deve se deslocar até ligar o bit
}

int mutacaoDupla(int solucao) //Função 'mutacaoDupla' que retorna variável inteira e recebe um valor inteiro
{
	if (testarBit(solucao, 12))
	{
		solucao = desligarBit(solucao, 12); //Retornando o resultado da função desligarBit(solucao, 12), onde 'solucao' é o valor a ser modificado e 12 é o número de casas que o bit de verificação deve se deslocar até desligar o bit
		if (testarBit(solucao, 3))
			return desligarBit(solucao, 3); //Retornando o resultado da função desligarBit(solucao, 3), onde 'solucao' é o valor a ser modificado e 3 é o número de casas que o bit de verificação deve se deslocar até desligar o bit
		else
			return ligarBit(solucao, 3); //Retornando o resultado da função ligarBit(solucao, 3), onde 'solucao' é o valor a ser modificado e 3 é o número de casas que o bit de verificação deve se deslocar até ligar o bit
	}
	else
	{
		solucao = ligarBit(solucao, 12); //Retornando o resultado da função ligarBit(solucao, 12), onde 'solucao' é o valor a ser modificado e 12 é o número de casas que o bit de verificação deve se deslocar até ligar o bit
		if (testarBit(solucao, 3))
			return desligarBit(solucao, 3); //Retornando o resultado da função desligarBit(solucao, 3), onde 'solucao' é o valor a ser modificado e 3 é o número de casas que o bit de verificação deve se deslocar até desligar o bit
		else
			return ligarBit(solucao, 3); //Retornando o resultado da função ligarBit(solucao, 3), onde 'solucao' é o valor a ser modificado e 3 é o número de casas que o bit de verificação deve se deslocar até ligar o bit
	}
}