#include <iostream>
using namespace std;

int main()
{
	int distanciaPercorrida, litrosDeCombustivel;

	cout << "Dist�ncia percorrida (km): ";
	cin >> distanciaPercorrida;
	cout << "Litros de combust�vel: ";
	cin >> litrosDeCombustivel;
	cout << "O consumo do seu carro foi de " << distanciaPercorrida / litrosDeCombustivel
		<< " km/litro.\n";

	system("pause");
	return 0;
}