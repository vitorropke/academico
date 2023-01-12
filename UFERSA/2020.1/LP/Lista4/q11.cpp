#include <cmath>
#include <iostream>

using namespace std;

int main() {
	unsigned int raioDesenhado, desenhadoX, desenhadoY, raioFlor, florX, florY;
	float relacaoCirculos;

	while(cin >> raioDesenhado >> desenhadoX >> desenhadoY >> raioFlor >> florX >> florY) {
		// Início dos constraints
		if(raioDesenhado < 1 || raioFlor > 1000 || florY > 1000)
			return 0;
		// Fim dos constraints

		// Relação entre os circulos
		relacaoCirculos = sqrt((florX - desenhadoX) * (florX - desenhadoX) + 
								(florY - desenhadoY) * (florY - desenhadoY));
		
		// Se o raio desenhado for maior ou igual ao raio da flor
		if((raioDesenhado - relacaoCirculos) >= raioFlor)
			cout << "RICO\n";
		else
			cout << "MORTO\n";
	}

	return 0;
}