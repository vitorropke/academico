#include <iostream>
using namespace std;

int main()
{
	int horas, minutos;
	char doisPontos;

	cout << "Que horas s�o? ";
	cin >> horas >> doisPontos >> minutos;
	cout << "O seu rel�gio est� atrasado.\n";
	cout << "Agora s�o " << horas + 1 << ":" << minutos << ".\n";

	system("pause");
	return 0;
}