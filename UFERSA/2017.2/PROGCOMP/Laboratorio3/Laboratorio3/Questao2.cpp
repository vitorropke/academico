#include <iostream>
using namespace std;

int main()
{
	int idade;

	cout << "Digite sua idade: ";
	cin >> idade;
	cout << idade << " anos equivalem a " << idade * 365 << " dias.\n";

	system("pause");
	return 0;
}