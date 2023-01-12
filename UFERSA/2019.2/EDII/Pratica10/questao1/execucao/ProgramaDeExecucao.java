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
		tabelaHash.inserirContato("Vitoria", "+5545684", "Avenida Lóris");
		
		//Contato duplicado
		tabelaHash.inserirContato("vaso", "+55 11", "Avenida outro");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
		
		//Fazer busca de determinado contato
		contatos = tabelaHash.buscarContato("vitor");
		
		//Imprimir contatos achados se não for nulo
		if(contatos != null) {
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("\nNome: " + contatos[i].getNome());
				System.out.println("Número: " + contatos[i].getNumero());
				System.out.println("Endereço: " + contatos[i].getEndereco());
			}
		}
		
		//Este contato não existe
		contatos = tabelaHash.buscarContato("marcos");
		
		//Remove contato com nomes iguais e outros parâmetros diferentes
		tabelaHash.removerContato("vitor");
		
		//Inserir contato
		tabelaHash.inserirContato("zeé", "+564", "Avenida Rua");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
		
		//Não é possível inserir pois possui o primeiro caractere inválido
		tabelaHash.inserirContato("-zeé", "+564", "Avenida Rua");
		
		//Não é possível remover por não existir
		tabelaHash.removerContato("Antonio");
		
		//Remover contatos
		tabelaHash.removerContato("zeé");
		tabelaHash.removerContato("Vitoria");
		tabelaHash.removerContato("vitor");
		
		//Inserir contato
		tabelaHash.inserirContato("zeé", "+564", "Avenida Rua");
		
		//Imprimir contatos
		tabelaHash.imprimirContatos();
	}
}
