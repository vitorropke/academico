#include <iostream>
using namespace std;

int main()
{
	int vetor[5] = {}, posicao;

	cout << "Vetor: " << vetor[0] << ' ' << vetor[1] << ' ' << vetor[2] << ' ' << vetor[3] << ' '
		<< vetor[4] << '\n'
		<< "Qual posi��o deseja modificar: ";
	cin >> posicao;
	cout << "Qual n�mero deseja colocar a�: ";
	cin >> vetor[posicao-1];
	cout << "Vetor: " << vetor[0] << ' ' << vetor[1] << ' ' << vetor[2] << ' ' << vetor[3] << ' '
		<< vetor[4] << '\n';

	system("pause");
	return 0;
}