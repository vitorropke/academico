#include <iostream>
using namespace std;

int main()
{
	double preco[3] = { 1.5, 2.0, 1.0 }, quantidade[3];

	cout << "Prezado Cliente,\n\n"
		<< "Digite a quantidade de quilos desejados:\n"
		<< "Alface: ";
	cin >> quantidade[0];
	cout << "Beterraba: ";
	cin >> quantidade[1];
	cout << "Cenoura: ";
	cin >> quantidade[2];
	cout << fixed;
	cout.precision(2);
	cout << "\nResumo da Compra\n"
		<< "-------------------\n"
		<< "Alface    = R$" << quantidade[0] * preco[0] << '\n'
		<< "Beterraba = R$" << quantidade[1] * preco[1] << '\n'
		<< "Cenoura   = R$" << quantidade[2] * preco[2] << '\n'
		<< "-------------------\n"
		<< "Total     = R$" << quantidade[0] * preco[0] + quantidade[1] * preco[1] + quantidade[2] * preco[2]
		<< '\n';

	system("pause");
	return 0;
}