#include <iostream>
using namespace std;

int main()
{
	int vetA[5] = { 10, 20, 30, 40, 50 }, vetB[5] = { 10, 20 }, vetC[5] = { 0, 0, 30 };

	cout << "Vetor A: " << vetA[0] << ' ' << vetA[1] << ' ' << vetA[2] << ' ' << vetA[3] << ' '
		<< vetA[4] << '\n'
		<< "Vetor B: " << vetB[0] << ' ' << vetB[1] << ' ' << vetB[2] << ' ' << vetB[3] << ' '
		<< vetB[4] << '\n'
		<< "Vetor C: " << vetC[0] << ' ' << vetC[1] << ' ' << vetC[2] << ' ' << vetC[3] << ' '
		<< vetC[4] << '\n';

	system("pause");
	return 0;
}