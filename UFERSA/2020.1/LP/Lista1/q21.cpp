#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int entradas[4];

	for(unsigned int i = 0; i < 4; i++) {
		cin >> entradas[i];
	}

	for(unsigned int i = 0; i < 4; i++) {
		if(entradas[i] < 1 || entradas[i] > 100){
			cout << 'N' << '\n';
			return 0;
		}
	}

	sort(entradas, entradas + 4);

	if(
			(entradas[0] < entradas[1] + entradas[2]) &&
			(entradas[1] < entradas[0] + entradas[2]) &&
			(entradas[2] < entradas[0] + entradas[1])
	) {
		cout << 'S' << '\n';
		return 0;
	}
	if(
			(entradas[1] < entradas[2] + entradas[3]) &&
			(entradas[2] < entradas[1] + entradas[3]) &&
			(entradas[3] < entradas[1] + entradas[2])
	) {
		cout << 'S' << '\n';
		return 0;
	}

	cout << 'N' << '\n';
	return 0;
}
