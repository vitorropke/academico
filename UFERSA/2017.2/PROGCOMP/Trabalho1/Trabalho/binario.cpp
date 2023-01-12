int ligarBit(int valor, int posicao) //Fun��o 'ligarBit' que retorna vari�vel inteira e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declara��o da vari�vel 'm�scara' como sendo inteiro e j� atribuindo um valor para esta vari�vel e realizando uma opera��o bit a bit de leftshift

	return valor | mascara; //Retornando o resultado da opera��o entre valor OU m�scara
}

int desligarBit(int valor, int posicao) //Fun��o 'desligarBit' que retorna vari�vel inteira e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declara��o da vari�vel 'm�scara' como sendo inteiro e j� atribuindo um valor para esta vari�vel e realizando uma opera��o bit a bit de leftshift

	return valor & ~mascara; //Retornando o resultado da opera��o entre valor E NEGA��O de m�scara
}

bool testarBit(int valor, int posicao) //Fun��o 'testarBit' que retorna vari�vel booleana e recebe dois valores inteiros
{
	int mascara = 1 << posicao; //Declara��o da vari�vel 'm�scara' como sendo inteiro e j� atribuindo um valor para esta vari�vel e realizando uma opera��o bit a bit de leftshift

	if (valor & mascara) //Condicional entre a opera��o valor E m�scara
		return true; //Retorna true quando valor E m�scara for verdade(Quando o bit for igual a 1)
	else //Se n�o for verdade
		return false; //Retorna false quando valor E m�scara for mentira(Quando o bit for igual a 0)
}

int andBinario(int valor1, int valor2) //Fun��o 'andBinario' que retorna vari�vel inteira e recebe dois valores inteiros
{
	return valor1 & valor2; //Retornando o resultado da opera��o entre valor1 E valor2
}

int orBinario(int valor1, int valor2) //Fun��o 'orBinario' que retorna vari�vel inteira e recebe dois valores inteiros
{
	return valor1 | valor2; //Retornando o resultado da opera��o entre valor1 OU valor2
}

int bitsBaixos(int valor) //Fun��o 'bitsBaixos' que retorna vari�vel inteira e recebe um valor inteiro
{
	int mascara = 255; //Declara��o da vari�vel 'm�scara' como sendo inteiro e j� atribuindo um valor para esta vari�vel

	return valor & mascara; //Retornando o resultado da opera��o entre valor E m�scara
}

int bitsAltos(int valor) //Fun��o 'bitsAltos' que retorna vari�vel inteira e recebe um valor inteiro
{
	int mascara = 255; //Declara��o da vari�vel 'm�scara' como sendo inteiro e j� atribuindo um valor para esta vari�vel

	return valor & ~mascara; //Retornando o resultado da opera��o entre valor E NEGA��O de m�scara
}