#include <iostream>
using namespace std;

int main()
{
	double apostaJogador1, apostaJogador2, valorDoPremio, parte1, parte2;

	cout << "Aposta dos amigos\n";
	cout << "-----------------\n";
	cout << "Digite a quantia apostada pelo jogador 1: ";
	cin >> apostaJogador1;
	cout << "Digite a quantia apostada pelo jogador 2: ";
	cin >> apostaJogador2;
	cout << "Entre com o valor do prêmio: ";
	cin >> valorDoPremio;

	parte1 = (valorDoPremio * apostaJogador1) / (apostaJogador1 + apostaJogador2);
	parte2 = valorDoPremio - parte1;

	cout << fixed;
	cout.precision(0);
	cout << "O jogador 1 tem direito a R$" << parte1 << '\n';
	cout << "O jogador 2 tem direito a R$" << parte2 << '\n';

	system("pause");
	return 0;
}