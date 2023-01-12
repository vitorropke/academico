#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
	// Todo número menor que 0 não é palíndromo
	if(x < 0)
		return false;
	// Todo número entre 0 e 9 é palíndromo, pois é dígito único
	if(x >= 0 && x <= 9)
		return true;
	
	vector<unsigned char> digitos;

	// Segrega os dígitos e coloca cada um, em uma posição no vetor
	unsigned long indice = 1;
	unsigned char digitoAtual;
	while(indice <= x) {
		digitoAtual = x / indice % 10; // Separa o dígito

		indice = indice * 10; // Atualiza o índice na base 10

		digitos.push_back(digitoAtual); // Coloca o dígito no vetor
	}

	unsigned char indiceReverso = digitos.size() - 1, indiceNormal = 0;

	// Percorre o vetor pela frente e por trás
	while(indiceNormal < indiceReverso) {
		// Vê se o dígito do vetor crescente e da vetor decrescente são diferentes
		if(digitos[indiceNormal] != digitos[indiceReverso])
			return false;

		indiceReverso--;
		indiceNormal++;
	}

	return true;
}

int main() {
	cout << isPalindrome(1410110141);

	return 0;
}