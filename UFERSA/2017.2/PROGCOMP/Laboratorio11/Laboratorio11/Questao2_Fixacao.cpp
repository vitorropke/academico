#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sNumero;
	int iNumero;

	cout << "Entre com dois números: ";
	cin >> sNumero >> iNumero;
	cout << "A multiplicação entre eles é " << std::stoi(sNumero) * iNumero << '\n';

	system("pause");
	return 0;
}