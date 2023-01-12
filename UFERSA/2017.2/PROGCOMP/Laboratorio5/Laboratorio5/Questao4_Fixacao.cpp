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
	cout << "é a última";
}

void imprimeAEsperancaQueMorre()
{
	cout << "A esperança ";
	imprimeEAUltima();
	cout << " que morre\n";
}