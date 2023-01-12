package ab.modelo;

public class No {
	protected int chave;
	protected No esq;
	protected No dir;
	
	
	//public No() {}
	
	public No (int valor, No e, No d) {
		
		this.chave = valor;
		this.esq = e;
		this.dir = d;
		
	}
	
	public static No criarNoVazio() {
		
		return null;
	}
}
