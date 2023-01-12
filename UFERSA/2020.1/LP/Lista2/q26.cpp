#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int numeroCasos;
	string sEntrada, palavra = "";
	vector<string> vetorEntrada;

	scanf("%d%*c", &numeroCasos);

	for(unsigned int i = 0; i < numeroCasos; i++) {

		getline(cin, sEntrada);

		for(unsigned int j = 0; j < sEntrada.size(); j++) { // String de entrada, para vetor
			if(sEntrada[j] == ' ' || j+1 == sEntrada.size()) { // Se for espaço, separa um palavra da outra e
				// coloca no vetor. Se for o final da string, adiciona o último caractere
				if(j+1 == sEntrada.size())
					palavra += sEntrada[j];

				vetorEntrada.push_back(palavra);
				palavra = "";
			}
			if(sEntrada[j] != ' ')
				palavra += sEntrada[j];
		}

		// Verifica a quantidade de strings do vetor
		if(vetorEntrada.size() > 50)
			return 0;
		// Verifica a quantidade de caracteres de cada string do vetor
		for(unsigned int j = 0; j < vetorEntrada.size(); j++) {
			if(vetorEntrada[j].length() > 50)
				return 0;
		}

		sort(vetorEntrada.begin(), vetorEntrada.end(), [](const string first, const string second){
			return first.size() > second.size();
		}); // Ordena o vetor por tamanho de strings

		// Imprime o vetor
		for(unsigned int j = 0; j < vetorEntrada.size(); j++) {
			cout << vetorEntrada[j] << ' ';
		}
		cout << '\n';
		vetorEntrada.clear();
	}

	return 0;
}
