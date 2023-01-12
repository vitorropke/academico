#include <iostream>
using namespace std;

int main()
{
	double x1, x2;
	int soma;

	cout << "Digite o valor x1: ";
	cin >> x1;
	cout << "Digite o valor x2: ";
	cin >> x2;
	soma = int(x1) + int(x2);
	cout << "A adição inteira dos valores é " << soma << ".\n";

	system("pause");
	return 0;
}