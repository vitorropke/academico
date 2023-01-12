#include <iostream>
using namespace std;

char codificar(char);
char decodificar(char);

int main()
{
	char caractere;

	cout << "Digite um caractere qualquer: ";
	cin >> caractere;
	cout << "Codificando: " << codificar(caractere) << '\n'
		<< "Decodificando: " << decodificar(caractere) << '\n';

	system("pause");
	return 0;
}

char codificar(char caractere)
{
	return caractere + 3;
}

char decodificar(char caractere)
{
	return caractere - 3;
}