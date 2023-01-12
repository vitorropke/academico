#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int numeroCasos;
	unsigned short numeroAlunos;

	cin >> numeroCasos;

	for(unsigned int i = 0; i < numeroCasos; i++) { // Percorre o número de casos
		cin >> numeroAlunos;

		// Verifica se o número de alunos é maior que 1000 ou menor que 1
		if(numeroAlunos > 1000 || numeroAlunos < 1)
			return 0;

		vector<unsigned short> notaAlunos, filaOrdenada; // Declaração dos vetores ordenado e não ordenado
		unsigned short nota;

		for(unsigned int j = 0; j < numeroAlunos; j++) { // Inserção das notas dos alunos
			cin >> nota;

			// Verifica que a nota do aluno i é maior que 100 ou menor que 1
			if(nota > 1000 || nota < 1)
				return 0;

			notaAlunos.push_back(nota);
		}

		unsigned short alunosEstaticos = 0;

		filaOrdenada = notaAlunos;
		sort(filaOrdenada.begin(), filaOrdenada.end(), greater<int>()); // Ordena decrescente

		for(unsigned int j = 0; j < numeroAlunos; j++) { // Verifica as posições que não mudaram
			if(filaOrdenada[j] == notaAlunos[j])
				alunosEstaticos++;
		}

		cout << alunosEstaticos << '\n';
	}

	return 0;
}
