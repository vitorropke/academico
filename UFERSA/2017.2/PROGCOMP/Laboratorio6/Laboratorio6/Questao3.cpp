#include <iostream>
using namespace std;

int main()
{
	short varShort;
	int varInt;
	long varLong;
	long long varLongLong;

	cout << left; cout.width(12); cout << "short:" << sizeof varShort << " bytes\n";
	cout << left; cout.width(12); cout << "int:" << sizeof varInt << " bytes\n";
	cout << left; cout.width(12); cout << "long:" << sizeof varLong << " bytes\n";
	cout << left; cout.width(12); cout << "long long:" << sizeof varLongLong << " bytes\n";
	cout << "Total de bytes usados: " << sizeof varShort + sizeof varInt + sizeof varLong
		+ sizeof varLongLong << '\n';

	system("pause");
	return 0;
}