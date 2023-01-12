#include <iostream>
using namespace std;

int main()
{
	int vetor[5] = {}, posicao;

	cout << "Vetor: " << vetor[0] << ' ' << vetor[1] << ' ' << vetor[2] << ' ' << vetor[3] << ' '
		<< vetor[4] << '\n'
		<< "Qual posição deseja modificar: ";
	cin >> posicao;
	cout << "Qual número deseja colocar aí: ";
	cin >> vetor[posicao-1];
	cout << "Vetor: " << vetor[0] << ' ' << vetor[1] << ' ' << vetor[2] << ' ' << vetor[3] << ' '
		<< vetor[4] << '\n';

	system("pause");
	return 0;
}