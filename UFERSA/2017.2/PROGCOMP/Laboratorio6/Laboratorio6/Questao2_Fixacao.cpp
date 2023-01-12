#include <iostream>
using namespace std;

#define PRECOPAO 0.30
#define PRECOPASTEL 0.33

int main()
{
	int quantidadePao, quantidadePastel;

	cout << "Digite quantos pães desejas: ";
	cin >> quantidadePao;
	cout << "Digite quantos pastéis desejas: ";
	cin >> quantidadePastel;
	cout << "O preço total é R$" << PRECOPAO * quantidadePao + PRECOPASTEL * quantidadePastel << '\n';

	system("pause");
	return 0;
}