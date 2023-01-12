#include <iostream> //Diretiva de pré-processamento para adicionar o arquivo 'iostream'
#include "genetico.h" //Diretiva de pré-processamento para adicionar o arquivo 'genetico'
#include <Windows.h> //Diretiva de pré-processamento para adicionar o arquivo 'Windows'

using namespace std; //Diretiva simplificar o uso de códigos como std::cout, std::cin, etc...

int main() //Função 'main' principal que retorna variável inteira e recebe nada
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //Código para mudança de cor no texto

	int solucaoA, solucaoB, solucaoC, solucaoD, solucaoE, solucaoF;
	int novaSolucaoAposCruzamentoPontoUnico, novaSolucaoAposCruzamentoAritmetico, novaSolucaoAposMutacaoSimples, novaSolucaoAposMutacaoDupla; //Declaração de variáveis inteiras
	
	cout << "Entre com 6 solu" << char(135) << char(228) << "es iniciais (n" << char(163) << "meros entre 0 e 65535):" << endl; //Imprime o texto 'Entre com 6 soluções iniciais (números entre 0 e 65535):' com detalhe aos números definidos como caracteres. Serve para imprimir caracteres com acento.
	cin >> solucaoA >> solucaoB >> solucaoC >> solucaoD >> solucaoE >> solucaoF; //Comando para dar valores digitados pelo usuário às variáveis
	cout << endl; //Quebra de linha
	cout << "Resultado da Avalia" << char(135) << char(198) << "o" << endl; //Imprime o texto 'Resultado da Avaliação' com detalhe aos números definidos como caracteres. Serve para imprimir caracteres com acento.
	cout << "------------------------" << endl;
	
	//As próximas 6 condicionais servem para imprimir as 6 soluções diferentes informadas pelo usuário com suas determinadas informações adicionais
	//como massa total, valor total e se a situação pode ser aceita ou não(Se o valor total da massa é menor que 20)

	cout << right; cout.width(5); cout << solucaoA; //Código para formatação de texto, alinhado à esquerda e com 5 espaços
	cout << " - ";
	if (avaliacao(solucaoA)) //Condicional da função de avaliação 
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //Código para mudança de cor para verde
		cout << "OK" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); //Código para mudança de cor para vermelho
		cout << "X" << endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //Código para mudança de cor para branco

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

	novaSolucaoAposCruzamentoPontoUnico = cruzamentoPontoUnico(solucaoA, solucaoB); //Atribuição de valor a uma variável
	novaSolucaoAposCruzamentoAritmetico = cruzamentoAritmetico(solucaoC, solucaoD); //Atribuição de valor a uma variável
	novaSolucaoAposMutacaoSimples = mutacaoSimples(solucaoE); //Atribuição de valor a uma variável
	novaSolucaoAposMutacaoDupla = mutacaoDupla(solucaoF); //Atribuição de valor a uma variável

	//As próximas 4 condicionais servem para imprimir as novas soluções após a aplicação dos operadores genéticos

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
	return 0; //Retorno da função main
}