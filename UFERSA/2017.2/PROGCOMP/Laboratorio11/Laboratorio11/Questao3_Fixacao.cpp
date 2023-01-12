#include <iostream>
#include <string>
using namespace std;

int main()
{
	string nome, data, stringConcatenada;

	cout << "Nome: ";
	cin >> nome;
	cout << "Data: ";
	cin >> data;
	stringConcatenada = nome + " esteve aqui em " + data;
	cout << stringConcatenada << ".\n";

	system("pause");
	return 0;
}