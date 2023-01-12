import java.util.Calendar;

class Disco {
	// Variáveis
	private String	titulo;
	private String	nomeBanda;
	private String	estilo;
	private int		numeroExemplares;
	private int		numeroEmprestimos;
	private int		numeroDiasAlugado;
	private int		anoLancamento;
	private float	valorAluguel;

	// Construtores
	public Disco(String titulo, String nomeBanda, String estilo, int numeroExemplares, int anoLancamento, 
			float valorAluguel) {
		setTitulo(titulo);
		setNomeBanda(nomeBanda);
		setEstilo(estilo);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(0);
		setNumeroDiasAlugado(0);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}
	public Disco(String titulo, String nomeBanda, String estilo, int numeroExemplares, int numeroEmprestimos,
			int numeroDiasAlugado, int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setNomeBanda(nomeBanda);
		setEstilo(estilo);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(numeroEmprestimos);
		setNumeroDiasAlugado(numeroDiasAlugado);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}

	public String toString() {
		String disco = "";
		String valorAluguelDoisDecimais = String.format("%.02f", valorAluguel);

		disco = "Titulo:                 " + titulo;
		disco += "\nNome da banda:          " + nomeBanda;
		disco += "\nEstilo:                 " + estilo;
		disco += "\nNumero de exemplares:   " + numeroExemplares;
		disco += "\nNumero de emprestimos:  " + numeroEmprestimos;
		disco += "\nNumero de dias alugado: " + numeroDiasAlugado;
		disco += "\nAno de lancamento:      " + anoLancamento;
		disco += "\nValor do aluguel:       " + "R$" + valorAluguelDoisDecimais;
		
		return disco;
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
	
	public String getNomeBanda() {
		return nomeBanda;
	}
	public void setNomeBanda(String nomeBanda) {
		if ((nomeBanda != null) && (nomeBanda != "")) {
			this.nomeBanda = nomeBanda;
		} else {
			System.out.println("Nome da banda nao pode ser vazio!");
		}
	}
	
	public String getEstilo() {
		return estilo;
	}
	public void setEstilo(String estilo) {
		if ((estilo != null) && (estilo != "")) {
			this.estilo = estilo;
		} else {
			System.out.println("Estilo nao pode ser vazio!");
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
	public void cadastrar(Disco disco) {
		// adiciona o disco ao "banco de dados"
	}
	
	public void alterar(Disco disco) {
		// altera os atributos do disco no "banco de dados"
	}
	
	public void deletar(Disco disco) {
		// apaga o disco do "banco de dados"
		
		disco.titulo = null;
		disco.nomeBanda = null;
		disco.estilo = null;
		disco.numeroExemplares = null;
		disco.numeroEmprestimos = null;
		disco.numeroDiasAlugado = null;
		disco.anoLancamento = null;
		disco.valorAluguel = null;
	}
	
	public Disco pesquisarTitulo(String titulo) {
		return Disco;
	}

	public Disco[] pesquisarBanda(String banda) {
		return Disco;
	}

	public Disco[] pesquisarEstilo(String estilo) {
		return Disco;
	}

	public Disco[] pesquisarAno(Calendar anoLancamento) {
		return Disco;
	}
	*/
}
