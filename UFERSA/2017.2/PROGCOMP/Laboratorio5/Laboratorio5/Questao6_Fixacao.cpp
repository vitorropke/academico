#include <iostream>
using namespace std;

int elevaAoQuadrado(int);
int elevaAoCubo(int);
int elevaAQuarta(int);

int main()
{
	int numero;

	cout << "Digite um n�mero: ";
	cin >> numero;
	cout << numero << " ao quadrado � " << elevaAoQuadrado(numero) << '\n';
	cout << numero << " ao cubo � " << elevaAoCubo(numero) << '\n';
	cout << numero << " � quarta � " << elevaAQuarta(numero) << '\n';

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