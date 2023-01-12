#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int decimal;
	string entrada;
	
	cin >> entrada;

	while(entrada[0] != '-') {
		if(entrada[1] == 'x') {												// Hex para decimal	
			stringstream hexParaInt;

			hexParaInt << entrada; // Entrada para hex
			hexParaInt >> hex >> decimal; // Hex para decimal

			cout << decimal << '\n';
		}else { 															// Decimal para hex
			stringstream intParaHex, stringParaInt(entrada); // String para decimal
			stringParaInt >> decimal;			 // String para decimal

			intParaHex << hex << decimal; // Entrada para hex
			
			string saidaHex(intParaHex.str()); // Hex para string

			// Troca as letras minúsculas, por letras maiúsculas
			for(unsigned int i = 0; i < saidaHex.length(); i++) {
				if(saidaHex[i] == 'a')
					saidaHex[i] = 'A';
				else if(saidaHex[i] == 'b')
					saidaHex[i] = 'B';
				else if(saidaHex[i] == 'c')
					saidaHex[i] = 'C';
				else if(saidaHex[i] == 'd')
					saidaHex[i] = 'D';
				else if(saidaHex[i] == 'e')
					saidaHex[i] = 'E';
				else if(saidaHex[i] == 'f')
					saidaHex[i] = 'F';
			}

			cout << "0x" << saidaHex << '\n';
		}

		cin >> entrada;
	}

	return 0;
}