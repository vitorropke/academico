//#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void deepFirstSearch(vector<vector<int>>& grafo, int vertice, int destino, vector<int> caminhoAtual, vector<vector<int>>& caminhos) {
	if(vertice == destino) {	// Se chegar no vércite de destino
		caminhos.push_back(caminhoAtual);
		return;
	}

	//for(auto it = grafo.begin(); it != grafo.end(); ++it)
	for(unsigned int i : grafo[vertice]) {	// Percorre do início até o fim do grafo
		caminhoAtual.push_back(i);
		deepFirstSearch(grafo, i, destino, caminhoAtual, caminhos);
		caminhoAtual.pop_back();
	}
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> caminhos;
	vector<int> caminhoAtual;

	caminhoAtual.push_back(0);
	deepFirstSearch(graph, 0, graph.size() - 1, caminhoAtual, caminhos);

	return caminhos;
}

int main() {
	//vector<vector<int>> vetor = {{1,2},{3},{3},{}};
	vector<vector<int>> vetor = {{4,3,1},{3,2,4},{3},{4},{}};
	//vector<vector<int>> vetor = {{1},{}};
	//vector<vector<int>> vetor = {{1,2,3},{2},{3},{}};
	//vector<vector<int>> vetor = {{1,3},{2},{3},{}};
	vector<vector<int>> saida;

	saida = allPathsSourceTarget(vetor);

	for(unsigned int i = 0; i < saida.size(); i++) {
		for(unsigned int j = 0; j < saida[i].size(); j++)
			cout << saida[i][j] << " ";
		cout << "\n";
	}

	return 0;
}