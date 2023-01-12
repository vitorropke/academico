package ab.modelo;

public class ArvoreBinaria {
	protected No raiz;
	
	/* Operações */	
	
	public static No criarNo(int valor, No e, No d) {
		
		No n = new No(valor, e, d);
		
		return n;
	}
	
	public void preOrdem(No arv) {
		
		if(arv != null) {
			
			System.out.println(arv.chave);
			this.preOrdem(arv.esq);
			this.preOrdem(arv.dir);
			
		}
		
	}

	public void ordem(No arv) {
		
		if(arv != null) {
			
			this.ordem(arv.esq);
			System.out.println(arv.chave);
			this.ordem(arv.dir);
			
		}
		
	}
	
	public void posOrdem(No arv) {
		
		if(arv != null) {
			
			this.posOrdem(arv.esq);
			this.posOrdem(arv.dir);
			System.out.println(arv.chave);
			
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		criarNo(5, 3, 8);
		criarNo(3, 1, 4);
		criarNo(8, null, 9);
		criarNo(1, null, null);
		criarNo(4, null, null);
		criarNo(9, null, null);
	}

}
