package questao1.lista;

public class Lista {
	private char elemento;
	
	public Lista(char elemento) {
		this.elemento = elemento;
	}
	
	public char getElemento() {
		return elemento;
	}
	
	public void setElemento(char elemento) {
		this.elemento = elemento;
	}
	
	public static int buscarPosicao(char elemento, Lista[] lista, int tamanho) {
		int posicao = 0;
		
		/*Percorre a lista em buscar do elemento. Quando achar, encerra o loop
		 * e retorna o �ndice*/
		for(int x = 0; x < tamanho; x++) {
			if(lista[x].getElemento() == elemento) {
				posicao = x;
				break;
			}
		}
		
		return posicao;
	}
	
	public static void moverParaFrente(char elemento, Lista[] lista, int tamanho) {
		//Procura a posi��o do elemento
		int posicaoAtual = buscarPosicao(elemento, lista, tamanho);
		Lista temp;
		
		/*Enquanto n�o chegar ao in�cio da lista, troque o elemento atual com o
		 * elemento da esquerda*/
		while(posicaoAtual != 0) {
			temp = lista[posicaoAtual - 1];
			lista[posicaoAtual - 1] = lista[posicaoAtual];
			lista[posicaoAtual] = temp;
			
			posicaoAtual--;
		}
	}
	
	public static void transposicao(char elemento, Lista[] lista, int tamanho) {
		//Procura a posi��o do elemento
		int posicaoAtual = buscarPosicao(elemento, lista, tamanho);
		Lista temp;
		
		/*Somente troque o elemento atual com o elemento da esquerda se este
		 * elemento n�o estiver no in�cio da lista*/
		if(posicaoAtual != 0) {
			temp = lista[posicaoAtual - 1];
			lista[posicaoAtual - 1] = lista[posicaoAtual];
			lista[posicaoAtual] = temp;
		}
	}
	
	public static void contadorDeFrequencia(char elemento, Lista[] lista, int tamanho, int frequencia[]) {
		//            Procura a posi��o do elemento
		int tempFreq, posicaoAtual = buscarPosicao(elemento, lista, tamanho);
		Lista temp;
		
		/*Enquanto n�o chegar ao in�cio da lista, troque o elemento atual com o
		 * elemento da esquerda SE a frequ�ncia do atual for maior que a frequ�ncia
		 * de quem est� na esquerda*/
		while(posicaoAtual != 0) {
			if(frequencia[posicaoAtual] > frequencia[posicaoAtual - 1]) {
				temp = lista[posicaoAtual - 1];
				tempFreq = frequencia[posicaoAtual - 1];
				
				lista[posicaoAtual - 1] = lista[posicaoAtual];
				frequencia[posicaoAtual - 1] = frequencia[posicaoAtual];
				
				lista[posicaoAtual] = temp;
				frequencia[posicaoAtual] = tempFreq;
			}
			posicaoAtual--;
		}
	}
	
	public static void resetaLista(Lista lista[]) {
		lista[0].setElemento('a');
		lista[1].setElemento('b');
		lista[2].setElemento('c');
		lista[3].setElemento('d');
		lista[4].setElemento('e');
		lista[5].setElemento('f');
		lista[6].setElemento('g');
	}
}
