#include <iostream>
#include <vector>

using namespace std;

void deepFirstSearch(int i, int j, vector<vector<int>>& matriz) {
	// Quando chega no final da matriz ou quando encontra 1
	if(i < 0 or i == matriz.size() or j < 0 or j== matriz.size() or matriz[i][j] == 1)
		return;
	
	matriz[i][j] = 1;

	// Percorre a matriz em todas as direções
	deepFirstSearch(i, j + 1, matriz);
	deepFirstSearch(i, j - 1, matriz);
	deepFirstSearch(i + 1, j, matriz);
	deepFirstSearch(i - 1, j, matriz);
}

int regionsBySlashes(vector<string>& grid) {
	int tamanhoMatriz = grid.size() * 3, linha, coluna, contador;
	vector<vector<int>> matriz(tamanhoMatriz, vector<int>(tamanhoMatriz));

	for(unsigned int i = 0; i < grid.size(); i++) {
		for(unsigned int j = 0; j < grid[i].length(); j++) {
			if(grid[i][j] == ' ')
				continue;
			
			linha = i * 3;

			if(grid[i][j] == '\\') {
				coluna = j * 3;

				for(unsigned int k = 0; k < 3; k++)
					matriz[linha++][coluna++] = 1;
			} else {
				coluna = j * 3 + 2;

				for(unsigned int k = 0; k < 3; k++)
					matriz[linha++][coluna++] = 1;
			}
		}
	}

	contador = 0;

	for(unsigned int i = 0; i < matriz.size(); i++) {
		for(unsigned int j = 0; j < matriz[i].size(); j++) {
			if(matriz[i][j] == 0) {
				contador++;
				deepFirstSearch(i, j, matriz);
			}
		}
	}
	return contador;
}

int main() {
	vector<string> vetor = { " /", "/ " };

	cout << regionsBySlashes(vetor);

	return 0;
}