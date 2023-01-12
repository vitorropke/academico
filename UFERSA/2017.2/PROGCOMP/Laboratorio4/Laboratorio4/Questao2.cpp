#include <iostream>
using namespace std;

void umTres();
void dois();

int main()
{
	cout << "Começando agora:\n";
	umTres();
	cout << "\nPronto!\n";

	system("pause");
	return 0;
}

void umTres()
{
	cout << "Um ";
	dois();
	cout << " Três";
}

void dois()
{
	cout << "Dois";
}