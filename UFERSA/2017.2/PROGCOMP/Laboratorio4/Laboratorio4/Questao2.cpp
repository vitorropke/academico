#include <iostream>
using namespace std;

void umTres();
void dois();

int main()
{
	cout << "Come�ando agora:\n";
	umTres();
	cout << "\nPronto!\n";

	system("pause");
	return 0;
}

void umTres()
{
	cout << "Um ";
	dois();
	cout << " Tr�s";
}

void dois()
{
	cout << "Dois";
}