#include <iostream>
using namespace std;
void auxiliar(void);
void outra(void);
int main(void)
{
	cout << "Um programa em C++, sempre come�a pela fun��o main.\n";
	outra();
	auxiliar();
	system("pause");
	return 0;
}
void auxiliar(void)
{
	cout << "Fun��es auxiliares podem ser invocadas";
	cout << " a partir da fun��o main.\n";
}
void outra(void)
{
	auxiliar();
	cout << "Fun��es tamb�m podem ser invocadas";
	cout << " a partir de outras fun��es.\n";
}