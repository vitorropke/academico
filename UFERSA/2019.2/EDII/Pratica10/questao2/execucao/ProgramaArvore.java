package questao2.execucao;

import questao2.arvore.ArvoreDigital;

public class ProgramaArvore {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArvoreDigital trie = new ArvoreDigital();
		
		trie.inserir("she", 0);
		trie.inserir("Histórias", 1);
		trie.inserir("Hstórias", 2);
		trie.inserir("Htórias", 3);
		trie.inserir("Hórias", 4);
		trie.imprimir();
	}

}
