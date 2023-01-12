#include <iostream>

using namespace  std;

int countVowelStrings(int n) {
	unsigned int combinacoes = 1;
	
	// nCr = (n + m - 1)! / [ (m!) * (n - 1)! ]
	for(unsigned int i = n + 1; i <= 4 + n; i++)
		combinacoes *= i;
	
	return combinacoes / 24;  // 24 = 4!
}

int main() {
	cout << countVowelStrings(2);

	return 0;
}