#include <iostream>
#include <string>
using namespace std;

int main()
{
	string feriado1, feriado2, feriado3, feriado4 = "Natal", stringsConcatenadas;

	cout << "Quais suas datas comemorativas preferidas?\n";
	cin >> feriado1 >> feriado2 >> feriado3;
	stringsConcatenadas = feriado1 + ", " + feriado2 + " e " + feriado3 + " são belas festas.\n";
	if ((feriado1 == feriado4) or (feriado2 == feriado4) or (feriado3 == feriado4))
		cout << "O Natal também é uma das minhas datas preferidas!\n";

	system("pause");
	return 0;
}