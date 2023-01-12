#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vagoes, vagoesReverso;
	unsigned int numeroVagoes, indiceReverso, vagao;
	bool fimDeBloco = false, tremReverso = true;

	while(true) {
		cin >> numeroVagoes;

		// Verifica se o número de vagões não é 0. Se for, o programa acaba
		if(numeroVagoes == 0)
			return 0;

		for(unsigned int i = 0; i < numeroVagoes; i++) { // Adiciona o trem
			cin >> vagao;

			if(vagao == 0) { // Se for igual a 0, é fim de bloco
				fimDeBloco = true;
				break;
			}

			vagoes.push_back(vagao);
		}

		if(!fimDeBloco)
			cout << "Yes" << '\n';

		while(!fimDeBloco) {
			for(unsigned int i = 0; i < numeroVagoes; i++) { // Adiciona o trem reverso
				cin >> vagao;

				if(vagao == 0) { // Se for igual a 0, é fim de bloco
					fimDeBloco = true;
					break;
				}

				vagoesReverso.push_back(vagao);
			}

			if(!fimDeBloco) { // Fim de bloco, para o trem reverso
				indiceReverso = vagoesReverso.size() - 1;
				for(unsigned int i = 0; i < vagoes.size(); i++) { // Verifica o trem reverso
					if(vagoes[i] != vagoesReverso[indiceReverso]) {
						tremReverso = false;
						break;
					}

					indiceReverso--;
				}
				if(tremReverso)
					cout << "Yes" << '\n';
				else
					cout << "No" << '\n';
			}
		}
		cout << '\n';
		fimDeBloco = false;
	}

	return 0;
}
