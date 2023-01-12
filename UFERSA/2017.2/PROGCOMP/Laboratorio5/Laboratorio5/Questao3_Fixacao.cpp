#include <iostream>
using namespace std;

float calculoIMC(float, float);

int main()
{
	float massa, altura;

	cout << "Digite a sua massa em Kg: ";
	cin >> massa;
	cout << "Digite a sua altura em m: ";
	cin >> altura;
	cout << "Seu IMC é " << calculoIMC(massa, altura) << '\n';

	system("pause");
	return 0;
}

float calculoIMC(float massa, float altura)
{
	return massa / (altura * altura);
}