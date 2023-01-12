#include <iostream>
using namespace std;
void auxiliar(void);
void outra(void);
int main(void)
{
	cout << "Um programa em C++, sempre começa pela função main.\n";
	outra();
	auxiliar();
	system("pause");
	return 0;
}
void auxiliar(void)
{
	cout << "Funções auxiliares podem ser invocadas";
	cout << " a partir da função main.\n";
}
void outra(void)
{
	auxiliar();
	cout << "Funções também podem ser invocadas";
	cout << " a partir de outras funções.\n";
}