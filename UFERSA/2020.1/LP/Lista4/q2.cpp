#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> urlLonga, urlCurta;

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
	// Procura pela URL longa, se tiver
	auto const iter = find(urlLonga.begin(), urlLonga.end(), longUrl);
	
	if(iter != urlLonga.end())
		return urlCurta[iter - urlLonga.begin()];  // Retorna a URL curta
	
	// Cria uma string
	string novaURL = "http://url.com/";
	unsigned int tamanhoURLCurta = urlCurta.size(), contador = 0;
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
	
	// Gera novos caracteres
	for(unsigned int i = 0; i < tamanhoURLCurta; i++) {
		contador++;
		novaURL += alphanum[i];
		if(contador == 63) {
			contador = 0;
			novaURL += alphanum[contador];
		}
	}

	// Coloca a string longa e curta no vetor
	urlCurta.push_back(novaURL);
	urlLonga.push_back(longUrl);

	return novaURL;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
	// Procura pela URL curta
	auto const iter = find(urlCurta.begin(), urlCurta.end(), shortUrl);
	
	if(iter != urlCurta.end())
		return urlLonga[iter - urlCurta.begin()];  // Retorna a URL longa
	else
		return "";
}

int main() {
	cout << encode("https://leetcode.com/problems/design-tinyurl") << '\n';
	cout << decode("http://url.com/");

	return 0;
}