#include <iostream>
using namespace std;

float mediaHarmonica(float, float);

int main()
{
	float numero1, numero2;

	cout << "Entre com um n�mero: ";
	cin >> numero1;
	cout << "Entre com outro n�mero: ";
	cin >> numero2;
	cout << "A m�dia harm�nica dos n�meros � " << mediaHarmonica(numero1, numero2) << '\n';

	system("pause");
	return 0;
}

float mediaHarmonica(float numero1, float numero2)
{
	return 2.0 * numero1 * numero2 / (numero1 + numero2);
}