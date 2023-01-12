#include <iostream>

using namespace std;

int main() {
	unsigned int estrelas, posicaoAtual = 0, totalCarneiros = 0, numeroEstrelasAtacadas = 0;

	cin >> estrelas;

	// Verificação do número de estrelas
	if(estrelas < 1 || estrelas > 1000000)
		return 0;

	unsigned int numeroCarneiros[estrelas];
	bool estrelasAtacadas[estrelas]; // true, significa que foi atacada

	// Carneiros
	for(unsigned int i = 0; i < estrelas; i++) {
		cin >> numeroCarneiros[i];

		// Verificação do número de ovelhas
		if(numeroCarneiros[i] < 1 || numeroCarneiros[i] > 1000000)
			return 0;
	}

	// Se tiver pelo menos 1 carneiro aqui, extraia-o e modifique sua posição dentro dos limites das estrelas.
	while(numeroCarneiros[posicaoAtual] != 0 && posicaoAtual < estrelas) {
		if(numeroCarneiros[posicaoAtual] % 2 == 1) { // Se for ímpar, a posição aumenta
			numeroCarneiros[posicaoAtual]--;
			estrelasAtacadas[posicaoAtual] = true;
			posicaoAtual++;
		} else {
			numeroCarneiros[posicaoAtual]--;
			estrelasAtacadas[posicaoAtual] = true;
			posicaoAtual--;
		}
	}

	// Soma os carneiros que sobraram
	for(unsigned int i = 0; i < estrelas; i++)
		totalCarneiros += numeroCarneiros[i];

	// Verifica quais estrelas foram atacadas
	for(unsigned int i = 0; i < estrelas; i++){
		if(estrelasAtacadas[i])
			numeroEstrelasAtacadas++;
	}

	cout << numeroEstrelasAtacadas << " ";
	cout << totalCarneiros << '\n';

	return 0;
}
