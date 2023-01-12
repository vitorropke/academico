#include <iostream>
using namespace std;

int main()
{
	int numeroAnos, quantidadeCigarros;
	float precoCarteira;

	cout << "A quantos anos você fuma? ";
	cin >> numeroAnos;
	cout << "Quantos cigarros você fuma por dia? ";
	cin >> quantidadeCigarros;
	cout << "Qual o preço médio de uma carteira de cigarros? ";
	cin >> precoCarteira;
	cout << "Você gastou até agora R$ " << numeroAnos * 365 * quantidadeCigarros * (precoCarteira / 20)
		<< " com cigarros.\n";

	system("pause");
	return 0;
}