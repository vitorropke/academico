#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sNumero;
	int iNumero;

	cout << "Entre com dois n�meros: ";
	cin >> sNumero >> iNumero;
	cout << "A multiplica��o entre eles � " << std::stoi(sNumero) * iNumero << '\n';

	system("pause");
	return 0;
}