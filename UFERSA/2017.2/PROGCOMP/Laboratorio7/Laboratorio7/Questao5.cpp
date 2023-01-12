#include <iostream>
using namespace std;

unsigned char LigarBit(unsigned char, int);
unsigned char DesligarBit(unsigned char, int);
bool TestarBit(unsigned char, int);

int main()
{

}

unsigned char LigarBit(unsigned char estado, int posicao)
{
	unsigned char mascara = 1 << posicao;
	
	estado = estado | mascara;
	
	return estado;
}

unsigned char DesligarBit(unsigned char estado, int posicao)
{
	unsigned char mascara = 1 << posicao;

	estado = estado & ~mascara;

	return estado;
}

bool TestarBit(unsigned char estado, int posicao)
{
	unsigned char mascara = 1 << posicao;

	if (estado & mascara)
		return true;
	else
		return false;
}