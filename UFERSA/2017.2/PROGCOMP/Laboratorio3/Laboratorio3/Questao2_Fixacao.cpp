#include <iostream>
using namespace std;

int main()
{
	int numeroAnos, quantidadeCigarros;
	float precoCarteira;

	cout << "A quantos anos voc� fuma? ";
	cin >> numeroAnos;
	cout << "Quantos cigarros voc� fuma por dia? ";
	cin >> quantidadeCigarros;
	cout << "Qual o pre�o m�dio de uma carteira de cigarros? ";
	cin >> precoCarteira;
	cout << "Voc� gastou at� agora R$ " << numeroAnos * 365 * quantidadeCigarros * (precoCarteira / 20)
		<< " com cigarros.\n";

	system("pause");
	return 0;
}