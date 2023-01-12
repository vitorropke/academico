#include <iostream> //Diretiva de pr�-processamento para adicionar o arquivo 'iostream'
#include "genetico.h" //Diretiva de pr�-processamento para adicionar o arquivo 'genetico'
#include <Windows.h> //Diretiva de pr�-processamento para adicionar o arquivo 'Windows'

using namespace std; //Diretiva simplificar o uso de c�digos como std::cout, std::cin, etc...

int main() //Fun��o 'main' principal que retorna vari�vel inteira e recebe nada
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //C�digo para mudan�a de cor no texto

	int solucaoA, solucaoB, solucaoC, solucaoD, solucaoE, solucaoF;
	int novaSolucaoAposCruzamentoPontoUnico, novaSolucaoAposCruzamentoAritmetico, novaSolucaoAposMutacaoSimples, novaSolucaoAposMutacaoDupla; //Declara��o de vari�veis inteiras
	
	cout << "Entre com 6 solu" << char(135) << char(228) << "es iniciais (n" << char(163) << "meros entre 0 e 65535):" << endl; //Imprime o texto 'Entre com 6 solu��es iniciais (n�meros entre 0 e 65535):' com detalhe aos n�meros definidos como caracteres. Serve para imprimir caracteres com acento.
	cin >> solucaoA >> solucaoB >> solucaoC >> solucaoD >> solucaoE >> solucaoF; //Comando para dar valores digitados pelo usu�rio �s vari�veis
	cout << endl; //Quebra de linha
	cout << "Resultado da Avalia" << char(135) << char(198) << "o" << endl; //Imprime o texto 'Resultado da Avalia��o' com detalhe aos n�meros definidos como caracteres. Serve para imprimir caracteres com acento.
	cout << "------------------------" << endl;
	
	//As pr�ximas 6 condicionais servem para imprimir as 6 solu��es diferentes informadas pelo usu�rio com suas determinadas informa��es adicionais
	//como massa total, valor total e se a situa��o pode ser aceita ou n�o(Se o valor total da massa � menor que 20)

	cout << right; cout.width(5); cout << solucaoA; //C�digo para formata��o de texto, alinhado � esquerda e com 5 espa�os
	cout << " - ";
	if (avaliacao(solucaoA)) //Condicional da fun��o de avalia��o 
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //C�digo para mudan�a de cor para verde
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); //C�digo para mudan�a de cor para vermelho
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //C�digo para mudan�a de cor para branco

	cout << right; cout.width(5); cout << solucaoB;
	cout << " - ";
	if (avaliacao(solucaoB))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << solucaoC;
	cout << " - ";
	if (avaliacao(solucaoC))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << solucaoD;
	cout << " - ";
	if (avaliacao(solucaoD))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << solucaoE;
	cout << " - ";
	if (avaliacao(solucaoE))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << solucaoF;
	cout << " - ";
	if (avaliacao(solucaoF))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "------------------------" << endl;

	novaSolucaoAposCruzamentoPontoUnico = cruzamentoPontoUnico(solucaoA, solucaoB); //Atribui��o de valor a uma vari�vel
	novaSolucaoAposCruzamentoAritmetico = cruzamentoAritmetico(solucaoC, solucaoD); //Atribui��o de valor a uma vari�vel
	novaSolucaoAposMutacaoSimples = mutacaoSimples(solucaoE); //Atribui��o de valor a uma vari�vel
	novaSolucaoAposMutacaoDupla = mutacaoDupla(solucaoF); //Atribui��o de valor a uma vari�vel

	//As pr�ximas 4 condicionais servem para imprimir as novas solu��es ap�s a aplica��o dos operadores gen�ticos

	cout << right; cout.width(5); cout << novaSolucaoAposCruzamentoPontoUnico;
	cout << " - ";
	if (avaliacao(novaSolucaoAposCruzamentoPontoUnico))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << novaSolucaoAposCruzamentoAritmetico;
	cout << " - ";
	if (avaliacao(novaSolucaoAposCruzamentoAritmetico))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << novaSolucaoAposMutacaoSimples;
	cout << " - ";
	if (avaliacao(novaSolucaoAposMutacaoSimples))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << right; cout.width(5); cout << novaSolucaoAposMutacaoDupla;
	cout << " - ";
	if (avaliacao(novaSolucaoAposMutacaoDupla))
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	system("pause>null"); //Comando para evitar que a janela se feche
	return 0; //Retorno da fun��o main
}