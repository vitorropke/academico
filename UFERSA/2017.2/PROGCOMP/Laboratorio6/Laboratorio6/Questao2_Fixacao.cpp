#include <iostream>
using namespace std;

#define PRECOPAO 0.30
#define PRECOPASTEL 0.33

int main()
{
	int quantidadePao, quantidadePastel;

	cout << "Digite quantos p�es desejas: ";
	cin >> quantidadePao;
	cout << "Digite quantos past�is desejas: ";
	cin >> quantidadePastel;
	cout << "O pre�o total � R$" << PRECOPAO * quantidadePao + PRECOPASTEL * quantidadePastel << '\n';

	system("pause");
	return 0;
}