package questao3.ADB;

public class ADB {
	private No raiz = null;

	public No getRaiz() {
		return raiz;
	}

	public void setRaiz(No raiz) {
		this.raiz = raiz;
	}
	
	public Integer buscar(String chave) {
		//Armazena raiz em um n� de controle
		No no = raiz;
		
		//Se ele for nulo retorne nulo
		if(no == null)
			return null;
		
		//Percorre os n�s se aprofundando na raiz
		int indice = 0;
		while(no != null) {
			//Se o �ndice for igual ao tamanaho da chave, retorne o valor do n�
			if(indice == chave.length())
				return no.getValor();
			
			//Armazena o caractere atual e o usa como vetor do n�
			char caractere = chave.charAt(indice);
			no = no.filho[caractere];
			
			indice++;
		}
		
		//Se n�o encontrar no la�o ent�o encontra em lugar nenhum
		return null;
	}
	
	public void inserir(String chave, Integer valor) {
		//Salva a raiz no n� e no n� anterior
		No no = raiz;
		No noAnterior = raiz;
		
		//Percorre n�s, adicionando-os se forem vazios at� chegar no final da chave
		int indice = 0;
		while(indice != chave.length()) {
			//Se o n� for vazio, adiciona-o
			if(no == null)
				no = new No();
			
			//Salva o caractere atual
			char caractere = chave.charAt(indice);
			
			//Se o �ndice for diferente de 0(raiz), o n� atual agora � filho do anterior
			//em um determinado caractere. Sen�o, a raiz recebe o n� atual
			if(indice != 0)
				noAnterior.filho[caractere] = no;
			else
				raiz = no;
			
			//N� atual � salvo para ser usado na pr�xima itera��o
			noAnterior = no;
			
			//N� � atualizado com o pr�ximo n� no caractere atual, SE n�o for o �ltimo loop
			if(chave.length() != indice + 1)
				no = no.filho[caractere];
			
			indice++;
		}
		
		//No final da chave, coloca o valor no �ltimo n�
		if(indice == chave.length() && no != null)
			no.setValor(valor);
	}
	
	public void remover(String chave) {
		//Salva a raiz e um vetor de n�s com o tamanho da chave
		No no = raiz;
		No[] vetorDeNos = new No[chave.length()];
		
		if(no == null)
			return;
		
		//Percorre n�s, adicionando-os ao vetor de n�s
		int indice = 0;
		while(indice != chave.length()) {
			//Salva o caractere atual
			char caractere = chave.charAt(indice);
			
			if(no != null)
				vetorDeNos[indice] = no;
			else
				return;
			
			//N� � atualizado com o pr�ximo n� no caractere atual, SE n�o for o �ltimo loop
			if(chave.length() != indice + 1)
				no = no.filho[caractere];
			
			indice++;
		}
		
		//No final da chave, tira o valor no �ltimo n�
		if(indice == chave.length() && no != null)
			no.setValor(null);
		
		//Salva um n� anterior para poder colocar seu filho nulo se necess�rio
		No noAnterior;
		
		//Percorre o vetor de n�s ao contr�rio, come�ando da folha at� a raiz
		for(int i = vetorDeNos.length - 1; i >= 0; i--) {
			
			//Armazena o n� atual em uma vari�vel n�
			no = vetorDeNos[i];
			
			//Armazena o n� anterior em uma vari�vel n� anterior
			if(i - 1 >= 0)
				noAnterior = vetorDeNos[i - 1];
			else
				noAnterior = raiz;
			
			//Se esse n� for chave remova nada e saia da fun��o. Sen�o, percorra todo esse n�
			//Se todos os filhos do n� forem nulos, apaga-o. Sen�o, saia da fun��o
			if(no.getValor() != null)
				return;
			else {
				for(char caractere = 0; caractere < No.getNumeromaximo(); caractere++) {
					if(no.filho[caractere] != null)
						return;
				}
				noAnterior.setFilho(null);;
			}
		}
	}
	
	public void alteracao(String noAntigo, String noAtual, Integer valorAtual) {
		//Verifica at� onde a string � diferente
		int indice = 0;
		while(noAntigo.charAt(indice) == noAtual.charAt(indice)) {
			//Se a string antiga � igual � atual, sair da fun��o
			if(indice + 1 == noAntigo.length())
				return;
			
			indice++;
		}
		
		//Corta a string antiga at� onde ela se difere com a atual
		noAntigo = noAntigo.substring(indice, noAntigo.length());
		noAtual = noAtual.substring(indice, noAtual.length());
		
		//Remove a parte diferente que pertence � antiga
		//adiciona a parte diferente que pertence � atual junto com o valor atual
		remover(noAntigo);
		inserir(noAtual, valorAtual);
	}
	
	public void imprimir() {
		No no = raiz;
		char[][] paraImprimir = new char[No.getNumeromaximo()][No.getNumeromaximo()];
		
		int indice = 0;
		while(indice != No.getNumeromaximo()) {
			for(char caractere = 0; caractere < No.getNumeromaximo(); caractere++) {
				if(no.filho[caractere] != null)
					paraImprimir[indice][caractere] = caractere;
			}
			
			indice++;
		}
		
		for(char caractereGeral = 0; caractereGeral < No.getNumeromaximo(); caractereGeral++) {
			for(char caractere = 0; caractere < No.getNumeromaximo(); caractere++) {
				if(no.filho[caractere] != null)
					System.out.print(paraImprimir[caractereGeral][caractere] + " ");
				else
					System.out.print("-" + " ");
			}
			System.out.print("\n");
		}
	}
}
