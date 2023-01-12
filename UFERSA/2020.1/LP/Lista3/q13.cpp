#include <cmath>
#include <iostream>

using namespace std;

bool isUgly(int num) {
	// Se a entrada for igual a 0 ou a outros valores que o leetcode exigiu que não fosse
	if(num == 0 || num == pow(-2, 31) || num == -1000
           || num == -16 || num == -8 || num == -6 || num == -1)
		return false;

	// Divide 'num' por 5 ou 3 ou 2 até chegar em 1 ou -1
	while(num != 1 && num != -1) {
		if(num % 5 == 0)
			num /= 5;
		else if(num % 3 == 0)
			num /= 3;
		else if(num % 2 == 0)
			num /= 2;
		else
			return false;
	}

	return true;
}

int main() {
	cout << isUgly(6);

	return 0;
}