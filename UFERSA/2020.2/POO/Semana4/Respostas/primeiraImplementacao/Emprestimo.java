import java.util.Calendar;

class Emprestimo {
	// Variáveis
	private static float faturamento;
	private Calendar dataDevolucao;

	// Getters e Setters
	public float getFaturamento() {
		return faturamento;
	}
	public void setFaturamento(float faturamento) {
		this.faturamento = faturamento;
	}
	
	/*
	public Calendar getDataDevolucao() {
		return dataDevolucao;
	}
	public void setDataDevolucao(float dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}
	
	// Métodos
	public void alugarLivro(Livro[] livro, int[] quantidade, Cliente cliente) {
		for (int x = 0; x < livro.size(); x++) {
			livro[x].setQuantidadeExemplares(livro[x].getQuantidadeExemplares() - quantidade[x]);
			cliente.setLivro(livro[x]);
			setFaturamento(getFaturamento() + )
		}
		
	}

	public void devolverLivro(Livro[] livro, int[] quantidade, Cliente cliente) {
		for (int x = 0; x < livro.length(); x++) {
			livro[x].numeroExemplares = livro[x].numeroExemplares + quantidade[x];
		}
		cliente.livro = livro;
	}

	public void alugarDisco(Disco[] disco, int[] quantidade, Cliente cliente) {
		for (int x = 0; x < disco.length(); x++) {
			disco[x].numeroExemplares = disco[x].numeroExemplares - quantidade[x];
		}
		cliente.disco = disco;
	}

	public void devolverDisco(Disco[] disco, int[] quantidade, Cliente cliente) {
		for (int x = 0; x < disco.length(); x++) {
			disco[x].numeroExemplares = disco[x].numeroExemplares + quantidade[x];
		}
		cliente.disco = disco;
	}

	
	public void gerarRelatorio(Calendar dataInicio, Calendar dataFim) {
		
	}

	public void gerarRelatorioCliente(Cliente cliente, Calendar dataInicio, Calendar dataFim) {
		
	}
	*/
}
