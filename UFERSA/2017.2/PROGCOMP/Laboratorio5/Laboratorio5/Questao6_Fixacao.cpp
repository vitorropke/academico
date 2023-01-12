#include <iostream>
using namespace std;

int elevaAoQuadrado(int);
int elevaAoCubo(int);
int elevaAQuarta(int);

int main()
{
	int numero;

	cout << "Digite um número: ";
	cin >> numero;
	cout << numero << " ao quadrado é " << elevaAoQuadrado(numero) << '\n';
	cout << numero << " ao cubo é " << elevaAoCubo(numero) << '\n';
	cout << numero << " à quarta é " << elevaAQuarta(numero) << '\n';

	system("pause");
	return 0;
}

int elevaAoQuadrado(int numero)
{
	return numero * numero;
}

int elevaAoCubo(int numero)
{
	return numero * numero * numero;
}

int elevaAQuarta(int numero)
{
	return numero * numero * numero * numero;
}