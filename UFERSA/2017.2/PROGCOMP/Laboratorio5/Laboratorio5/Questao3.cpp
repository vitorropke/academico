#include <iostream>
using namespace std;

float mediaHarmonica(float, float);

int main()
{
	float numero1, numero2;

	cout << "Entre com um número: ";
	cin >> numero1;
	cout << "Entre com outro número: ";
	cin >> numero2;
	cout << "A média harmônica dos números é " << mediaHarmonica(numero1, numero2) << '\n';

	system("pause");
	return 0;
}

float mediaHarmonica(float numero1, float numero2)
{
	return 2.0 * numero1 * numero2 / (numero1 + numero2);
}