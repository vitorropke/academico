#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
	unsigned int numeroDeLinhas = coordinates.size();

	sort(coordinates.begin(), coordinates.end()); // Ordena o vetor para verificar se existem elementos repetidos

	for(unsigned int i = 0; i < numeroDeLinhas - 1; i++) {
		if(coordinates[i] == coordinates[i + 1]) // Verifica se existem elementos repetidos (X e Y iguais)
			return false;
	}

	if(numeroDeLinhas == 2) // Se existirem apenas 2 pontos, então é uma reta
		return true;
	// Fim das verificações
	
	bool Xigual = true, Yigual = true;

	// Verifica se a reta é perpendicular em algum eixo
	for(unsigned int i = 0; i < numeroDeLinhas - 1; i++) {
		if(coordinates[i + 1][0] != coordinates[i][0]) // Verifica se os Xs são iguais
			Xigual = false;
		
		if(coordinates[i + 1][1] != coordinates[i][1]) // Verifica se os Ys são iguais
			Yigual = false;

		if(!Xigual && !Yigual) // Se algum valor em X e em Y forem diferentes, saia do loop, pois não é mais necessário
			break;
	}

	if(Xigual || Yigual) // Se X ou Y for igual em todos os pontos, é uma reta
		return true;

	int diferencaX, diferencaY;
	float coeficienteAngularInicial, coeficienteAngularAtual;

	// Para ser uma reta, X e Y devem resultar no mesmo coeficiente angular após serem divididos
	diferencaX = coordinates[1][0] - coordinates[0][0];
	diferencaY = coordinates[1][1] - coordinates[0][1];

	if(diferencaX != 0) // Protege contra divisão com denominador 0
		coeficienteAngularInicial = diferencaY / diferencaX;
	else
		return false;
	
	/* Após calcular o coeficiente angular dos primeiros pontos, deve-se comparar com o resultado do
		coeficiente angular dos próximos pontos*/
	for(unsigned int i = 1; i < numeroDeLinhas - 1; i++) {
		diferencaX = coordinates[i + 1][0] - coordinates[i][0];
		diferencaY = coordinates[i + 1][1] - coordinates[i][1];

		if(diferencaX != 0) // Protege contra divisão com denominador 0
			coeficienteAngularAtual = diferencaY / diferencaX;
		else
			return false;

		if(coeficienteAngularAtual != coeficienteAngularInicial) // Comparação do coeficiente angular inicial
			return false;
	}

	return true;
}

int main() {
	//{{2,4},{2,5},{2,8}}
	//{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}
	//{{0,1},{1,3},{-4,-7},{5,11}}
	vector<vector<int>> coordinates = {{0,1},{1,3},{-4,-7},{5,11}}; // Inicializa vetor de vetores

	cout << checkStraightLine(coordinates);
	
	return 0;
}