#include <iostream>
using namespace std;

int main()
{
	float lado1, lado2, areaBase, altura, volume;

	cout << "Digite o lado 1 da base do prisma: ";
	cin >> lado1;
	cout << "Digite o lado 2 da base do prisma: ";
	cin >> lado2;
	areaBase = lado1 * lado2;
	cout << "�rea da base � " << areaBase << "\n";
	cout << "Digite a altura do prisma: ";
	cin >> altura;
	volume = areaBase * altura;
	cout << "Volume do prisma � " << volume << "\n";

	system("pause");
	return 0;
}