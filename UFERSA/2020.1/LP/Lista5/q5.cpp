#include <iostream>
#include <vector>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	unsigned int numeroQuartos = rooms.size();
	bool portasAbertas[numeroQuartos], chaves[numeroQuartos], nenhumaChave = false;

	// Inicializa o vetor de portas abertas
	for(unsigned int i = 0; i < numeroQuartos; i++)
		portasAbertas[i] = false;

	// Inicializa o vetor de chaves
	for(unsigned int i = 1; i < numeroQuartos; i++)
		chaves[i] = false;
	
	chaves[0] = true;	// Tenho a chave para o primeiro quarto
	/*
	for(unsigned int i = 0; i < numeroQuartos; i++)
		cout << portasAbertas[i] << " ";
	cout << '\n';
	*/
	// Enquanto existirem chaves para abrir portas
	while(!nenhumaChave) {
		// Percorre os quartos, procurando as chaves
		for(unsigned int i = 0; i < numeroQuartos; i++) {
			if(chaves[i]) {					// Se existir uma chave para o atual quarto
				portasAbertas[i] = true;	// A porta desse quarto é aberta
				chaves[i] = false;			// A chave, agora está na porta

				// Procura as chaves que existem nesse quarto
				for(unsigned int j = 0; j < rooms[i].size(); j++) {
					if(!portasAbertas[rooms[i][j]])	// Se a porta não estiver aberta
						chaves[rooms[i][j]] = true;	// Pega a chave
				}
			}
		}

		nenhumaChave = true;
		// Verifica se ainda existe alguma chave
		for(unsigned int i = 0; i < numeroQuartos; i++) {
			if(chaves[i]) {	// Se achar uma chave, sai desse loop e continua a abrir portas
				nenhumaChave = false;
				break;
			}
		}
	}
	/*
	for(unsigned int i = 0; i < numeroQuartos; i++)
		cout << portasAbertas[i] << " ";
	*/
	// Percorre todas os quartos, verificando se as portas estão abertas
	for(unsigned int i = 0; i < numeroQuartos; i++) {
		if(!portasAbertas[i])	// Se existir alguma porta fechada, retorna falso
			return false;
	}

	return true;
}

int main() {
	vector<vector<int>> quartos = {{1},{2},{3},{}};
	//vector<vector<int>> quartos = {{1,3},{3,0,1},{2},{0}};

	cout << canVisitAllRooms(quartos) << '\n';

	return 0;
}