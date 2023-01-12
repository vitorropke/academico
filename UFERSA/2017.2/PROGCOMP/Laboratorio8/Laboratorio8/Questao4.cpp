#include <iostream>
using namespace std;

int main()
{
	float numero;

	cout << "Digite um ponto-flutuante: ";
	cin >> numero;

	cout << "Notação padrão: " << numero;
	
	cout << scientific;
	cout << "\nNotação científica: " << numero;
	
	cout << fixed;
	cout.precision(2);
	cout << "\nNotação decimal: " << numero << '\n';

	system("pause");
	return 0;
}