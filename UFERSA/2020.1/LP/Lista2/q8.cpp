#include <bits/stdc++.h>
#include <iostream>
#include <valarray>

using namespace std;

int getSum(int a, int b) {
	valarray<int> vetor = { a, b };

	return vetor.sum();
}

int main() {
	int a = 3, b = 2;

	cout << getSum(a, b);

	return 0;
}
