#include <iostream>

using namespace std;

bool isPalindrome(string s) {
	string semSimbolos = "";

	// Converte todas as letras maiúsculas para minúsculas
	for(unsigned int i = 0; i < s.length(); i++) {
		if(isupper(s[i]))
			s[i] = tolower(s[i]);
	}

	// Produz uma nova string sem símbolos
	for(unsigned int i = 0; i < s.length(); i++) {
		if(
			(s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= '0' && s[i] <= '9')
		)
			semSimbolos += s[i];
	}

	int indiceReverso = semSimbolos.length() - 1, indice = 0;

	if(semSimbolos.length() < 2)
		return true;

	// Percorre a string pela frente e por trás
	while(indice < indiceReverso) {
		// Vê se o dígito da string crescente e da string decrescente são iguais
		if(semSimbolos[indice] != semSimbolos[indiceReverso])
			return false;

		indiceReverso--;
		indice++;
	}
	
	return true;
}

int main() {
	string entrada;

	//getline(cin, entrada);
	entrada = "1221";

	bool status = isPalindrome(entrada);

	cout << status;

	return 0;
}
