package questao1.tabelaHash;

import java.util.Scanner;

public class TabelaHash {
	private int tamanhoTabela;
	private No[] tabelaHash;
	
	public TabelaHash(int tamanhoTabela) {
		this.tamanhoTabela = tamanhoTabela;
		this.tabelaHash = new No[this.tamanhoTabela];
	}

	public int getTamanhoTabela() {
		return tamanhoTabela;
	}

	public void setTamanhoTabela(int tamanhoTabela) {
		this.tamanhoTabela = tamanhoTabela;
	}

	public No[] getTabelaHash() {
		return tabelaHash;
	}

	public void setTabelaHash(No[] tabelaHash) {
		this.tabelaHash = tabelaHash;
	}
	
	public int funcaoHash(String nome) {
		//Salva a posição da tabela ascii a partir da letra 'A' maiúscula
		int posicaoAlfabeto = nome.charAt(0) - 65;
		
		//Se for minúscula, deve-se reposicionar para a posição da letra 'A' maiúscula
		if(posicaoAlfabeto >= 32 && posicaoAlfabeto <= 57)
			posicaoAlfabeto = posicaoAlfabeto - 32;
		
		return posicaoAlfabeto % this.tamanhoTabela;
	}
	
	public void inserirContato(String nome, String numero, String endereco) {
		//Verifica se a primeira letra é válida no alfabeto português A-Z
		if((nome.charAt(0) >= 0 && nome.charAt(0) <= 64) || 
				(nome.charAt(0) >= 91 && nome.charAt(0) <= 96) || (nome.charAt(0) >= 123)){
			System.out.println("\nFavor, digite um contato com nome válido disponível no "
					+ "alfabeto português. De A-Z ou a-z sem acento na primeira letra.");
			return;
		}
				
		//Salva a posição da tabela, que seria uma letra
		int posicaoNaTabela = this.funcaoHash(nome);
		No no = this.tabelaHash[posicaoNaTabela];
		
		//Verifica se existe um contato com os mesmo dados
		while(no != null) {
			if(nome == no.getNome() && numero == no.getNumero() && endereco == no.getEndereco()) {
				System.out.println("Contato duplicado. Nada mudou.");
				return;
			}
			
			no = no.getProximoNo();
		}
		
		//Salva o contato com seus dados
		if(no == null) {
			no = new No();
			
			no.setNome(nome);
			no.setNumero(numero);
			no.setEndereco(endereco);
			no.setProximoNo(this.tabelaHash[posicaoNaTabela]);
			this.tabelaHash[posicaoNaTabela] = no;
		}
	}
	
	public No[] buscarContato(String nome) {
		//Salva a posição da tabela, que seria uma letra
		int posicaoNaTabela = this.funcaoHash(nome);
		No no = this.tabelaHash[posicaoNaTabela];
		
		//Verifica quantos nomes repetidos existem
		int indice = 0;
		while(no != null) {
			if(no.getNome() == nome)
				indice++;
			
			no = no.getProximoNo();
		}
		
		//Se não existir nome correspondente na tabela, saia da função
		if(indice == 0) {
			System.out.println("\nExiste ninguém aqui com esse nome.");
			return null;
		}
		
		//IMPRIMIR
		if(indice == 1)
			System.out.println("\n1 correspondência encontrada.");
		else
			System.out.println("\n" + indice + " correspondências encontradas.");
			
		
		//Cria um objeto de nomes repetidos
		No[] contatos = new No[indice];
		
		//Reinicia o índice e o nó para percorrê-los novamente
		indice = 0;
		no = this.tabelaHash[posicaoNaTabela];
		
		//Armazena os nomes repetidos no objeto criado
		while(no != null) {
			if(no.getNome() == nome) {
				contatos[indice] = no;
				indice++;
			}
			no = no.getProximoNo();
		}
		
		return contatos;
	}
	
