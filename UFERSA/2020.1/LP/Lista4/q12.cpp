#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	unsigned int numeroDegraus, alturaDegrau, comprimentoDegrau, larguraDegrau;
	float hipotenusa;

	while(cin >> numeroDegraus >> alturaDegrau >> comprimentoDegrau >> larguraDegrau) {
		// Início dos constraints
		if(numeroDegraus < 1 || numeroDegraus > 1000 || alturaDegrau < 1 || larguraDegrau > 100)
			return 0;
		// Fim dos constraints

		// Cálculo da hipotenusa
		hipotenusa = sqrt((alturaDegrau * alturaDegrau) + (comprimentoDegrau * comprimentoDegrau));

		// Cálculo da área de cada degrau, multiplicado pelo número de degraus
		cout << setprecision(4) << fixed <<
		(hipotenusa * larguraDegrau * numeroDegraus) / 10000 << '\n';
	}

	return 0;
}