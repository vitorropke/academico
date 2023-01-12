import java.util.Calendar;

class Livro {
	// Variáveis
	private String	titulo;
	private String	genero;
	private int		numeroPaginas;
	private int		numeroExemplares;
	private int		numeroEmprestimos;
	private int		numeroDiasAlugado;
	private int		anoLancamento;
	private float	valorAluguel;
	
	// Construtores
	public Livro(String titulo, String genero, int numeroPaginas,
			int numeroExemplares, int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setGenero(genero);
		setNumeroPaginas(numeroPaginas);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(0);
		setNumeroDiasAlugado(0);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}
	public Livro(String titulo, String genero, int numeroPaginas,
			int numeroExemplares, int numeroEmprestimos, int numeroDiasAlugado,
			int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setGenero(genero);
		setNumeroPaginas(numeroPaginas);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(numeroEmprestimos);
		setNumeroDiasAlugado(numeroDiasAlugado);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}

	public String toString() {
		String livro = "";
		String valorAluguelDoisDecimais = String.format("%.02f", valorAluguel);

		livro = "Titulo:                 " + titulo;
		livro += "\nGenero:                 " + genero;
		livro += "\nNumero de paginas:      " + numeroPaginas;
		livro += "\nNumero de exemplares:   " + numeroExemplares;
		livro += "\nNumero de emprestimos:  " + numeroEmprestimos;
		livro += "\nNumero de dias alugado: " + numeroDiasAlugado;
		livro += "\nAno de lancamento:      " + anoLancamento;
		livro += "\nValor do aluguel:       " + "R$" + valorAluguelDoisDecimais;
		
		return livro;
	}
	
	// Getters e Setters
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		if ((titulo != null) && (titulo != "")) {
			this.titulo = titulo;
		} else {
			System.out.println("Titulo nao pode ser vazio!");
		}
	}
	
	public String getGenero() {
		return genero;
	}
	public void setGenero(String genero) {
		if ((genero != null) && (genero != "")) {
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
	
	public int getNumeroExemplares() {
		return numeroExemplares;
	}
	public void setNumeroExemplares(int numeroExemplares) {
		if (numeroExemplares >= 0) {
			this.numeroExemplares = numeroExemplares;
		} else {
			System.out.println("Numero de exemplares nao pode ser menor que 0!");
		}
	}

	public int getNumeroEmprestimos() {
		return numeroEmprestimos;
	}
	public void setNumeroEmprestimos(int numeroEmprestimos) {
		if (numeroEmprestimos >= 0) {
			this.numeroEmprestimos = numeroEmprestimos;
		} else {
			System.out.println("Numero de emprestimos nao pode ser menor que 0!");
		}
	}

	public int getNumeroDiasAlugado() {
		return numeroDiasAlugado;
	}
	public void setNumeroDiasAlugado(int numeroDiasAlugado) {
		if (numeroDiasAlugado >= 0) {
			this.numeroDiasAlugado = numeroDiasAlugado;
		} else {
			System.out.println("Dias alugado nao pode ser menor que 0!");
		}
	}

	public int getAnoLancamento() {
		return anoLancamento;
	}
	public void setAnoLancamento(int anoLancamento) {
		int anoAtual = Calendar.getInstance().get(Calendar.YEAR);

		if (anoLancamento <= anoAtual) {
			this.anoLancamento = anoLancamento;
		} else {
			System.out.println("Ano de lancamento nao pode ser no futuro!");
		}
	}

	public float getValorAluguel() {
		return valorAluguel;
	}
	public void setValorAluguel(float valorAluguel) {
		if (valorAluguel >= 0) {
			this.valorAluguel = valorAluguel;
		} else {
			System.out.println("Valor do aluguel nao pode ser menor que 0!");
		}
	}
	
	/*
	// Métodos
	public void cadastrar(Livro livro) {
		// adiciona o livro ao "banco de dados"
	}
	
	public void alterar(Livro livro) {
		// altera os atributos do livro no "banco de dados"
	}
	
	public void deletar(Livro livro) {
		// apaga o livro do "banco de dados"

		livro.titulo = null;
		livro.genero = null;
		livro.numeroPaginas = null;
		livro.numeroExemplares = null;
		livro.numeroEmprestimos = null;
		livro.numeroDiasAlugado = null;
		livro.anoLancamento = null;
		livro.valorAluguel = null;
	}
	
	public Livro pesquisarTitulo(String titulo) {
		return Livro;
	}
	
	public Livro[] pesquisarGenero(String genero) {
		return Livro;
	}
	
	public Livro[] pesquisarAno(Calendar anoLancamento) {
		return Livro;
	}
	*/
}
