#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isBoomerang(vector<vector<int>>& points) {
	unsigned int numeroDeLinhas = points.size();

	sort(points.begin(), points.end()); // Ordena o vetor para verificar se existem elementos repetidos

	for(unsigned int i = 0; i < numeroDeLinhas - 1; i++) {
		if(points[i] == points[i + 1]) // Verifica se existem elementos repetidos (X e Y iguais)
			return false;
	}

	bool Xigual = true, Yigual = true;

	// Verifica se a reta é perpendicular em algum eixo
	for(unsigned int i = 0; i < numeroDeLinhas - 1; i++) {
		if(points[i + 1][0] != points[i][0]) // Verifica se os Xs são iguais
			Xigual = false;
		
		if(points[i + 1][1] != points[i][1]) // Verifica se os Ys são iguais
			Yigual = false;

		if(!Xigual && !Yigual) // Se algum valor em X e em Y forem diferentes, saia do loop, pois não é mais necessário
			break;
	}

	if(Xigual || Yigual) // Se X ou Y for igual em todos os pontos, é uma reta. Não um boomerang
		return false;
	
	int diferencaX, diferencaY;
	float coeficienteAngularInicial, coeficienteAngularAtual;

	// Para ser uma reta, X e Y devem resultar no mesmo coeficiente angular após serem divididos
	diferencaX = points[1][0] - points[0][0];
	diferencaY = points[1][1] - points[0][1];

	if(diferencaX != 0) // Protege contra divisão com denominador 0
		coeficienteAngularInicial = float(diferencaY) / float(diferencaX);
	else
		return true;
	
	/* Após calcular o coeficiente angular dos primeiros pontos, deve-se comparar com o resultado do
		coeficiente angular dos próximos pontos*/
	for(unsigned int i = 1; i < numeroDeLinhas - 1; i++) {
		diferencaX = points[i + 1][0] - points[i][0];
		diferencaY = points[i + 1][1] - points[i][1];
		
		if(diferencaX != 0) // Protege contra divisão com denominador 0
			coeficienteAngularAtual = float(diferencaY) / float(diferencaX);
		else
			return true;

		if(coeficienteAngularAtual != coeficienteAngularInicial) // Comparação do coeficiente angular inicial
			return true;
	}

	return false;
}

int main() {
	//{{2,4},{2,5},{2,8}}
	//{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}
	//{{0,1},{1,3},{-4,-7},{5,11}}
	//{{1,1},{2,3},{3,2}}
	//{{52,86},{12,65},{24,71}}
	vector<vector<int>> coordinates = {{52,86},{12,65},{24,71}}; // Inicializa vetor de vetores

	cout << isBoomerang(coordinates);
	
	return 0;
}