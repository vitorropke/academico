#include <iostream>
#include <cmath>
using namespace std;

int absoluto(int);

int main()
{
	int numero;

	cout << "Digite um n�mero inteiro: ";
	cin >> numero;
	cout << "O valor absoluto � " << absoluto(numero) << '\n';

	system("pause");
	return 0;
}

int absoluto(int numero)
{
	return sqrt(pow(numero, 2));
}