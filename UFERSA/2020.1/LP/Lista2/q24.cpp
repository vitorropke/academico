#include <iostream>

using namespace std;

int main() {
	unsigned int numeroCasos;
	cin >> numeroCasos;

	if(numeroCasos > 10000 || numeroCasos < 1)
		return 0;

	unsigned int numerador1, denominador1, numerador2, denominador2;
	int numeradorResultado, denominadorResultado;
	char operacao, barraComEspaco = '/';

	for(unsigned int i = 0; i < numeroCasos; i++) { // Repete, baseado no número de casos
		cin >> numerador1 >> barraComEspaco >> denominador1 >> operacao >> numerador2 >> barraComEspaco >> denominador2;

		if(operacao == '+') { // Operação de soma
			numeradorResultado = numerador1 * denominador2 + numerador2 * denominador1;
			denominadorResultado = denominador1 * denominador2;

			cout << numeradorResultado << '/' << denominadorResultado << " = ";

			for(unsigned int j = denominadorResultado; j >= 2; j--) { // Simplifica a fração
				if(numeradorResultado % j == 0 && denominadorResultado % j ==0) {
					numeradorResultado = numeradorResultado / j;
					denominadorResultado = denominadorResultado / j;
				}
			}

			cout << numeradorResultado << '/' << denominadorResultado << '\n';

		} else if(operacao == '-') { // Operação de subtração
			numeradorResultado = numerador1 * denominador2 - numerador2 * denominador1;
			denominadorResultado = denominador1 * denominador2;

			cout << numeradorResultado << '/' << denominadorResultado << " = ";

			for(unsigned int j = denominadorResultado; j >= 2; j--) { // Simplifica a fração
				if(numeradorResultado % j == 0 && denominadorResultado % j ==0) {
					numeradorResultado = numeradorResultado / j;
					denominadorResultado = denominadorResultado / j;
				}
			}

			cout << numeradorResultado << '/' << denominadorResultado << '\n';

		} else if(operacao == '*') { // Operação de multiplicação
			numeradorResultado = numerador1 * numerador2;
			denominadorResultado = denominador1 * denominador2;

			cout << numeradorResultado << '/' << denominadorResultado << " = ";

			for(unsigned int j = denominadorResultado; j >= 2; j--) { // Simplifica a fração
				if(numeradorResultado % j == 0 && denominadorResultado % j ==0) {
					numeradorResultado = numeradorResultado / j;
					denominadorResultado = denominadorResultado / j;
				}
			}

			cout << numeradorResultado << '/' << denominadorResultado << '\n';

		} else if(operacao == '/') { // Operação de divisão
			numeradorResultado = numerador1 * denominador2;
			denominadorResultado = numerador2 * denominador1;

			cout << numeradorResultado << '/' << denominadorResultado << " = ";

			for(unsigned int j = denominadorResultado; j >= 2; j--) { // Simplifica a fração
				if(numeradorResultado % j == 0 && denominadorResultado % j ==0) {
					numeradorResultado = numeradorResultado / j;
					denominadorResultado = denominadorResultado / j;
				}
			}

			cout << numeradorResultado << '/' << denominadorResultado << '\n';
		}
	}

	return 0;
}
