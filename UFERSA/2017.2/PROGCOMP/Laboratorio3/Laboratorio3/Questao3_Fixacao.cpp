#include <iostream>
using namespace std;

int main()
{
	int numero;
	
	cout << "Tabuada de n\n";
	cout << "------------\n";
	cout << "Entre com um n�mero n (0 a 9): ";
	cin >> numero;
	cout << numero << " x 0 = " << numero * 0 << "\n";
	cout << numero << " x 1 = " << numero * 1 << "\n";
	cout << numero << " x 2 = " << numero * 2 << "\n";
	cout << numero << " x 3 = " << numero * 3 << "\n";
	cout << numero << " x 4 = " << numero * 4 << "\n";
	cout << numero << " x 5 = " << numero * 5 << "\n";
	cout << numero << " x 6 = " << numero * 6 << "\n";
	cout << numero << " x 7 = " << numero * 7 << "\n";
	cout << numero << " x 8 = " << numero * 8 << "\n";
	cout << numero << " x 9 = " << numero * 9 << "\n";

	system("pause");
	return 0;
}