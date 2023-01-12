#include <iostream>

using namespace std;

int minOperations(int n) {
	return n * n / 4;
}

int main() {
	cout << minOperations(2);

	return 0;
}