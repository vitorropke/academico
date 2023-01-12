#include <iostream>
using namespace std;

#define MINUTOS 60

int main()
{
	int horaPartida, minutoPartida, horaChegada, minutoChegada, minutosPartida, minutosChegada,
		minutosViagem;

	cout << "Digite o horário de partida (HH MM): ";
	cin >> horaPartida >> minutoPartida;
	cout << "Digite o horário de chegada (HH MM): ";
	cin >> horaChegada >> minutoChegada;
	cout << '\n';
	minutosPartida = MINUTOS * horaPartida + minutoPartida;
	minutosChegada = MINUTOS * horaChegada + minutoChegada;
	minutosViagem = minutosChegada - minutosPartida;
	cout << "O tempo total de viagem foi " << minutosViagem / 60 << " horas e " << minutosViagem % 60
		<< " min.\n";

	system("pause");
	return 0;
}