#include <iostream>
using namespace std;

void equacaoSegundoGrau(float, float, float);

int main()
{
	float a, b, c;

	cout << "Digite os valores para a, b e c respectivamente: ";
	cin >> a >> b >> c;
	equacaoSegundoGrau(a, b, c);

	system("pause");
	return 0;
}

void equacaoSegundoGrau(float a, float b, float c)
{
	float delta = b * b - 4 * a * c;

	if (delta >= 0)
	{
		if (delta < 1)
			cout << "Possui somente 1 raíz\nX1 = " << -b / (2 * a) << '\n';
		else
			cout << "Possui 2 raízes:\n"
			<< "X1 = " << (-b + sqrt(delta)) / (2 * a) << '\n'
			<< "X2 = " << (-b - sqrt(delta)) / (2 * a) << '\n';
	}
	else
		cout << "Não tem raízes reais!\n";
}