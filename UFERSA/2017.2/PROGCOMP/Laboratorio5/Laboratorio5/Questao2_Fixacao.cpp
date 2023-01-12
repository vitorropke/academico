#include <iostream>
using namespace std;

float aumentoSalario(float);

int main()
{
	float salario;

	cout << "Digite seu salário atual: R$";
	cin >> salario;
	cout << "Seu salário com 15% de aumento é de R$" << aumentoSalario(salario) << '\n';

	system("pause");
	return 0;
}

float aumentoSalario(float salario)
{
	return salario + salario * 0.15;
}