#include <iostream>
using namespace std;

int main()
{
	float numero;

	cout << "Digite um ponto-flutuante: ";
	cin >> numero;

	cout << "Nota��o padr�o: " << numero;
	
	cout << scientific;
	cout << "\nNota��o cient�fica: " << numero;
	
	cout << fixed;
	cout.precision(2);
	cout << "\nNota��o decimal: " << numero << '\n';

	system("pause");
	return 0;
}