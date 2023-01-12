#include <iostream>
using namespace std;

char codificar(char);
char decodificar(char);

int main()
{
	char ch;
	int resposta;

	cout << "Digite uma letra: ";
	cin >> ch;
	cout << "Deseja codificar ou decodificar? Entre com 1 para codificar e 0 para decodificar: ";
	cin >> resposta;

	if (resposta == true)
		cout << "Codificando: " << codificar(ch) << '\n';
	else
		cout << "Decodificando: " << decodificar(ch) << '\n';

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