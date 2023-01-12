#include <iostream>
#include <vector>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
	unsigned int tamanhoVetor = trust.size();
	bool matrizAdjacencia[N][N], linhaNula = false;

	// Inicializa a matriz de adjacência
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < N; j++)
			matrizAdjacencia[i][j] = false;
	}

	// Baseado na primeira e segunda coluna de trust.
	// Primeira coluna aponta para segunda.
	// Essa posição na matriz de adjacência é colocada para true.
	// Menos 1 é para compensar a matriz. Os valores em trust, iniciam-se em 1
	// Vetor inicia-se em 0.
	for(unsigned int i = 0; i < tamanhoVetor; i++)
		matrizAdjacencia[trust[i][0] - 1][trust[i][1] - 1] = true;

	/*
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < N; j++)
			cout << matrizAdjacencia[i][j] << " ";
		cout << "\n";
	}
	*/

	// Verifica qual linha está completa de 0.
	// A partir do índice dessa linha, verifica-se a coluna no mesmo índice.
	// Verifica se a coluna do índice está completa de 1, exceto quando o índice da coluna
	// E da linha se encontram.
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < N; j++) {
			if(matrizAdjacencia[i][j])	// Se for valor 1, para
				break;
			if(j + 1 == N)				// Se chegar na última coluna
				linhaNula = true;
		}
		if(linhaNula) {	// Se a linha atual for completa de 0
			// Percorre as linhas, na mesma coluna, verificando se é tudo 1, exceto quando
			// índice da linhas é igual ao índice da coluna
			for(unsigned int linhas = 0; linhas < N; linhas++) {
				// 'i' aqui é coluna
				if(i != linhas) {	// Quando a linha for diferente da coluna
					if(!matrizAdjacencia[linhas][i])	// Quando um 0 é encontrado
						break;
				}
				if(linhas + 1 == N)		// Quando chega na última linha, retorna o índice
					return i + 1;
			}
		}
	}

	return -1;
}

int main() {
	vector<vector<int>> vetor = {{1,2}};
	//vector<vector<int>> vetor = {{1,3},{2,3}};
	//vector<vector<int>> vetor = {{1,3},{2,3},{3,1}};
	//vector<vector<int>> vetor = {{1,2},{2,3}};
	//vector<vector<int>> vetor = {{1,3},{1,4},{2,3},{2,4},{4,3}};

	cout << findJudge(2, vetor);

	return 0;
}