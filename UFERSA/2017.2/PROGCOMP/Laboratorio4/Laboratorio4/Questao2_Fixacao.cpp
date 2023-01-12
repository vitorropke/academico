#include <iostream>
using namespace std;

float media(int, int);

int main()
{
	int numero1, numero2;

	cout << "Digite um número inteiro: ";
	cin >> numero1;
	cout << "Digite outro valor inteiro: ";
	cin >> numero2;
	cout << "A média dos números é " << media(numero1, numero2) << '\n';

	system("pause");
	return 0;
}

float media(int numero1, int numero2)
{
	float soma;

	soma = numero1 + numero2;

	return soma / 2;
}