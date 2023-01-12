#include <iostream>
using namespace std;

char ultimoCaractere(char[]);

int main()
{
	char vetor[10];

	cout << "Digite uma palavra: ";
	cin >> vetor;
	cout << "Em " << vetor << " a última letra é " << ultimoCaractere(vetor) << ".\n";

	system("pause");
	return 0;
}

char ultimoCaractere(char vetor[])
{
	int tamanho = strlen(vetor);
	
	return vetor[tamanho - 1];
}