int ligarBit(int valor, int posicao) //Função 'ligarBit' que retorna variável inteira e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declaração da variável 'máscara' como sendo inteiro e já atribuindo um valor para esta variável e realizando uma operação bit a bit de leftshift

	return valor | mascara; //Retornando o resultado da operação entre valor OU máscara
}

int desligarBit(int valor, int posicao) //Função 'desligarBit' que retorna variável inteira e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declaração da variável 'máscara' como sendo inteiro e já atribuindo um valor para esta variável e realizando uma operação bit a bit de leftshift

	return valor & ~mascara; //Retornando o resultado da operação entre valor E NEGAÇÃO de máscara
}

bool testarBit(int valor, int posicao) //Função 'testarBit' que retorna variável booleana e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declaração da variável 'máscara' como sendo inteiro e já atribuindo um valor para esta variável e realizando uma operação bit a bit de leftshift

	if (valor & mascara) //Condicional entre a operação valor E máscara
		return true; //Retorna true quando valor E máscara for verdade(Quando o bit for igual a 1)
	else //Se não for verdade
		return false; //Retorna false quando valor E máscara for mentira(Quando o bit for igual a 0)
}

int andBinario(int valor1, int valor2) //Função 'andBinario' que retorna variável inteira e recebe dois valores inteiros
{
	return valor1 & valor2; //Retornando o resultado da operação entre valor1 E valor2
}

int orBinario(int valor1, int valor2) //Função 'orBinario' que retorna variável inteira e recebe dois valores inteiros
{
	return valor1 | valor2; //Retornando o resultado da operação entre valor1 OU valor2
}

int bitsBaixos(int valor) //Função 'bitsBaixos' que retorna variável inteira e recebe um valor inteiro
{
	int mascara = 255; //Declaração da variável 'máscara' como sendo inteiro e já atribuindo um valor para esta variável

	return valor & mascara; //Retornando o resultado da operação entre valor E máscara
}

int bitsAltos(int valor) //Função 'bitsAltos' que retorna variável inteira e recebe um valor inteiro
{
	int mascara = 255; //Declaração da variável 'máscara' como sendo inteiro e já atribuindo um valor para esta variável

	return valor & ~mascara; //Retornando o resultado da operação entre valor E NEGAÇÃO de máscara
}