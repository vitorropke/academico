#include <iostream>
using namespace std;

char charada(char, int);

int main()
{
	cout << charada('<', 20);
	cout << charada('\a', 90);
	cout << charada('(', 72);
	cout << charada('5', 48);
	cout << charada('/j', 107) << '\n';

	system("pause");
	return 0;
}

char charada(char ch, int x)
{
	return ch + x;
}