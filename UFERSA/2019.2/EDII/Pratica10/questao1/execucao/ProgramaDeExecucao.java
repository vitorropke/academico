package questao1.execucao;

import questao1.tabelaHash.*;

public class ProgramaDeExecucao {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TabelaHash tabelaHash = new TabelaHash(26);
		No[] contatos;
		
		//Inserir contatos
		tabelaHash.inserirContato("vitor", "99", "avenida nenhuma");
		tabelaHash.inserirContato("Vitor", "+55 84", "Avenida Talco");
		tabelaHash.inserirContato("vitor", "+55 11", "Avenida outro");
		tabelaHash.inserirContato("vaso", "+55 11", "Avenida outro");
		tabelaHash.inserirContato("Vitoria", "+5545684", "Avenida L�ris");
		
		//Contato duplicado
		tabelaHash.inserirContato("vaso", "+55 11", "Avenida outro");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
		
		//Fazer busca de determinado contato
		contatos = tabelaHash.buscarContato("vitor");
		
		//Imprimir contatos achados se n�o for nulo
		if(contatos != null) {
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("\nNome: " + contatos[i].getNome());
				System.out.println("N�mero: " + contatos[i].getNumero());
				System.out.println("Endere�o: " + contatos[i].getEndereco());
			}
		}
		
		//Este contato n�o existe
		contatos = tabelaHash.buscarContato("marcos");
		
		//Remove contato com nomes iguais e outros par�metros diferentes
		tabelaHash.removerContato("vitor");
		
		//Inserir contato
		tabelaHash.inserirContato("ze�", "+564", "Avenida Rua");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
		
		//N�o � poss�vel inserir pois possui o primeiro caractere inv�lido
		tabelaHash.inserirContato("-ze�", "+564", "Avenida Rua");
		
		//N�o � poss�vel remover por n�o existir
		tabelaHash.removerContato("Antonio");
		
		//Remover contatos
		tabelaHash.removerContato("ze�");
		tabelaHash.removerContato("Vitoria");
		tabelaHash.removerContato("vitor");
		
		//Inserir contato
		tabelaHash.inserirContato("ze�", "+564", "Avenida Rua");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
	}
}
