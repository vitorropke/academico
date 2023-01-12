#include <iostream>
using namespace std;

int main()
{
	double numero;

	cout << "Digite um número real: ";
	cin >> numero;
	cout << "A parte inteira: " << int(numero) << '\n';
	cout << "A parte fracionária: " << numero - int(numero) << '\n';

	system("pause");
	return 0;
}