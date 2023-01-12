// CalcMedia.cpp - calcula a media das avaliações
#include <iostream>
int main()
{
	using namespace std;

	float n1, n2, n3, media;

	cout << "Calculando a media" << endl;
	cout << "------------------" << endl;
	cout << endl;
	cout << "Digite a nota 1: ";
	cin >> n1;
	cout << "Digite a nota 2: ";
	cin >> n2;
	cout << "Digite a nota 3: ";
	cin >> n3;
	cout << endl;
	media = (n1 * 2 + n2 * 3 + n3 * 4) / 9;
	cout << "A media das notas: " << media;
	cout << endl;

	system("pause");
	return 0;
}