#include <iostream>
using namespace std;

int main()
{
	int x, y;

	cout << "Digite dois n�meros inteiros: ";
	cin >> x >> y;
	cout << "O quociente " << x << '/' << y << " � " << x / y << '\n';
	cout << "O resto da divis�o " << x << '%' << y << " � " << x % y << '\n';

	system("pause");
	return 0;
}