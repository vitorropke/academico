public class Biblioteca {
	private String nome, local;
	protected static int livros;
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if(!nome.isEmpty()) {
			this.nome = nome;
		}else {
			this.nome = "Desconhecido";
		}
	}
	
	public String getLocal() {
		return local;
	}
	public void setLocal(String local) {
		if(!local.isEmpty()) {
			this.local = local;
		}else {
			this.local = "Desconhecido";
		}
	}
	
	public static int getLivros() {
		return livros;
	}
	public static void setLivros(int nLivros) {
		if(nLivros <= 150) {
			livros = nLivros;
		}else {
			livros = 150;
		}
	}
}
