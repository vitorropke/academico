#include <iostream>
using namespace std;

float VolumeCilindro(float, float);

int main()
{
	float raioDaBase, altura;

	cout << "Calcula o Volume de um Cilindro\n";
	cout << "-------------------------------\n";
	cout << "Entre com o raio da base: ";
	cin >> raioDaBase;
	cout << "Entre com a altura: ";
	cin >> altura;
	cout << "O volume do cilindro é " << VolumeCilindro(altura, raioDaBase) << '\n';

	system("pause");
	return 0;
}

float VolumeCilindro(float altura, float raioDaBase)
{
	const float pi = 3.14159;

	return pi * raioDaBase * raioDaBase * altura;
}