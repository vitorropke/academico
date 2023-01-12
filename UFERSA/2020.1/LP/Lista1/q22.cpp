#include <iostream>

using namespace std;

int main () {
	unsigned int entrada, casos = 0, numerosAcumulados = 0;
	string numeros = "";
	
	while (scanf("%d", &entrada) != EOF) {
		// Encerra o programa, caso encontre uma entrada > 200 e menor que 0.
		if(entrada > 200)
			return 0;

		// Salva os números em uma string
		for(unsigned int i = 0; i <= entrada; i++) {
			// Salva várias vezes o mesmo número, caso seja >= 2
			if(i == 0) {
				if(i + 1 > entrada) { // Coloca um espaço se não for o final
					numerosAcumulados++;
					numeros += "0\n\n";
				}else {
					numerosAcumulados++;
					numeros += "0 ";
				}
			}else {
				for(unsigned int j = 0; j < i; j++){
					// Coloca um espaço se não for o final
					if(i + 1 > entrada && j + 1 == i){
						numerosAcumulados++;
						numeros += to_string(i);
						numeros += "\n\n";
					}
					else {
						numerosAcumulados++;
						numeros += to_string(i);
						numeros += " ";
					}
				}
			}
		}

		// Saída
		casos++;
		cout << "Caso " << casos << ": ";
		cout << numerosAcumulados;
		
		if(numerosAcumulados == 1)
			cout << " numero\n";
		else
			cout << " numeros\n";
		
		cout << numeros;

		// Reseta valores
		numeros = "";
		numerosAcumulados = 0;
	}

	return 0;
}
