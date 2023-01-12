#include <iostream>

using namespace std;

void imprimirTracos(int numero, char traco)
{
	for (int x = 0; x < numero; x++)
		cout << traco;
}

void imprimirAtributos(void)
{
	cout << "1. Preco\n";
	cout << "2. Quantidade produzida\n";
	cout << "3. Ano do primeiro voo\n";
	cout << "4. Numero de passageiros\n";
	cout << "5. Massa (vazio) (milhares de Kg)\n";
	cout << "6. Quantidade de motores\n";
	cout << "7. Velocidade maxima (Km/h)\n";
	cout << "8. Velocidade cruzeiro (Km/h)\n";
	cout << "9. Alcance (Km)\n";
	cout << "10. Teto maximo (metros)\n";
}