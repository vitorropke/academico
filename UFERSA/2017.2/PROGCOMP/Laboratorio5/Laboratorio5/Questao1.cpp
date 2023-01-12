#include <iostream>
using namespace std;

void imprimeHorario(int, int);

int main()
{
	int horas, minutos;

	cout << "Entre com o número de horas: ";
	cin >> horas;
	cout << "Entre com o número de minutos: ";
	cin >> minutos;
	cout << "Agora são ";
	imprimeHorario(horas, minutos);
	cout << '\n';

	system("pause");
	return 0;
}

void imprimeHorario(int horas, int minutos)
{
	cout << horas << ':' << minutos;
}