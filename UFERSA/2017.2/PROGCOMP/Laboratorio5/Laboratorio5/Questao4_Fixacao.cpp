#include <iostream>
using namespace std;

void imprimeEAUltima();
void imprimeAEsperancaQueMorre();

int main()
{
	imprimeAEsperancaQueMorre();

	system("pause");
	return 0;
}

void imprimeEAUltima()
{
	cout << "� a �ltima";
}

void imprimeAEsperancaQueMorre()
{
	cout << "A esperan�a ";
	imprimeEAUltima();
	cout << " que morre\n";
}