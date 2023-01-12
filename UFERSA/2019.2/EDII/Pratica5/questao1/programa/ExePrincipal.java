package questao1.programa;

import questao1.lista.Lista;

public class ExePrincipal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Lista[] lista = {new Lista('a'), new Lista('b'), new Lista('c'), 
					new Lista('d'), new Lista('e'), new Lista('f'), new Lista('g')};
		int tamanhoLista = lista.length;
		
		System.out.print("Lista original:                                      ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		System.out.println();
		
		/*Mover para frente, passando os argumentos
			(elemento, lista, tamanho da lista)*/
		
		Lista.moverParaFrente('g', lista, tamanhoLista);
		Lista.moverParaFrente('f', lista, tamanhoLista);
		Lista.moverParaFrente('d', lista, tamanhoLista);
		Lista.moverParaFrente('f', lista, tamanhoLista);
		Lista.moverParaFrente('b', lista, tamanhoLista);
		Lista.moverParaFrente('f', lista, tamanhoLista);
		Lista.moverParaFrente('f', lista, tamanhoLista);
		Lista.moverParaFrente('d', lista, tamanhoLista);
		Lista.moverParaFrente('c', lista, tamanhoLista);
		
		System.out.print("Lista ap�s autoajuste usando mover para frente:      ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		System.out.println();
		
		/*Transposi��o, passando os argumentos (elemento, lista, tamanho da lista)*/
		Lista.resetaLista(lista);
		Lista.transposicao('g', lista, tamanhoLista);
		Lista.transposicao('f', lista, tamanhoLista);
		Lista.transposicao('d', lista, tamanhoLista);
		Lista.transposicao('f', lista, tamanhoLista);
		Lista.transposicao('b', lista, tamanhoLista);
		Lista.transposicao('f', lista, tamanhoLista);
		Lista.transposicao('f', lista, tamanhoLista);
		Lista.transposicao('d', lista, tamanhoLista);
		Lista.transposicao('c', lista, tamanhoLista);
		
		System.out.print("Lista ap�s autoajuste usando tranposi��o:            ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		System.out.println();
		
		/*Contador de frequ�ncia, passando os argumentos
		 * (elemento, lista, tamanho da lista)*/
		Lista.resetaLista(lista);
		
		//� necessario salvar a frequencia na fun��o main
		int frequencia[] = new int[tamanhoLista];
		
		frequencia[Lista.buscarPosicao('g', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('g', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('f', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('f', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('d', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('d', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('f', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('f', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('b', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('b', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('f', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('f', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('f', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('f', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('d', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('d', lista, tamanhoLista, frequencia);
		
		frequencia[Lista.buscarPosicao('c', lista, tamanhoLista)]++;
		Lista.contadorDeFrequencia('c', lista, tamanhoLista, frequencia);
		
		System.out.print("Lista ap�s autoajuste usando contador de frequ�ncia: ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		
		System.out.print("Frequ�ncia dos elementos:                            ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(frequencia[x]);
		}
	}

}
