#include <iostream>
using namespace std;

int main()
{
	int metros;
	const int metrosEmUmQuilometro = 1000;

	cout << "Entre com a distância em metros: ";
	cin >> metros;
	cout << metros << " metros equivalem a " << metros / metrosEmUmQuilometro << " quilômetros e "
		<< metros % metrosEmUmQuilometro << " metros.\n";

	system("pause");
	return 0;
}