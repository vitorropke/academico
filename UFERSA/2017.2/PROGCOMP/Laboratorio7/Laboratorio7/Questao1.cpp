#include <iostream>
using namespace std;

char caractereNumerico(int);

int main()
{
	cout << caractereNumerico(80) << caractereNumerico(114) << caractereNumerico(111)
		<< caractereNumerico(103) << caractereNumerico(67) << caractereNumerico(111)
		<< caractereNumerico(109) << caractereNumerico(112) << '\n';

	system("pause");
	return 0;
}

char caractereNumerico(int numero)
{
	return numero;
}