#include <cmath>
#include <iostream>

using namespace std;

int main() {
	unsigned int somatorio = 0, entrada, numeroCasos;

	cin >> numeroCasos;

	for(unsigned int i = 0; i < numeroCasos; i++) {
		cin >> entrada;

		// Início do constraint
		if(entrada < 1 || entrada > 31)
			return 0;
		// Fim do constraint

		// Calcula o somatório iterando sobre a entrada e calculando 2^i
		for(unsigned int j = 0; j < entrada; j++)
			somatorio += pow(2, j);
		
		cout << somatorio << '\n';
		
		somatorio = 0; // Reinicia o somatório
	}

	return 0;
}