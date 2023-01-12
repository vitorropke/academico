#include <cmath>
#include <iostream>

using namespace std;

int main() {
	bool encaixa = true;
	unsigned int casosTeste, numeroA, numeroB, diferencaStringAB;
	string stringNumeroA, stringNumeroB;

	cin >> casosTeste;

	for(unsigned int i = 0; i < casosTeste; i++) {
		cin >> numeroA >> numeroB;

		// Verificação da entrada (constraints)
		if(numeroA < 1 || numeroA >= pow(2, 31) || numeroB < 1 || numeroB >= pow(2, 31))
			return 0;
		// Fim da verificação da entrada (constraints)

		// converte int para string
		stringNumeroA = to_string(numeroA);
		stringNumeroB = to_string(numeroB);

		// Verifica se a string A é menor que a string B
		if(stringNumeroA.length() < stringNumeroB.length())
			encaixa = false;

		if(encaixa) { // Se passou no teste de tamanho
			diferencaStringAB = stringNumeroA.length() - stringNumeroB.length();

			// Percorre as strings. StringA adianta para alcançar stringB
			for(unsigned int j = 0; j < stringNumeroB.length(); j++) {
				// Busca pelo caractere diferente
				if(stringNumeroA[j + diferencaStringAB] != stringNumeroB[j]) {
					encaixa = false;
					break;
				}
			}
		}
		
		// Saída
		if(encaixa)
			cout << "encaixa\n";
		else
			cout << "nao encaixa\n";
		
		encaixa = true; // Restaura valor
	}

	return 0;
}