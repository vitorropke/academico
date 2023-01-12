#include <iostream>
using namespace std;

#define SEGUNDOSEMUMANO 3.156E+7

float anosParaSegundos(int);

int main()
{
	int idade;

	cout << "Digite sua idade em anos: ";
	cin >> idade;
	cout << idade << " anos equivalem a " << anosParaSegundos(idade) << " segundos.\n";

	system("pause");
	return 0;
}

float anosParaSegundos(int idade)
{
	return SEGUNDOSEMUMANO * idade;
}