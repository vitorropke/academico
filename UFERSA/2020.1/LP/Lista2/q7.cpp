#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if(nums.size() == 1)
		return 1;

	vector<int>::iterator apagarInicio, apagarFim;
	bool numeroIgual = false;
	unsigned int salvaJ = 0, indice = 0;

	// Procure pelos valores repetidos
	for(unsigned int i = 0; i < nums.size(); i++) {
		for(unsigned int j = i + 1; j < nums.size(); j++) {
			if(nums[i] == nums[j]) {
				apagarInicio = nums.begin() + i; // Salva o início da cadeia de números iguais
				numeroIgual = true;
				salvaJ = j;
			}
			// Quando encontra um número diferente, sai do loop interno
			else
				break;
		}
		if(numeroIgual) { // Caso o loop interno tenha encontrado um número igual
			apagarFim = nums.begin() + salvaJ; // Salva o final da cadeia de números iguais
			nums.erase(apagarInicio, apagarFim); // ele apaga neste intervalo
			numeroIgual = false;
		}
	}

	return nums.size();
}

int main() {
	vector<int> vetor;

	vetor.push_back(0);
	vetor.push_back(0);
	vetor.push_back(1);
	vetor.push_back(1);
	vetor.push_back(1);
	vetor.push_back(2);
	vetor.push_back(2);
	vetor.push_back(3);
	vetor.push_back(3);
	vetor.push_back(4);

	for(unsigned int i = 0; i < vetor.size(); i++)
			cout << vetor[i];

	cout << '\n';
	cout << removeDuplicates(vetor);
	cout << '\n';

	for(unsigned int i = 0; i < vetor.size(); i++)
		cout << vetor[i];

	return 0;
}