	public void removerContato(String nome) {
		int posicaoNaTabela = this.funcaoHash(nome);
		No no = this.tabelaHash[posicaoNaTabela];
		No noAnterior = this.tabelaHash[posicaoNaTabela];
		No[] contatos = buscarContato(nome);
		
		//Se o nome não existir na tabela, saia da função
		if(contatos == null) {
			System.out.println("\nNão é possível removê-lo. Ele não existe.");
			return;
		}
		
		//Verifica se existe mais de um com o mesmo nome
		if(contatos.length > 1) {
			//Parâmetros para ler contatos com o mesmo nome
			Scanner ler = new Scanner(System.in);
			No[] nosAnteriores = new No[contatos.length];
			int apagarContato, indice;
			
			//Percorre lista com contatos de mesmo nome, mas número e endereço diferentes
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("\nContato " + i);
				
				System.out.println("---Nome: " + contatos[i].getNome());
				System.out.println("---Número: " + contatos[i].getNumero());
				System.out.println("---Endereço: " + contatos[i].getEndereco());
			}
			
			System.out.println("\nQual deseja apagar?");
			
			//Estipula um índice para ser parâmetro de remoção
			System.out.println("\nDigite qualquer número diferente dos seguintes para cancelar:");
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("Digite " + i + " para apagar Contato " + i);
			}
			
			//Lê o índice do contato a ser apagado
			apagarContato = ler.nextInt();
			ler.close();
			
			//Se o número for diferente dos índices anteriores, cancela a operação
			if(apagarContato < 0 || apagarContato >= contatos.length) {
				System.out.println("Saiu");
				return;
			}
			
			System.out.println("\nRemoção do contato " + apagarContato);
			System.out.println("---Nome: " + contatos[apagarContato].getNome());
			System.out.println("---Número: " + contatos[apagarContato].getNumero());
			System.out.println("---Endereço: " + contatos[apagarContato].getEndereco());
			
			//Acha os nós anteriores de ambos os nomes
			indice = 0;
			while(no != null && indice < contatos.length) {
				if(no.getNome() == nome) {
					indice++;
				}
				
				if(indice < contatos.length)
					nosAnteriores[indice] = no;
				
				no = no.getProximoNo();
			}
			
			noAnterior = nosAnteriores[apagarContato];
			no = contatos[apagarContato];
		}
		
		//Acha o nó anterior do nome
		while(no != null) {
			if(no.getNome() == nome)
				break;
			
			noAnterior = no;
			no = no.getProximoNo();
		}
		
		//Se a tabela aponta para o nó
		if(noAnterior == this.tabelaHash[posicaoNaTabela] && no.getProximoNo() == null)
			this.tabelaHash[posicaoNaTabela] = null;
		else if(noAnterior == this.tabelaHash[posicaoNaTabela] && no.getProximoNo() != null)
			this.tabelaHash[posicaoNaTabela] = no.getProximoNo();
		
		//Faz ligações necessárias para evitar perda de referências. Se ela não existir, anula
		if(no != null && no.getProximoNo() != null)
			noAnterior.setProximoNo(no.getProximoNo());
		else if(no != null && no.getProximoNo() == null)
			noAnterior.setProximoNo(null);
		
		//Anula o contato
		if(no != null) {
			no.setEndereco(null);
			no.setNumero(null);
			no.setNome(null);
			no = null;
		}
	}
	
	public void imprimirContatos() {
		for(int i = 0; i < getTamanhoTabela(); i++) {
			if(tabelaHash[i] != null) {
				No no = this.tabelaHash[i];
				
				//Imprime cada letra em uma linha separada
				System.out.println("\nLetra " + ((char)(i + 65)) + ": ");
				
				//Imprime cada contato de uma letra em linha[s] separada[s]
				while(no != null) {
					System.out.println("\n---Nome:	" + no.getNome());
					System.out.println("---Número:	" + no.getNumero());
					System.out.println("---Endereço:	" + no.getEndereco());
					no = no.getProximoNo();
				}
			}
			else
				System.out.println("\nLetra " + ((char)(i + 65)) + ": Vazio");
		}
	}
}
