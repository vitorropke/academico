#include <iostream>
#include <cmath>
using namespace std;

double modulo(double, double);

int main()
{
	double numero1, numero2;

	cout << "Digite um n�mero: ";
	cin >> numero1;
	cout << "Digite outro n�mero: ";
	cin >> numero2;
	cout << "A norma � " << modulo(numero1, numero2) << '\n';

	system("pause");
	return 0;
}

double modulo(double numero1, double numero2)
{
	return sqrt(pow(numero1, 2) + pow(numero2, 2));
}