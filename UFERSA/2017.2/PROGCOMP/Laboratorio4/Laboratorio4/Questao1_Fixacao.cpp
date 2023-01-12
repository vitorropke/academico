#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float angulo;
	
	cout << "Digite um ângulo: ";
	cin >> angulo;
	cout << "Seno = " << sin(angulo*(3.14159265358979323846/180)) << '\n';

	system("pause");
	return 0;
}