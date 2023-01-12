#include <iostream>
#include <cmath>
using namespace std;

float subtracaoEQuadradoDeX(float, float);
float subtracaoEQuadradoDeY(float, float);

int main()
{
	float pX, pY, qX, qY;

	cout << "Ponto P:\n";
	cin >> pX >> pY;
	cout << "Ponto Q:\n";
	cin >> qX >> qY;
	cout << "A distancia entre P e Q é: ";
	cout << sqrt(subtracaoEQuadradoDeX(pX, qX) + subtracaoEQuadradoDeY(pY, qY));
	cout << '\n';
	
	system("pause");
	return 0;
}

float subtracaoEQuadradoDeX(float pontoP, float pontoQ)
{
	return pow((pontoQ - pontoP), 2);
}

float subtracaoEQuadradoDeY(float pontoP, float pontoQ)
{
	return pow((pontoQ - pontoP), 2);
}