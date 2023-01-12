#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	// Se a entrada for única, retorne apenas ela
	if(strs.size() == 1)
		return strs[0];
	// Se não existir entradas, retorne uma string vazia
	if(strs.size() == 0)
		return "";

	unsigned int menorEntrada = strs[0].length();
	string saida = "";

	// Procura pela menor entrada
	for(unsigned int i = 1; i < strs.size(); i++) {
		// Procura pela menor string
		if(strs[i].length() < menorEntrada)
			menorEntrada = strs[i].length();
	}

	// Compara todas as strings até o primeiro caractere diferente
	for(unsigned int i = 0; i < menorEntrada; i++) { // i são os caracteres
		for(unsigned int j = 0; j < strs.size(); j++) { // j são as strings
			if(j + 1 != strs.size()){
				if(strs[j][i] != strs[j + 1][i])
					return saida;
			}else
				saida += strs[j][i];
		}
	}
	return saida;
}

int main() {
	vector<string> entrada;

	entrada.push_back("aadadaad");
	entrada.push_back("ab");
	entrada.push_back("abdsd");

	//getline(cin, entrada);

	cout << longestCommonPrefix(entrada);

	return 0;
}
