#include <iostream>
using namespace std;

int main()
{
	double numero;

	cout << "Digite um n�mero real: ";
	cin >> numero;
	cout << "A parte inteira: " << int(numero) << '\n';
	cout << "A parte fracion�ria: " << numero - int(numero) << '\n';

	system("pause");
	return 0;
}