#include <iostream>
using namespace std;

float aumentoSalario(float);

int main()
{
	float salario;

	cout << "Digite seu sal�rio atual: R$";
	cin >> salario;
	cout << "Seu sal�rio com 15% de aumento � de R$" << aumentoSalario(salario) << '\n';

	system("pause");
	return 0;
}

float aumentoSalario(float salario)
{
	return salario + salario * 0.15;
}