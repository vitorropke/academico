#include <stdio.h>

int main()
{
	char senha[7] = "133445", senhaDigitada[20];
	
	printf("Digite a senha: ");
	fgets(senhaDigitada, 20, stdin);
	
	while(strncmp(senha, senhaDigitada, 6))
	{
		printf("\nsenha incorreta\n");
		
		printf("Digite novamente a senha: ");
		fgets(senhaDigitada, 20, stdin);
	}
	
	printf("\nsenha correta\n");
	
	return 0;
}
