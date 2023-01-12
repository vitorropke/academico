#include <iostream>
using namespace std;

int main()
{
	const int tamanhoDoVetor = 50;
	char nome[tamanhoDoVetor], conceito;

	cout << "Qual é o nome? ";
	cin.getline(nome, tamanhoDoVetor);
	cout << "Que conceito você merece? ";
	cin >> conceito;
	conceito += 1;
	cout << "\nBom dia " << nome << ", seu conceito é " << conceito << ".\n";

	system("pause");
	return 0;
}