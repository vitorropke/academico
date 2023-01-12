#include <iostream>
#include <string>
using namespace std;

int main()
{
	string senha = "ropke123", senhaUsuario;

	cout << "Digite a senha: ";
	cin >> senhaUsuario;

	if (senha == senhaUsuario)
		cout << "Senha correcta!\n";
	else
		cout << "Senha incorrecta!\n";

	system("pause");
	return 0;
}