#pragma once

struct aviao //Registro
{
	char fabricante[20], modelo[10];
	unsigned int quantidadeProduzida, preco, passageiros, anoPrimeiroVoo, massa;
	unsigned int quantidadeMotores, velocidadeMaxima, velocidadeCruzeiro, alcance, tetoMaximo;
};

void imprimirTracos(int, char);
void imprimirAtributos(void);