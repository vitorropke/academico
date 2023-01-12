#include <iostream>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
	unsigned int tamanhoString = s.length();
	int letras[256] = {0};

	// Preenche o vetor com as frequências
	for(unsigned int i = 0; i < tamanhoString; i++) {
		letras[s[i]]++;
	}
	// Encontrar o primeiro caractere com frequência de apenas 1
	for(unsigned int i = 0; i < tamanhoString; i++) {
		if(letras[s[i]] == 1)
			return i;
	}
	return -1;
}

int main() {
	string entrada;

	//getline(cin, entrada);

	entrada = "abca";

	cout << firstUniqChar(entrada);

	return 0;
}
