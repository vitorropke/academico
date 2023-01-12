#include <iostream>

using namespace std;

int main() {
	unsigned int linhas, colunas, linhaEncontrada = 0, colunaEncontrada = 0;

	// Entrada
	cin >> linhas >> colunas;

	// Verificação da entrada de linhas e colunas
	if(linhas < 3)
		return 0;
	if(colunas < 3 || colunas > 1000)
		return 0;

	int matrix[linhas][colunas];

	for(unsigned int i = 0; i < linhas; i++) {
		for(unsigned int j = 0; j < colunas; j++) {
			cin >> matrix[i][j];

			// Verificação da entrada da matrix
			if(matrix[i][j] < -100 || matrix[i][j] > 100)
				return 0;
		}
	}

	// Começa a percorrer a matrix a partir da segunda linha e segunda coluna até a penúltima linha e penúltima coluna
	for(unsigned int i = 1; i < linhas - 1; i++) {
		for(unsigned int j = 1; j < colunas - 1; j++) {
			// Se achar o número 42, procure pelos 7s ao redor
			if(matrix[i][j] == 42) {
				if(matrix[i-1][j-1] != 7) // Primeira linha, primeira coluna
					j += 3;
				else if(matrix[i-1][j] != 7) // Primeira linha, coluna do meio
					j += 2;
				else if(matrix[i-1][j+1] != 7) // Primeira linha, última coluna
					j += 1;
				else if(matrix[i][j-1] != 7) // Linha do meio, primeira coluna
					j += 3;
				else if(matrix[i][j+1] != 7) // Linha do meio, última coluna
					j += 1;
				else if(matrix[i+1][j-1] != 7) // Última linha, primeira coluna
					j += 3;
				else if(matrix[i+1][j] != 7) // Última linha, coluna do meio
					j += 2;
				else if(matrix[i+1][j+1] != 7) // Última linha, última coluna
					j += 1;
				else {
					linhaEncontrada = i+1;
					colunaEncontrada = j+1;

					cout << linhaEncontrada << ' ' << colunaEncontrada << '\n';
					return 0;
				}
			}
		}
	}
	cout << linhaEncontrada << ' ' << colunaEncontrada << '\n';

	return 0;
}
