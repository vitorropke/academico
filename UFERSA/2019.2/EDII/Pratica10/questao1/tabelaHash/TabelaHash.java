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
		//Salva a posi��o da tabela ascii a partir da letra 'A' mai�scula
		int posicaoAlfabeto = nome.charAt(0) - 65;
		
		//Se for min�scula, deve-se reposicionar para a posi��o da letra 'A' mai�scula
		if(posicaoAlfabeto >= 32 && posicaoAlfabeto <= 57)
			posicaoAlfabeto = posicaoAlfabeto - 32;
		
		return posicaoAlfabeto % this.tamanhoTabela;
	}
	
	public void inserirContato(String nome, String numero, String endereco) {
		//Verifica se a primeira letra � v�lida no alfabeto portugu�s A-Z
		if((nome.charAt(0) >= 0 && nome.charAt(0) <= 64) || 
				(nome.charAt(0) >= 91 && nome.charAt(0) <= 96) || (nome.charAt(0) >= 123)){
			System.out.println("\nFavor, digite um contato com nome v�lido dispon�vel no "
					+ "alfabeto portugu�s. De A-Z ou a-z sem acento na primeira letra.");
			return;
		}
				
		//Salva a posi��o da tabela, que seria uma letra
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
		//Salva a posi��o da tabela, que seria uma letra
		int posicaoNaTabela = this.funcaoHash(nome);
		No no = this.tabelaHash[posicaoNaTabela];
		
		//Verifica quantos nomes repetidos existem
		int indice = 0;
		while(no != null) {
			if(no.getNome() == nome)
				indice++;
			
			no = no.getProximoNo();
		}
		
		//Se n�o existir nome correspondente na tabela, saia da fun��o
		if(indice == 0) {
			System.out.println("\nExiste ningu�m aqui com esse nome.");
			return null;
		}
		
		//IMPRIMIR
		if(indice == 1)
			System.out.println("\n1 correspond�ncia encontrada.");
		else
			System.out.println("\n" + indice + " correspond�ncias encontradas.");
			
		
		//Cria um objeto de nomes repetidos
		No[] contatos = new No[indice];
		
		//Reinicia o �ndice e o n� para percorr�-los novamente
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
		
		//Se o nome n�o existir na tabela, saia da fun��o
		if(contatos == null) {
			System.out.println("\nN�o � poss�vel remov�-lo. Ele n�o existe.");
			return;
		}
		
		//Verifica se existe mais de um com o mesmo nome
		if(contatos.length > 1) {
			//Par�metros para ler contatos com o mesmo nome
			Scanner ler = new Scanner(System.in);
			No[] nosAnteriores = new No[contatos.length];
			int apagarContato, indice;
			
			//Percorre lista com contatos de mesmo nome, mas n�mero e endere�o diferentes
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("\nContato " + i);
				
				System.out.println("---Nome: " + contatos[i].getNome());
				System.out.println("---N�mero: " + contatos[i].getNumero());
				System.out.println("---Endere�o: " + contatos[i].getEndereco());
			}
			
			System.out.println("\nQual deseja apagar?");
			
			//Estipula um �ndice para ser par�metro de remo��o
			System.out.println("\nDigite qualquer n�mero diferente dos seguintes para cancelar:");
			for(int i = 0; i < contatos.length; i++) {
				System.out.println("Digite " + i + " para apagar Contato " + i);
			}
			
			//L� o �ndice do contato a ser apagado
			apagarContato = ler.nextInt();
			ler.close();
			
			//Se o n�mero for diferente dos �ndices anteriores, cancela a opera��o
			if(apagarContato < 0 || apagarContato >= contatos.length) {
				System.out.println("Saiu");
				return;
			}
			
			System.out.println("\nRemo��o do contato " + apagarContato);
			System.out.println("---Nome: " + contatos[apagarContato].getNome());
			System.out.println("---N�mero: " + contatos[apagarContato].getNumero());
			System.out.println("---Endere�o: " + contatos[apagarContato].getEndereco());
			
			//Acha os n�s anteriores de ambos os nomes
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
		
		//Acha o n� anterior do nome
		while(no != null) {
			if(no.getNome() == nome)
				break;
			
			noAnterior = no;
			no = no.getProximoNo();
		}
		
		//Se a tabela aponta para o n�
		if(noAnterior == this.tabelaHash[posicaoNaTabela] && no.getProximoNo() == null)
			this.tabelaHash[posicaoNaTabela] = null;
		else if(noAnterior == this.tabelaHash[posicaoNaTabela] && no.getProximoNo() != null)
			this.tabelaHash[posicaoNaTabela] = no.getProximoNo();
		
		//Faz liga��es necess�rias para evitar perda de refer�ncias. Se ela n�o existir, anula
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
					System.out.println("---N�mero:	" + no.getNumero());
					System.out.println("---Endere�o:	" + no.getEndereco());
					no = no.getProximoNo();
				}
			}
			else
				System.out.println("\nLetra " + ((char)(i + 65)) + ": Vazio");
		}
	}
}
