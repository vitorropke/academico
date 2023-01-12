#include <iostream>
using namespace std;

float IMC(float, float);

int main()
{
	float altura, massa;

	cout << "Digite sua altura em metros: ";
	cin >> altura;
	cout << "Digite seu peso em quilos: ";
	cin >> massa;
	cout << "Seu índice de massa corporal (IMC): " << IMC(altura, massa) << '\n';

	system("pause");
	return 0;
}

float IMC(float altura, float massa)
{
	return massa / (altura * altura);
}