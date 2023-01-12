#include <iostream>
using namespace std;

int main()
{
	float massa, minutosCorrida, minutosCiclismo, minutosNatacao, caloriasCorrida, caloriasCiclismo,
		caloriasNatacao;

	cout << "Digite seu peso em quilos: ";
	cin >> massa;
	cout << "Digite o tempo de corrida: ";
	cin >> minutosCorrida;
	cout << "Digite o tempo de ciclismo: ";
	cin >> minutosCiclismo;
	cout << "Digite o tempo de natação: ";
	cin >> minutosNatacao;
	caloriasCorrida = 7.0 * massa * (minutosCorrida / 60);
	caloriasCiclismo = 7.0 * massa * (minutosCiclismo / 60);
	caloriasNatacao = 8.0 * massa * (minutosNatacao / 60);
	cout << "Você gastou um total de " << caloriasCorrida + caloriasCiclismo + caloriasNatacao
		<< " calorias.\n";

	system("pause");
	return 0;
}