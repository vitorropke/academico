#include <iostream>
using namespace std;

int main()
{
	float precoCarroFabrica;

	cout << "Digite o valor monetário do veículo que acabou de sair da fábrica em reais: R$";
	cin >> precoCarroFabrica;
	cout << "Preço final junto com impostos e acréscimo do distribuidor: R$" << precoCarroFabrica +
		precoCarroFabrica * 0.28 + precoCarroFabrica * 0.45 << "\n";

	system("pause");
	return 0;
}