#include <iostream>
using namespace std;

int main()
{
	const int tamanhoDoVetor = 10;
	char vetor1[tamanhoDoVetor] = "Pamonha",
		vetor2[tamanhoDoVetor] = { 'C', 'o', 'm', 'p', 'u', 't', 'a', 'd', 'o', 'r' };

	cout << vetor1 << '\n' << vetor2 << '\n';

	system("pause");
	return 0;
}