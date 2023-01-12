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
		No subEsq = noRaiz.esq;				//Salva a subárvore esquerda do nó enraizado
		No subDireitaDaSubEsq = subEsq.dir;	//Salva a subárvore direita da subárvore esquerda do nó enraizado
		No paiDaExRaiz = noRaiz.pai;		//Salva o pai da raiz
		
		subEsq.dir = noRaiz;				//A ex-raiz virou subárvore direita. subEsq é a nova raiz
		noRaiz.esq = subDireitaDaSubEsq;	//A subárvore esquerda da ex-raiz, recebe nó que pertencia à ex-subEsq da ex-raiz
		
		if(subDireitaDaSubEsq != null)
			subDireitaDaSubEsq.pai = noRaiz;	//O pai que era da atual raiz agora é da atual subDir da raiz
		
		noRaiz.pai = subEsq;				//O pai da ex-raiz agora é subEsq, que é a nova raiz
		subEsq.pai = paiDaExRaiz;			//O pai da nova raiz é pai da antiga raiz
		
		
		if(subEsq.pai != null) {
			if(subEsq.pai.chave > subEsq.chave)
				subEsq.pai.esq = subEsq;			//Se o pai da nova raiz for maior que esta, então ficará à esquerda do pai
			else if(subEsq.pai.chave < subEsq.chave)
				subEsq.pai.dir = subEsq;			//Se o pai da nova raiz for menor que esta, então ficará à direita do pai
			else
				throw new IllegalArgumentException("Existem chaves iguais");	//Se existirem chaves iguais
		}
	}
	
	public void rotacaoEsquerdaSimples(No noRaiz) {
		No subDir = noRaiz.dir;					//Salva a subárvore direita do nó enraizado
		No subEsquerdaDaSubDir = subDir.esq;	//Salva a subárvore esquerda da subárvore direita do nó enraizado
		No paiDaExRaiz = noRaiz.pai;				//Salva o pai da raiz
		
		subDir.esq = noRaiz;					//A ex-raiz virou subárvore esquerda. subDir é a nova raiz
		noRaiz.dir = subEsquerdaDaSubDir;		//A subárvore direita da ex-raiz, recebe nó que pertencia à ex-subDir da ex-raiz
		
		if(subEsquerdaDaSubDir != null)
			subEsquerdaDaSubDir.pai = noRaiz;		//O pai que era da atual raiz agora é da atual subEsq da raiz
		noRaiz.pai = subDir;					//O pai da ex-raiz agora é subDir, que é a nova raiz
		subDir.pai = paiDaExRaiz;				//O pai da nova raiz é pai da antiga raiz
		
		if(subDir.pai != null) {
			if(subDir.pai.chave > subDir.chave)
				subDir.pai.esq = subDir;			//Se o pai da nova raiz for maior que esta, então ficará à esquerda do pai
			else if(subDir.pai.chave < subDir.chave)
				subDir.pai.dir = subDir;			//Se o pai da nova raiz for menor que esta, então ficará à direita do pai
			else
				throw new IllegalArgumentException("Existem chaves iguais");	//Se existirem chaves iguais
		}
	}
	
	public void rotacaoDuplaDireita(No noRaiz) {
		rotacaoEsquerdaSimples(noRaiz.esq);	//Rotação esquerda simples na subárvore esquerda da raiz
		rotacaoDireitaSimples(noRaiz);		//Rotação direita simples na nova raiz
	}
	
	public void rotacaoDuplaEsquerda(No noRaiz) {
		rotacaoDireitaSimples(noRaiz.dir);	//Rotação direita simples na subárvore direita da raiz
		rotacaoEsquerdaSimples(noRaiz);		//Rotação esquerda simples na nova raiz
	}
	
	public void difusaoCompleta(No raiz, No no) {
		while(no.chave != raiz.chave && no.pai == null)
			difusao(raiz, no);
	}
	
	public void difusao(No raiz, No no) {
		//SE O NÓ, PAI E AVÔ FOREM DIFERENTES DA RAIZ
		if(no != null && no.pai != null && no.pai.pai != null) {
			//CASO 3 PRIMEIRO QUE O 2 POIS EXISTE UMA CONDIÇÃO ONDE O CASO 2 SOBREPUJARIA O CASO 3
			//CASO 3.1
			if(no.chave == no.pai.esq.chave && no.pai.chave == no.pai.pai.esq.chave) {
				/*Se o nó estiver à esquerda do pai, e este estiver à esquerda do seu pai(avô do nó), 
				 * efetue uma rotação direita simples no pai do pai e uma rotação direita simples no pai */
				rotacaoDireitaSimples(no.pai.pai);
				rotacaoDireitaSimples(no.pai);
			
			//CASO 3.2
			}else if(no.chave == no.pai.dir.chave && no.pai.chave == no.pai.pai.dir.chave) {
				/*Se o nó estiver à direita do pai, e este estiver à direita do seu pai(avô do nó), 
				 * efetue uma rotação esquerda simples no pai do pai e uma rotação esquerda simples no pai */
				rotacaoEsquerdaSimples(no.pai.pai);
				rotacaoEsquerdaSimples(no.pai);
			
			//CASO 3.3
			}else if(no.chave == no.pai.dir.chave && no.pai.chave == no.pai.pai.esq.chave) {
				/*Se o nó estiver à direita do pai, e este estiver à esquerda do seu pai(avô do nó), 
				 * efetue uma rotação dupla direita no pai do pai*/
				rotacaoDuplaDireita(no.pai.pai);
			
			//CASO 3.4
			}else if(no.chave == no.pai.esq.chave && no.pai.chave == no.pai.pai.dir.chave) {
				/*Se o nó estiver à esquerda do pai, e este estiver à direita do seu pai(avô do nó), 
				 * efetue uma rotação dupla esquerda no pai do pai*/
				rotacaoDuplaEsquerda(no.pai.pai);
			}
			
			//CASO 2.1
			else if(no.chave == no.pai.esq.chave)
				rotacaoDireitaSimples(no.pai);	//Se o nó estiver à esquerda do pai, efetue rotação direita simples no pai
			
			//CASO 2.2
			else if(no.chave == no.pai.dir.chave)
				rotacaoEsquerdaSimples(no.pai);	//Se o nó estiver à direita do pai, efetue rotação esquerda simples no pai
		
		//SE O PAI DO NÓ FOR NULO
		}
		else if(no.pai == null) {
			raiz = no;	//O nó agora é raiz da árvore
		
		
		//SE O AVÔ DO NÓ FOR NULO
		}else if(no.pai.pai == null) {
			//CASO 2.1
			if(no.chave == no.pai.esq.chave) {
				rotacaoDireitaSimples(no.pai);	//Se o nó estiver à esquerda do pai, efetue rotação direita simples no pai
			}
			//CASO 2.2
			else if(no.chave == no.pai.dir.chave)
				rotacaoEsquerdaSimples(no.pai);	//Se o nó estiver à direita do pai, efetue rotação esquerda simples no pai
			raiz = no; //O nó agora é raiz da árvore
		}
	}
}
