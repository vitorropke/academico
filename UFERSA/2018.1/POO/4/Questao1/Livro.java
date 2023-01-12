
public class Livro extends Produto {
	private String autor;
	
	public Livro(String autor, String descricao) {
		super();
		this.autor = "Machado de Assis";
		this.descricao = "Romance 65p";
	}

	public String getDescricao() {
		return descricao + " " + autor;
	}
}
