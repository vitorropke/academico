#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getKth(int lo, int hi, int k) {
	unsigned int tamanhoVetor = hi - lo, passos, numeroAtual;
	vector<vector<unsigned int>> valores;
	
	// Percorre os números de 'lo' a 'hi'
	for(unsigned int i = lo; i <= hi; i++) {
		passos = 0;
		numeroAtual = i;

		// Reduz o número atual até chegar em 1
		while(numeroAtual != 1) {
			if(numeroAtual % 2 == 0)	// Se o número atual for par
				numeroAtual /= 2;
			else						// Se o número atual for ímpar
				numeroAtual = numeroAtual * 3 + 1;
			
			passos++;
		}
		valores.push_back({passos, i});
	}

	sort(valores.begin(), valores.end());
	/*
	for(unsigned int i = 0; i < valores.size(); i++) {
		for(unsigned int j = 0; j < 2; j++)
			cout << valores[i][j] << " ";
		cout << "\n";
	}
	*/
	return valores[k - 1][1];
}

int main() {
	cout << getKth(1, 1000, 777);

	return 0;
}