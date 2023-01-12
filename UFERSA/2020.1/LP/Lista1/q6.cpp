#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
	// Primeiro verifica os tamanhos das strings
	if(s.length() != t.length())
		return false;

	// Ordena as strings em ordem alfabética
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	// Se as strings forem iguais, aceita.
	if(s == t)
		return true;
	else
		return false;
}

int main() {
	string entrada1, entrada2;

	//getline(cin, entrada1);
	//getline(cin, entrada2);

	entrada1 = "aabbcc";
	entrada2 = "ccbaba";

	bool status = isAnagram(entrada1, entrada2);

	cout << status;

	return 0;
}
