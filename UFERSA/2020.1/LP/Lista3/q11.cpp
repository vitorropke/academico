#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int minCostToMoveChips(vector<int>& position) {
	unsigned char tamanhoVetor = position.size();

	// Se o vetor tiver apenas 1 posição, são 0 movimentos. Custo 0
	if(tamanhoVetor == 1)
		return 0;
	
	int par = 0, impar = 0;

	// Conta as posições que são pares e as posições ímpares
	for(unsigned char i = 0; i < tamanhoVetor; i++) {
		if(position[i] % 2 == 0)
			par++;
		else
			impar++;
	}
	return min(par, impar);
}

int main() {
	vector<int> vetor = { 1, 2, 3 };

	cout << minCostToMoveChips(vetor);

	return 0;
}