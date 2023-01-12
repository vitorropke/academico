#include <iostream>
using namespace std;

int main()
{
	float pesos[3] = { 2, 3, 4 }, notas[3], media;

	cout << "Digite suas três notas em sequência: ";
	cin >> notas[0] >> notas[1] >> notas[2];
	media = (notas[0] * pesos[0] + notas[1] * pesos[1] + notas[2] * pesos[2]) / 9;
	cout << "Média = " << media << '\n';

	system("pause");
	return 0;
}