#include <iostream>
using namespace std;
int main()
{
	cout << left; cout.width(12); cout << "Produto";
	cout << left; cout.width(15); cout << "Preco/Kg";
	cout.width(15); cout << "Pedido (Kg)";
	cout.width(8); cout << "Total Parcial" << endl;
	cout << left; cout.width(12); cout << "-------";
	cout << left; cout.width(15); cout << "--------";
	cout.width(15); cout << "-----------";
	cout.width(8); cout << "-------------" << endl;
	cout << left; cout.width(12); cout << "Alface";
	cout << left; cout.width(15); cout << "R$ 1,25/Kg";
	cout.width(15); cout << "3,2Kg";
	cout.width(8); cout << "R$ 4,00" << endl;
	cout << left; cout.width(12); cout << "Beterraba";
	cout << left; cout.width(15); cout << "R$ 0,65/Kg";
	cout.width(15); cout << "6,0Kg";
	cout.width(8); cout << "R$ 3,90" << endl;
	cout << left; cout.width(12); cout << "Cenoura";
	cout << left; cout.width(15); cout << "R$ 0,90/Kg";
	cout.width(15); cout << "10Kg";
	cout.width(8); cout << "R$ 9,00" << endl;

	system("pause");
	return 0;
}