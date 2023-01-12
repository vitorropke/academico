#include <iostream>
using namespace std;

#define MASSAMOLECULADEAGUA  3E-23
#define MASSADEUMQUARTODEGALAODEAGUA 950

float quantidadeDeMoleculasDeAgua(float);

int main()
{
	float quantidadeDeGaloesDeAgua;

	cout << "Digite a quantidade de gal�es de �gua: ";
	cin >> quantidadeDeGaloesDeAgua;
	cout << "Em " << quantidadeDeGaloesDeAgua << " gal�es existem "
		<< quantidadeDeMoleculasDeAgua(quantidadeDeGaloesDeAgua) << " mol�culas de �gua.\n";

	system("pause");
	return 0;
}

float quantidadeDeMoleculasDeAgua(float quantidadeDeGaloesDeAgua)
{
	float quantidadeDeMoleculasEmUmGalao = (MASSADEUMQUARTODEGALAODEAGUA * 4) / MASSAMOLECULADEAGUA;

	return quantidadeDeMoleculasEmUmGalao * quantidadeDeGaloesDeAgua;
}