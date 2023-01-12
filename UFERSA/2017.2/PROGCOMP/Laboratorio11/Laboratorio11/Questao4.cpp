#include <iostream>
using namespace std;

int main()
{
	char nome[] = "C++ Primer Plus";

	cout << "Esse vetor possui " << strlen(nome) << " caracteres e " << sizeof(nome) << " bytes.\n";

	system("pause");
	return 0;
}