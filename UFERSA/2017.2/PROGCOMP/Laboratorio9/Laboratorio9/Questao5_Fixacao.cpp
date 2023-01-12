#include <iostream>
using namespace std;

int main()
{
	double numeroDouble = 245.795;
	int numeroInt = int(numeroDouble);

	cout << "Multiplicando double por 100: " << numeroDouble * 100 << '\n';
	cout << "Multiplicando int por 100: " << numeroInt * 100 << '\n';

	system("pause");
	return 0;
}