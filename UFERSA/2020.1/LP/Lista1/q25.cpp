#include <iostream>

using namespace std;

int main() {
	unsigned int posicaoXInicial, posicaoYInicial, posicaoXFinal, posicaoYFinal;

	while(true) {
		// Entrada
		cin >> posicaoXInicial >> posicaoYInicial >> posicaoXFinal >> posicaoYFinal;

		// Verificação da entrada
		if(
			posicaoXInicial > 8 || posicaoXInicial < 1
			|| posicaoYInicial > 8 || posicaoYInicial < 1
			|| posicaoXFinal > 8 || posicaoXFinal < 1
			|| posicaoYFinal > 8 || posicaoYFinal < 1
			)
			return 0;

		// Verifica as posições e determina a quantidade de movimentos
		if(posicaoXInicial == posicaoXFinal && posicaoYInicial == posicaoYFinal) // Verifica se está na mesma posição
			cout << 0 << '\n'; // 0 movimentos
		else if((posicaoXInicial == posicaoXFinal && posicaoYInicial != posicaoYFinal) // Verifica se está na mesma linha ou coluna
			|| (posicaoXInicial != posicaoXFinal && posicaoYInicial == posicaoYFinal))
			cout << 1 << '\n'; // 1 movimento
		else { // Verifica se está na mesma diagonal
			if(posicaoXInicial > posicaoXFinal && posicaoYInicial > posicaoYFinal){
				for(unsigned int i = posicaoXInicial; i > posicaoXFinal; i--) { // Deslocamento pela diagonal superior esquerda
					posicaoXInicial--;
					posicaoYInicial--;
				}
				if(posicaoXInicial == posicaoXFinal && posicaoYInicial == posicaoYFinal) // Se após o deslocamento, encontrar o destino
					cout << 1 << '\n';
				else
					cout << 2 << '\n';
			} else if(posicaoXInicial > posicaoXFinal && posicaoYInicial < posicaoYFinal) {
				for(unsigned int i = posicaoXInicial; i > posicaoXFinal; i--) { // Deslocamento pela diagonal superior direita
					posicaoXInicial--;
					posicaoYInicial++;
				}
				if(posicaoXInicial == posicaoXFinal && posicaoYInicial == posicaoYFinal) // Se após o deslocamento, encontrar o destino
					cout << 1 << '\n';
				else
					cout << 2 << '\n';
			} else if(posicaoXInicial < posicaoXFinal && posicaoYInicial > posicaoYFinal) {
				for(unsigned int i = posicaoXInicial; i < posicaoXFinal; i++) { // Deslocamento pela diagonal inferior esquerda
					posicaoXInicial++;
					posicaoYInicial--;
				}
				if(posicaoXInicial == posicaoXFinal && posicaoYInicial == posicaoYFinal) // Se após o deslocamento, encontrar o destino
					cout << 1 << '\n';
				else
					cout << 2 << '\n';
			} else if(posicaoXInicial < posicaoXFinal && posicaoYInicial < posicaoYFinal) {
				for(unsigned int i = posicaoXInicial; i < posicaoXFinal; i++) { // Deslocamento pela diagonal inferior direita
					posicaoXInicial++;
					posicaoYInicial++;
				}
				if(posicaoXInicial == posicaoXFinal && posicaoYInicial == posicaoYFinal) // Se após o deslocamento, encontrar o destino
					cout << 1 << '\n';
				else
					cout << 2 << '\n';
			}
		}
	}
	return 0;
}
