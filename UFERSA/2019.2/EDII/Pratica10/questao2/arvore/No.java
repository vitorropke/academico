package questao2.arvore;

public class No {
	private static final int numeroMaximo = 256;
	private Integer valor;
	protected No[] filho = new No[numeroMaximo];
	
	public Integer getValor() {
		return valor;
	}
	public void setValor(Integer valor) {
		this.valor = valor;
	}
	public No[] getFilho() {
		return filho;
	}
	public void setFilho(No[] filho) {
		this.filho = filho;
	}
	public static int getNumeromaximo() {
		return numeroMaximo;
	}
}
