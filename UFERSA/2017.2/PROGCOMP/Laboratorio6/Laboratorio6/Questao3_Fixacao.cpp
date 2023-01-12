#include <iostream>
int main()
{
	unsigned short x = 1;
	x = x + 32767;
	std::cout << "x = " << x << std::endl;
	system("pause");
}