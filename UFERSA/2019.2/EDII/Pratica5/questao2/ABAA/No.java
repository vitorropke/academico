package questao2.ABAA;

public class No {
	private No esq, dir, pai;
	private char chave;
	
	public No(No esq, No dir, char chave) {
		super();
		this.esq = esq;
		this.dir = dir;
		this.chave = chave;
	}
	
	public No getEsq() {
		return esq;
	}
	public void setEsq(No esq) {
		this.esq = esq;
	}
	public No getDir() {
		return dir;
	}
	public void setDir(No dir) {
		this.dir = dir;
	}
	public No getPai() {
		return pai;
	}

	public void setPai(No pai) {
		this.pai = pai;
	}

	public char getChave() {
		return chave;
	}
	public void setChave(char chave) {
		this.chave = chave;
	}
	
	public void preOrdem(No no) {
		if(no != null) {
			System.out.print(no.chave + " ");
			preOrdem(no.esq);
			preOrdem(no.dir);
		}
	}
	
	public void Ordem(No no) {
		if(no != null) {
			Ordem(no.esq);
			System.out.print(no.chave + " ");
			Ordem(no.dir);
		}
	}
	
	public void posOrdem(No no) {
		if(no != null) {
			posOrdem(no.esq);
			posOrdem(no.dir);
			System.out.print(no.chave + " ");
		}
	}
	
	public void rotacaoDireitaSimples(No noRaiz) {
		No subEsq = noRaiz.esq;				//Salva a sub�rvore esquerda do n� enraizado
		No subDireitaDaSubEsq = subEsq.dir;	//Salva a sub�rvore direita da sub�rvore esquerda do n� enraizado
		No paiDaExRaiz = noRaiz.pai;		//Salva o pai da raiz
		
		subEsq.dir = noRaiz;				//A ex-raiz virou sub�rvore direita. subEsq � a nova raiz
		noRaiz.esq = subDireitaDaSubEsq;	//A sub�rvore esquerda da ex-raiz, recebe n� que pertencia � ex-subEsq da ex-raiz
		
		if(subDireitaDaSubEsq != null)
			subDireitaDaSubEsq.pai = noRaiz;	//O pai que era da atual raiz agora � da atual subDir da raiz
		
		noRaiz.pai = subEsq;				//O pai da ex-raiz agora � subEsq, que � a nova raiz
		subEsq.pai = paiDaExRaiz;			//O pai da nova raiz � pai da antiga raiz
		
		
		if(subEsq.pai != null) {
			if(subEsq.pai.chave > subEsq.chave)
				subEsq.pai.esq = subEsq;			//Se o pai da nova raiz for maior que esta, ent�o ficar� � esquerda do pai
			else if(subEsq.pai.chave < subEsq.chave)
				subEsq.pai.dir = subEsq;			//Se o pai da nova raiz for menor que esta, ent�o ficar� � direita do pai
			else
				throw new IllegalArgumentException("Existem chaves iguais");	//Se existirem chaves iguais
		}
	}
	
	public void rotacaoEsquerdaSimples(No noRaiz) {
		No subDir = noRaiz.dir;					//Salva a sub�rvore direita do n� enraizado
		No subEsquerdaDaSubDir = subDir.esq;	//Salva a sub�rvore esquerda da sub�rvore direita do n� enraizado
		No paiDaExRaiz = noRaiz.pai;				//Salva o pai da raiz
		
		subDir.esq = noRaiz;					//A ex-raiz virou sub�rvore esquerda. subDir � a nova raiz
		noRaiz.dir = subEsquerdaDaSubDir;		//A sub�rvore direita da ex-raiz, recebe n� que pertencia � ex-subDir da ex-raiz
		
		if(subEsquerdaDaSubDir != null)
			subEsquerdaDaSubDir.pai = noRaiz;		//O pai que era da atual raiz agora � da atual subEsq da raiz
		noRaiz.pai = subDir;					//O pai da ex-raiz agora � subDir, que � a nova raiz
		subDir.pai = paiDaExRaiz;				//O pai da nova raiz � pai da antiga raiz
		
		if(subDir.pai != null) {
			if(subDir.pai.chave > subDir.chave)
				subDir.pai.esq = subDir;			//Se o pai da nova raiz for maior que esta, ent�o ficar� � esquerda do pai
			else if(subDir.pai.chave < subDir.chave)
				subDir.pai.dir = subDir;			//Se o pai da nova raiz for menor que esta, ent�o ficar� � direita do pai
			else
				throw new IllegalArgumentException("Existem chaves iguais");	//Se existirem chaves iguais
		}
	}
	
