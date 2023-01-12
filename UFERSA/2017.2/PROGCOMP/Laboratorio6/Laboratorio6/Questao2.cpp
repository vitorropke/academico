#include <iostream>
using namespace std;

int main()
{
	int distanciaPercorrida, litrosDeCombustivel;

	cout << "Distância percorrida (km): ";
	cin >> distanciaPercorrida;
	cout << "Litros de combustível: ";
	cin >> litrosDeCombustivel;
	cout << "O consumo do seu carro foi de " << distanciaPercorrida / litrosDeCombustivel
		<< " km/litro.\n";

	system("pause");
	return 0;
}