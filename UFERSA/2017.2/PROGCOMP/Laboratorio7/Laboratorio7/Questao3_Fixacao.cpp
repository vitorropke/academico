#include <iostream>
using namespace std;

int BitsBaixos(int);

int main()
{
	int valor;

	cout << "Digite um valor inteiro: ";
	cin >> valor;
	cout << "Os 16 bits mais baixos desse valor correspondem ao número " << BitsBaixos(valor) << ".\n";

	system("pause");
	return 0;
}

int BitsBaixos(int numero)
{
	int mascara = 65535;

	numero = numero & mascara;

	return numero;
}