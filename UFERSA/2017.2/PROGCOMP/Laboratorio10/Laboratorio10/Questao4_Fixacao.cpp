#include <iostream>
using namespace std;

int main()
{
	int vetor[5] = { 10, 20, 30, 40, 50 };

	for (int x = 0; x <= 5; ++x)
		vetor[x] = 60;

	for (int x = 0; x <= 5; ++x)
		cout << vetor[x] << ' ';

	system("pause");
	return 0;
}