#include <iostream>
using namespace std;

void emitirAlerta();

int main()
{
	int senha;

	cout << "Iniciando com um som...\n";
	emitirAlerta();
	cout << "Digite sua senha: ______\b\b\b\b\b\b";
	cin >> senha;
	cout << "Obrigado!\n";

	system("pause");
	return 0;
}

void emitirAlerta()
{
	cout << '\a';
}