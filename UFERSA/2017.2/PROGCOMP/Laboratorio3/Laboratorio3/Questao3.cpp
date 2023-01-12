#include <iostream>
using namespace std;

int main()
{
	int altura, largura, comprimento;

	cout << "Entre com a altura, largura e comprimento: ";
	cin >> altura >> largura >> comprimento;
	cout << "O volume é " << altura * largura * comprimento << "cm³.\n";

	system("pause");
	return 0;
}