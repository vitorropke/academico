#include <iostream>
using namespace std;

void imprimeSorria();

int main()
{
	imprimeSorria(); cout << ' '; imprimeSorria(); cout << ' '; imprimeSorria(); cout << ' ';
	imprimeSorria(); cout << '\n';
	imprimeSorria(); cout << ' '; imprimeSorria(); cout << '\n';
	imprimeSorria(); cout << '\n';

	system("pause");
	return 0;
}

void imprimeSorria()
{
	cout << "Sorria!";
}