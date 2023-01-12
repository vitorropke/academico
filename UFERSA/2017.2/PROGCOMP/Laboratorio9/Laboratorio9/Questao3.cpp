#include <iostream>
using namespace std;

int main()
{
	long segundos, dias, horas, minutos;
	const int horasEmUmDia = 24, minutosEmUmaHora = 60, segundosEmUmMinuto = 60;

	cout << "Entre com o número de segundos: ";
	cin >> segundos;
	
	dias = segundos / segundosEmUmMinuto / minutosEmUmaHora / horasEmUmDia;
	horas = segundos / segundosEmUmMinuto / minutosEmUmaHora % dias;
	minutos = segundos / segundosEmUmMinuto % minutosEmUmaHora;

	cout << segundos << " segundos = " << dias << " dias, " << horas << " horas, " << minutos
		<< " minutos e " << segundos % segundosEmUmMinuto << " segundos\n";

	system("pause");
	return 0;
}