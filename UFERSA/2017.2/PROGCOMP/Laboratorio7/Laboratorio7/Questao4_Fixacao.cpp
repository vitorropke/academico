#include <iostream>
using namespace std;

int BitsAltos(int);

int main()
{
	int valor;

	cout << "Digite um valor inteiro: ";
	cin >> valor;
	cout << "Os 16 bits mais altos desse valor correspondem ao número " << BitsAltos(valor) << ".\n";

	system("pause");
	return 0;
}

int BitsAltos(int numero)
{
	int mascara = 4294901760;

	numero = numero & mascara;
	numero = numero >> 16;

	return numero;
}