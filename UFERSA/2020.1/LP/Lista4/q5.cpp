#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pathInZigZagTree(int label) {
	vector<int> camadas;
	
	while(label) {  // Percorre as camadas da árvore
		camadas.push_back(label);
		label = label / 2;
	}

	for(unsigned int i = 0; i < camadas.size(); i++) {
		unsigned int x = camadas.size() - i;
	
		// Procura pelo valor da camada
		if(i % 2 != 0)
			camadas[i] = pow(2, x - 1) + pow(2, x) - 1 - camadas[i];  
		
	}
	
	reverse(camadas.begin(), camadas.end());  // Inverte o vetor

	return camadas;
}

int main() {
	vector<int> vetor = pathInZigZagTree(26);

	for(unsigned int i = 0; i < vetor.size(); i++) {
		cout << vetor[i] << ' ';
	}

	return 0;
}