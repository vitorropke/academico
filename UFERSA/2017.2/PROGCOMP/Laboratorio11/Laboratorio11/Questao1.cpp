#include <iostream>
using namespace std;

int main()
{
	const int tamanhoDoVetor = 10;
	char nome[tamanhoDoVetor], sobrenome[tamanhoDoVetor];

	cout << "Primeiro nome? ";
	cin >> nome;
	cout << "Segundo nome? ";
	cin >> sobrenome;
	cout << "Bom dia, " << nome << ' ' << sobrenome << ".\n"
		<< "Seja bem vindo " << nome[0] << sobrenome[0] << "!\n";

	system("pause");
	return 0;
}