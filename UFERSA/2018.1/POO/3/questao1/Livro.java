public class Livro {
	private String titulo, nomeDoAutor;
	private int anoDePublicacao, numeroDePaginas;
	private boolean status;
	
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		if(!titulo.isEmpty()) {
			this.titulo = titulo;
		}else {
			this.titulo = "Sem título";
		}
	}
	
	public String getNomeDoAutor() {
		return nomeDoAutor;
	}
	public void setNomeDoAutor(String nomeDoAutor) {
		if(!nomeDoAutor.isEmpty()) {
			this.nomeDoAutor = nomeDoAutor;
		}else {
			this.nomeDoAutor = "Autor desconhecido";
		}
	}
	
	public int getAnoDePublicacao() {
		return anoDePublicacao;
	}
	public void setAnoDePublicacao(int anoDePublicacao) {
		if(anoDePublicacao > 0 && anoDePublicacao <= 2018) {
			this.anoDePublicacao = anoDePublicacao;
		}else {
			this.anoDePublicacao = 2018;
		}
	}
	
	public int getNumeroDePaginas() {
		return numeroDePaginas;
	}
	public void setNumeroDePaginas(int numeroDePaginas) {
		if(numeroDePaginas > 150 && numeroDePaginas < 1000) {
			this.numeroDePaginas = numeroDePaginas;
		}else {
			this.numeroDePaginas = 200;
		}
	}
	
	public boolean isStatus() {
		return status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
}
