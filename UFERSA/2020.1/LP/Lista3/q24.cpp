#include <cmath>
#include <iostream>

using namespace std;

int main() {
	unsigned int casosTeste, casasTabuleiro;
	unsigned long long graos;

	cin >> casosTeste;
	// Verificação da entrada (constraints)
	if(casosTeste < 1 || casosTeste > 100)
		return 0;
	// Fim da verificação da entrada (constraints)
	
	for(unsigned char i = 0; i < casosTeste; i++) {
		cin >> casasTabuleiro;
		// Verificação da entrada (constraints)
		if(casasTabuleiro < 1 || casasTabuleiro > 64)
			return 0;
		// Fim da verificação da entrada (constraints)

		// Calcula o número de grãos
		graos = pow(2, casasTabuleiro) - 1;

		// Saída
		cout << graos / 12 / 1000 << " kg\n";
	}

	return 0;
}