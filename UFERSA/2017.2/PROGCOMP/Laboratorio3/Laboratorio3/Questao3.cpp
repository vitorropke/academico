#include <iostream>
using namespace std;

int main()
{
	int altura, largura, comprimento;

	cout << "Entre com a altura, largura e comprimento: ";
	cin >> altura >> largura >> comprimento;
	cout << "O volume � " << altura * largura * comprimento << "cm�.\n";

	system("pause");
	return 0;
}