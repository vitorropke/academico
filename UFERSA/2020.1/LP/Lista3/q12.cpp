#include <cmath>
#include <iostream>

using namespace std;

bool isPerfectSquare(int num) {
	// Converte a raiz para inteiro e depois para double novamente
	int intRaiz = sqrt(num);
	double doubleRaiz = intRaiz;

	// Se após a dupla conversão for a mesma coisa
	if(doubleRaiz == sqrt(num))
		return true;
	else
		return false;
}

int main() {
	cout << isPerfectSquare(1);

	return 0;
}