// terceiro.cpp � erros de sem�ntica
#include <iostream>
using namespace std;

int main()
{
	int dias;      // declara uma vari�vel inteira
    cout << "Numero de Dias: ";
    cin >> dias;   // l� um valor para a vari�vel
	
	int horas = dias * 24;
    cout << dias << " dias tem " << horas << " horas." << endl;
    
	system("pause"); 
    return 0;
}
