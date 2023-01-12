// CalcMedia.cpp - calcula a media das avaliações
#include <iostream>
int main()
{
	using namespace std;

	float n1, n2, n3, n4, media, mediaFinal;

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
	if (media < 7)
	{
		cout << "Digite a nota 4: ";
		cin >> n4;
		cout << endl;
		mediaFinal = (media * 7 + n4 * 3) / 10;
		cout << "A media final: " << mediaFinal;
	}
	cout << endl;

	system("pause");
	return 0;
}