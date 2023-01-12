#include <stdio.h>

int main()
{
	char senha[7] = "133445", senhaDigitada[20];
	
	do
	{
		printf("Digite a senha: ");
		fgets(senhaDigitada, 20, stdin);
		
		if(strncmp(senha, senhaDigitada, 6))
		{
			printf("\nsenha incorreta\n");
		}
	}while(strncmp(senha, senhaDigitada, 6));
	
	printf("\nsenha correta\n");
	
	return 0;
}
