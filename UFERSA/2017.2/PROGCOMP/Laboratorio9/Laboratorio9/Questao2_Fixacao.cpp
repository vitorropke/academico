#include <iostream>
using namespace std;

int main()
{
	int x, y;

	cout << "Digite dois números inteiros: ";
	cin >> x >> y;
	cout << "O quociente " << x << '/' << y << " é " << x / y << '\n';
	cout << "O resto da divisão " << x << '%' << y << " é " << x % y << '\n';

	system("pause");
	return 0;
}