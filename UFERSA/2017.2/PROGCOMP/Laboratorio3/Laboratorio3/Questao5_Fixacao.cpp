#include <iostream>
using namespace std;

int main()
{
	float precoCarroFabrica;

	cout << "Digite o valor monet�rio do ve�culo que acabou de sair da f�brica em reais: R$";
	cin >> precoCarroFabrica;
	cout << "Pre�o final junto com impostos e acr�scimo do distribuidor: R$" << precoCarroFabrica +
		precoCarroFabrica * 0.28 + precoCarroFabrica * 0.45 << "\n";

	system("pause");
	return 0;
}