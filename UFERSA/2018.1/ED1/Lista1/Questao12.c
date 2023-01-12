#include <stdio.h>

int main()
{
	double conta1 = 100, conta2 = 100, valor;
	
	printf("Digite quanto desejas tranferir: ");
	scanf("%lf", &valor);
	
	if(valor > conta1)
	{
		printf("\nSaldo insuficiente\n");
	}
	else
	{
		printf("\nTranferencia feita com sucesso\n");
		conta1 -= valor;
		conta2 += valor;
	}
	printf("\nConta 1 = R$%.2lf\n", conta1);
	printf("Conta 2 = R$%.2lf\n", conta2);
	
	return 0;
}
