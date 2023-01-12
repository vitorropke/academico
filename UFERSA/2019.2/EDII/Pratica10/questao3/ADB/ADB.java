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
		//Armazena raiz em um nó de controle
		No no = raiz;
		
		//Se ele for nulo retorne nulo
		if(no == null)
			return null;
		
		//Percorre os nós se aprofundando na raiz
		int indice = 0;
		while(no != null) {
			//Se o índice for igual ao tamanaho da chave, retorne o valor do nó
			if(indice == chave.length())
				return no.getValor();
			
			//Armazena o caractere atual e o usa como vetor do nó
			char caractere = chave.charAt(indice);
			no = no.filho[caractere];
			
			indice++;
		}
		
		//Se não encontrar no laço então encontra em lugar nenhum
		return null;
	}
	
	public void inserir(String chave, Integer valor) {
		//Salva a raiz no nó e no nó anterior
		No no = raiz;
		No noAnterior = raiz;
		
		//Percorre nós, adicionando-os se forem vazios até chegar no final da chave
		int indice = 0;
		while(indice != chave.length()) {
			//Se o nó for vazio, adiciona-o
			if(no == null)
				no = new No();
			
			//Salva o caractere atual
			char caractere = chave.charAt(indice);
			
			//Se o índice for diferente de 0(raiz), o nó atual agora é filho do anterior
			//em um determinado caractere. Senão, a raiz recebe o nó atual
			if(indice != 0)
				noAnterior.filho[caractere] = no;
			else
				raiz = no;
			
			//Nó atual é salvo para ser usado na próxima iteração
			noAnterior = no;
			
			//Nó é atualizado com o próximo nó no caractere atual, SE não for o último loop
			if(chave.length() != indice + 1)
				no = no.filho[caractere];
			
			indice++;
		}
		
		//No final da chave, coloca o valor no último nó
		if(indice == chave.length() && no != null)
			no.setValor(valor);
	}
	
	public void remover(String chave) {
		//Salva a raiz e um vetor de nós com o tamanho da chave
		No no = raiz;
		No[] vetorDeNos = new No[chave.length()];
		
		if(no == null)
			return;
		
		//Percorre nós, adicionando-os ao vetor de nós
		int indice = 0;
		while(indice != chave.length()) {
			//Salva o caractere atual
			char caractere = chave.charAt(indice);
			
			if(no != null)
				vetorDeNos[indice] = no;
			else
				return;
			
			//Nó é atualizado com o próximo nó no caractere atual, SE não for o último loop
			if(chave.length() != indice + 1)
				no = no.filho[caractere];
			
			indice++;
		}
		
		//No final da chave, tira o valor no último nó
		if(indice == chave.length() && no != null)
			no.setValor(null);
		
		//Salva um nó anterior para poder colocar seu filho nulo se necessário
		No noAnterior;
		
		//Percorre o vetor de nós ao contrário, começando da folha até a raiz
		for(int i = vetorDeNos.length - 1; i >= 0; i--) {
			
			//Armazena o nó atual em uma variável nó
			no = vetorDeNos[i];
			
			//Armazena o nó anterior em uma variável nó anterior
			if(i - 1 >= 0)
				noAnterior = vetorDeNos[i - 1];
			else
				noAnterior = raiz;
			
			//Se esse nó for chave remova nada e saia da função. Senão, percorra todo esse nó
			//Se todos os filhos do nó forem nulos, apaga-o. Senão, saia da função
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
		//Verifica até onde a string é diferente
		int indice = 0;
		while(noAntigo.charAt(indice) == noAtual.charAt(indice)) {
			//Se a string antiga é igual à atual, sair da função
			if(indice + 1 == noAntigo.length())
				return;
			
			indice++;
		}
		
		//Corta a string antiga até onde ela se difere com a atual
		noAntigo = noAntigo.substring(indice, noAntigo.length());
		noAtual = noAtual.substring(indice, noAtual.length());
		
		//Remove a parte diferente que pertence à antiga
		//adiciona a parte diferente que pertence à atual junto com o valor atual
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
