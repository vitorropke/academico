#include <stdio.h>

int main()
{
	double nota1, nota2, nota3, nota4, media, mediaFinal, precisaDe;
	
	printf("Digite a primeira nota: ");
	scanf("%lf", &nota1);
	printf("Digite a segunda nota: ");
	scanf("%lf", &nota2);
	printf("Digite a terceira nota: ");
	scanf("%lf", &nota3);
	
	media = (2 * nota1 + 3 * nota2 + 4 * nota3) / 9;
	printf("\nMedia = %.1lf\n", media);
	
	if(media < 7)
	{
		if(media < 3.5)
		{
			printf("\nReprovado!\n");
		}
		else
		{
			printf("\nRecuperacao!\n");
			
			precisaDe = (50 - media * 7) / 3;
			
			printf("Voce precisa de %.1lf para ser aprovado\n", precisaDe);
			printf("Digite a quarta nota: ");
			scanf("%lf", &nota4);
			
			mediaFinal = (media * 7 + nota4 * 3) / 10;
			
			printf("\nMedia final = %.2lf\n", mediaFinal);
			
			if(mediaFinal < 5)
			{
				printf("\nReprovado!\n");
			}
			else
			{
				printf("\nAprovado!\n");
			}
		}
	}
	else
	{
		printf("\nAprovado!\n");
	}
	
	return 0;
}
