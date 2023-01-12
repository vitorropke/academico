#include <stdio.h>

typedef struct sFicha
{
	char nome[100];
	int idade;
	char sexo;
	float peso;
	float altura;
} tFicha;

int main()
{
	tFicha *pessoas;
	int contador, numeroDePessoas;
	float IMC[3];
	
	printf("Digite o números de pessoas: ");
	scanf("%d", &numeroDePessoas);
	
	pessoas = (tFicha*) calloc(numeroDePessoas, sizeof(tFicha));
	
	for(contador = 0; contador < numeroDePessoas; contador++)
	{
		printf("Pessoa %d\n", contador + 1);
		
		fflush(stdin);
		printf("Digite o nome da pessoa %d: ", contador + 1);
		fgets(pessoas[contador].nome, 99, stdin);
		
		printf("Digite a idade da pessoa %d: ", contador + 1);
		scanf("%d", &pessoas[contador].idade);
		
		fflush(stdin);
		printf("Digite o genero da pessoa %d: ", contador + 1);
		scanf("%c", &pessoas[contador].sexo);
		
		printf("Digite a massa da pessoa %d em quilogramas: ", contador + 1);
		scanf("%f", &pessoas[contador].peso);
		
		printf("Digite a altura da pessoa %d em metros: ", contador + 1);
		scanf("%f", &pessoas[contador].altura);
		
		printf("\n");
	}
	
	for(contador = 0; contador < numeroDePessoas; contador++)
	{
		printf("Pessoa %d\n", contador + 1);
		printf("Nome: %s", pessoas[contador].nome);
		printf("Idade: %d\n", pessoas[contador].idade);
		printf("Genero: %c\n", pessoas[contador].sexo);
		printf("Peso: %.2fKg\n", pessoas[contador].peso);
		printf("Altura: %.2fm\n", pessoas[contador].altura);
		
		IMC[contador] = pessoas[contador].peso / (pessoas[contador].altura * pessoas[contador].altura);
		printf("IMC: %.2f\n", IMC[contador]);
		
		printf("\n");
	}
	
	return 0;
}
