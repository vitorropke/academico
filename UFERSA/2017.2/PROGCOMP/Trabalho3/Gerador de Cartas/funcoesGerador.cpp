#include <iostream>

using namespace std;

void imprimirTraco(int quantidadeDeTraco, char traco) //Fun��o para imprimir tra�os
{
	for (int x = 0; x < quantidadeDeTraco; x++)
		cout << traco;
}

void imprimirMenuDeOpcoes(void) //Fun��o para imprimir o menu de op��es
{
	cout << "Gerador de Cartas" << endl;
	imprimirTraco(17, '-');
	cout << endl;
	cout << "1) Cadastrar" << endl;
	cout << "2) Alterar" << endl;
	cout << "3) Excluir" << endl;
	cout << "4) Listar" << endl;
	cout << "5) Sair" << endl;
}