	public void rotacaoDuplaDireita(No noRaiz) {
		rotacaoEsquerdaSimples(noRaiz.esq);	//Rota��o esquerda simples na sub�rvore esquerda da raiz
		rotacaoDireitaSimples(noRaiz);		//Rota��o direita simples na nova raiz
	}
	
	public void rotacaoDuplaEsquerda(No noRaiz) {
		rotacaoDireitaSimples(noRaiz.dir);	//Rota��o direita simples na sub�rvore direita da raiz
		rotacaoEsquerdaSimples(noRaiz);		//Rota��o esquerda simples na nova raiz
	}
	
	public void difusaoCompleta(No raiz, No no) {
		while(no.chave != raiz.chave && no.pai == null)
			difusao(raiz, no);
	}
	
	public void difusao(No raiz, No no) {
		//SE O N�, PAI E AV� FOREM DIFERENTES DA RAIZ
		if(no != null && no.pai != null && no.pai.pai != null) {
			//CASO 3 PRIMEIRO QUE O 2 POIS EXISTE UMA CONDI��O ONDE O CASO 2 SOBREPUJARIA O CASO 3
			//CASO 3.1
			if(no.chave == no.pai.esq.chave && no.pai.chave == no.pai.pai.esq.chave) {
				/*Se o n� estiver � esquerda do pai, e este estiver � esquerda do seu pai(av� do n�), 
				 * efetue uma rota��o direita simples no pai do pai e uma rota��o direita simples no pai */
				rotacaoDireitaSimples(no.pai.pai);
				rotacaoDireitaSimples(no.pai);
			
			//CASO 3.2
			}else if(no.chave == no.pai.dir.chave && no.pai.chave == no.pai.pai.dir.chave) {
				/*Se o n� estiver � direita do pai, e este estiver � direita do seu pai(av� do n�), 
				 * efetue uma rota��o esquerda simples no pai do pai e uma rota��o esquerda simples no pai */
				rotacaoEsquerdaSimples(no.pai.pai);
				rotacaoEsquerdaSimples(no.pai);
			
			//CASO 3.3
			}else if(no.chave == no.pai.dir.chave && no.pai.chave == no.pai.pai.esq.chave) {
				/*Se o n� estiver � direita do pai, e este estiver � esquerda do seu pai(av� do n�), 
				 * efetue uma rota��o dupla direita no pai do pai*/
				rotacaoDuplaDireita(no.pai.pai);
			
			//CASO 3.4
			}else if(no.chave == no.pai.esq.chave && no.pai.chave == no.pai.pai.dir.chave) {
				/*Se o n� estiver � esquerda do pai, e este estiver � direita do seu pai(av� do n�), 
				 * efetue uma rota��o dupla esquerda no pai do pai*/
				rotacaoDuplaEsquerda(no.pai.pai);
			}
			
			//CASO 2.1
			else if(no.chave == no.pai.esq.chave)
				rotacaoDireitaSimples(no.pai);	//Se o n� estiver � esquerda do pai, efetue rota��o direita simples no pai
			
			//CASO 2.2
			else if(no.chave == no.pai.dir.chave)
				rotacaoEsquerdaSimples(no.pai);	//Se o n� estiver � direita do pai, efetue rota��o esquerda simples no pai
		
		//SE O PAI DO N� FOR NULO
		}
		else if(no.pai == null) {
			raiz = no;	//O n� agora � raiz da �rvore
		
		
		//SE O AV� DO N� FOR NULO
		}else if(no.pai.pai == null) {
			//CASO 2.1
			if(no.chave == no.pai.esq.chave) {
				rotacaoDireitaSimples(no.pai);	//Se o n� estiver � esquerda do pai, efetue rota��o direita simples no pai
			}
			//CASO 2.2
			else if(no.chave == no.pai.dir.chave)
				rotacaoEsquerdaSimples(no.pai);	//Se o n� estiver � direita do pai, efetue rota��o esquerda simples no pai
			raiz = no; //O n� agora � raiz da �rvore
		}
	}
}
