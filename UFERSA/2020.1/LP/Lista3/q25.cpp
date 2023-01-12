#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned long operador1, operador2, indice;
	unsigned int carryOperations, digitoAtual, menorVetor, diferencaStringAB;
	vector<unsigned int> vetorOperador1;
	vector<unsigned int> vetorOperador2;

	cin >> operador1 >> operador2;

	while(operador1 != 0 || operador2 != 0) {
		// Verificação da entrada (constraints)
		if(operador1 > 999999999 || operador2 > 999999999)
			return 0;
		// Fim da verificação da entrada (constraints)

		// Restaura valores
		vetorOperador1.clear();
		vetorOperador2.clear();
		carryOperations = 0;

		// Segrega os dígitos e coloca cada um, em uma posição no vetor
		indice = 1;
		while(indice <= operador1) {
			digitoAtual = operador1 / indice % 10; // Separa o dígito

			indice = indice * 10; // Atualiza o índice na base 10

			vetorOperador1.push_back(digitoAtual); // Coloca o dígito no vetor
		}

		// Segrega os dígitos e coloca cada um, em uma posição no vetor
		indice = 1;
		while(indice <= operador2) {
			digitoAtual = operador2 / indice % 10; // Separa o dígito

			indice = indice * 10; // Atualiza o índice na base 10

			vetorOperador2.push_back(digitoAtual); // Coloca o dígito no vetor
		}

		// Pega o tamanho do menor vetor
		if(vetorOperador1.size() > vetorOperador2.size()) {
			diferencaStringAB = vetorOperador1.size() - vetorOperador2.size();
			menorVetor = vetorOperador2.size();
		}
		else {
			menorVetor = vetorOperador1.size();
			diferencaStringAB = vetorOperador2.size() - vetorOperador1.size();
		}
		
		// Calcula os carryes, caso a soma da posição dos vetores seja maior que 9
		for(unsigned int i = 0; i < menorVetor; i++) {
			if(vetorOperador1[i+diferencaStringAB] + vetorOperador2[i] > 9)
				carryOperations++;
		}

		// Saída
		if(carryOperations == 0)
			cout << "No carry operation.\n";
		else if(carryOperations == 1)
			cout << "1 carry operation.\n";
		else
			cout << carryOperations << " carry operations.\n";

		// Próxima entrada
		cin >> operador1 >> operador2;
	}

	return 0;
}