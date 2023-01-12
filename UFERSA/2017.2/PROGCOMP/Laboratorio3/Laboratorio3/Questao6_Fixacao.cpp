#include <iostream>
using namespace std;

int main()
{
	int horas, minutos;
	char doisPontos;

	cout << "Que horas são? ";
	cin >> horas >> doisPontos >> minutos;
	cout << "O seu relógio está atrasado.\n";
	cout << "Agora são " << horas + 1 << ":" << minutos << ".\n";

	system("pause");
	return 0;
}