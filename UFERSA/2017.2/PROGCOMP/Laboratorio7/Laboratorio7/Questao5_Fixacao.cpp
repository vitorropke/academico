#include <iostream>
using namespace std;

void ExibirBits(unsigned char);
bool TestarBit(unsigned char, int);

int main()
{
	unsigned char numero;

	cout << "Digite um valor entre 0 e 255: ";
	cin >> numero;
	cout << "O número " << numero << " em binário é ";
	ExibirBits(numero);
	cout << '\n';

	system("pause");
	return 0;
}

void ExibirBits(unsigned char numero)
{
	if (TestarBit(numero, 0))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 1))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 2))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 3))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 4))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 5))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 6))
		cout << '1';
	else
		cout << '0';

	if (TestarBit(numero, 7))
		cout << '1';
	else
		cout << '0';
}

bool TestarBit(unsigned char estado, int posicao)
{
	unsigned char mascara = 1 << posicao;

	if (estado & mascara)
		return true;
	else
		return false;
}