package br.edu.ufersa.ropke.locadoramaven.model.VO;

public class LivroVO extends EmprestavelVO {
	private static final long serialVersionUID = 1L;

	// Variáveis
	private String genero;
	private int numeroPaginas;

	// Construtores
	public LivroVO() {
	}

	public LivroVO(String titulo, String genero, int numeroPaginas, int anoLancamento, float valorAluguel) {
		super(titulo, anoLancamento, valorAluguel);
		setGenero(genero);
		setNumeroPaginas(numeroPaginas);
	}

	public LivroVO(String titulo, String genero, int numeroPaginas, int numeroExemplares, int anoLancamento,
			float valorAluguel) {
		super(titulo, numeroExemplares, anoLancamento, valorAluguel);
		setGenero(genero);
		setNumeroPaginas(numeroPaginas);
	}

	public LivroVO(String titulo, String genero, int numeroPaginas, int numeroExemplares, int numeroEmprestimos,
			int numeroDiasAlugado, int anoLancamento, float valorAluguel) {
		super(titulo, numeroExemplares, numeroEmprestimos, numeroDiasAlugado, anoLancamento, valorAluguel);
		setGenero(genero);
		setNumeroPaginas(numeroPaginas);
	}

	// toString
	@Override
	public String toString() {
		String livro = "";

		livro += super.toString();
		livro += "\nGenero:\t\t\t" + genero;
		livro += "\nNumero de paginas:\t" + numeroPaginas + "\n";

		return livro;
	}

	// Getters e setters
	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		if ((genero != null) && (!genero.isBlank())) {
			this.genero = genero;
		} else {
			System.out.println("Genero nao pode ser vazio!");
		}
	}

	public int getNumeroPaginas() {
		return numeroPaginas;
	}

	public void setNumeroPaginas(int numeroPaginas) {
		if (numeroPaginas > 0) {
			this.numeroPaginas = numeroPaginas;
		} else {
			System.out.println("Numero de paginas nao pode ser 0!");
		}
	}
}
