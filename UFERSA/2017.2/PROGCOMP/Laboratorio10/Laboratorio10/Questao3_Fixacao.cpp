#include <iostream>
using namespace std;

double operacao(double[]);

int main()
{
	double vetor[3];

	cout << "Digite 3 n�meros: ";
	cin >> vetor[0] >> vetor[1] >> vetor[2];
	cout << "Resultado da opera��o: " << operacao(vetor) << '\n';

	system("pause");
	return 0;
}

double operacao(double vetor[])
{
	return vetor[0] * vetor[2] - vetor[1];
}