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
		
		System.out.print("Lista após autoajuste usando mover para frente:      ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		System.out.println();
		
		/*Transposição, passando os argumentos (elemento, lista, tamanho da lista)*/
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
		
		System.out.print("Lista após autoajuste usando tranposição:            ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		System.out.println();
		
		/*Contador de frequência, passando os argumentos
		 * (elemento, lista, tamanho da lista)*/
		Lista.resetaLista(lista);
		
		//É necessario salvar a frequencia na função main
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
		
		System.out.print("Lista após autoajuste usando contador de frequência: ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(lista[x].getElemento());
		}
		System.out.println();
		
		System.out.print("Frequência dos elementos:                            ");
		for(int x = 0; x < tamanhoLista; x++) {
			System.out.print(frequencia[x]);
		}
	}

}
