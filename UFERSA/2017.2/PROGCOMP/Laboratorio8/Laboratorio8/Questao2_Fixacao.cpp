#include <iostream>
using namespace std;

int LigarBit(int, int);

int main()
{
	int expoente = 0;
	int mantissa = 0;
	float numero;

	LigarBit(expoente, 3); LigarBit(expoente, 6); LigarBit(expoente, 7);
	LigarBit(mantissa, 14); LigarBit(mantissa, 16); LigarBit(mantissa, 20); LigarBit(mantissa, 21);
	expoente = expoente - 127;
	numero = pow(2, expoente) * (1 + mantissa);
	cout << numero << '\n';

	system("pause");
	return 0;
}

int LigarBit(int estado, int posicao)
{
	int mascara = 1 << posicao;

	estado = estado | mascara;

	return estado;
}