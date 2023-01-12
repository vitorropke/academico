#include <iostream>
using namespace std;

int somaDosElementos(int[]);

int main()
{
	int vetor[5];

	cout << "Digite 5 valores: ";
	cin >> vetor[0] >> vetor[1] >> vetor[2] >> vetor[3] >> vetor[4];
	cout << "A soma do vetor é " << somaDosElementos(vetor) << ".\n";

	system("pause");
	return 0;
}

int somaDosElementos(int vetor[])
{
	return vetor[0] + vetor[1] + vetor[2] + vetor[3] + vetor[4];
}