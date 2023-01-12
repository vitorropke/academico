#include <iostream>
using namespace std;

#define MASSAMOLECULADEAGUA  3E-23
#define MASSADEUMQUARTODEGALAODEAGUA 950

float quantidadeDeMoleculasDeAgua(float);

int main()
{
	float quantidadeDeGaloesDeAgua;

	cout << "Digite a quantidade de galões de água: ";
	cin >> quantidadeDeGaloesDeAgua;
	cout << "Em " << quantidadeDeGaloesDeAgua << " galões existem "
		<< quantidadeDeMoleculasDeAgua(quantidadeDeGaloesDeAgua) << " moléculas de água.\n";

	system("pause");
	return 0;
}

float quantidadeDeMoleculasDeAgua(float quantidadeDeGaloesDeAgua)
{
	float quantidadeDeMoleculasEmUmGalao = (MASSADEUMQUARTODEGALAODEAGUA * 4) / MASSAMOLECULADEAGUA;

	return quantidadeDeMoleculasEmUmGalao * quantidadeDeGaloesDeAgua;
}