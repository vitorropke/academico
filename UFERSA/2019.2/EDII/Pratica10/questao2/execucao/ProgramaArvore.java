package questao2.execucao;

import questao2.arvore.ArvoreDigital;

public class ProgramaArvore {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArvoreDigital trie = new ArvoreDigital();
		
		trie.inserir("she", 0);
		trie.inserir("Hist�rias", 1);
		trie.inserir("Hst�rias", 2);
		trie.inserir("Ht�rias", 3);
		trie.inserir("H�rias", 4);
		trie.imprimir();
	}

}
