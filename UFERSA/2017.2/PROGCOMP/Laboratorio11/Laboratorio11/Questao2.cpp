#include <iostream>
using namespace std;

int main()
{
	const int tamanhoDoVetor = 50;
	char nome[tamanhoDoVetor], conceito;

	cout << "Qual � o nome? ";
	cin.getline(nome, tamanhoDoVetor);
	cout << "Que conceito voc� merece? ";
	cin >> conceito;
	conceito += 1;
	cout << "\nBom dia " << nome << ", seu conceito � " << conceito << ".\n";

	system("pause");
	return 0;
}