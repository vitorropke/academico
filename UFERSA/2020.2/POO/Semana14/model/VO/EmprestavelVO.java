package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.io.Serializable;
import java.util.Calendar;

public abstract class EmprestavelVO implements Serializable {
	private static final long serialVersionUID = 1L;

	// Variáveis
	private String titulo;
	private int numeroExemplares;
	private int numeroEmprestimos;
	private int numeroDiasAlugado;
	private int anoLancamento;
	private float valorAluguel;

	// Construtores
	public EmprestavelVO() {
	}

	public EmprestavelVO(String titulo, int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setNumeroExemplares(0);
		setNumeroEmprestimos(0);
		setNumeroDiasAlugado(0);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}

	public EmprestavelVO(String titulo, int numeroExemplares, int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(0);
		setNumeroDiasAlugado(0);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}

	public EmprestavelVO(String titulo, int numeroExemplares, int numeroEmprestimos, int numeroDiasAlugado,
			int anoLancamento, float valorAluguel) {
		setTitulo(titulo);
		setNumeroExemplares(numeroExemplares);
		setNumeroEmprestimos(numeroEmprestimos);
		setNumeroDiasAlugado(numeroDiasAlugado);
		setAnoLancamento(anoLancamento);
		setValorAluguel(valorAluguel);
	}

	// toString
	@Override
	public String toString() {
		String emprestavel = "";
		String valorAluguelDoisDecimais = String.format("%.02f", valorAluguel);

		emprestavel = "\nTitulo:\t\t\t" + titulo;
		emprestavel += "\nNumero de exemplares:\t" + numeroExemplares;
		emprestavel += "\nNumero de emprestimos:\t" + numeroEmprestimos;
		emprestavel += "\nNumero de dias alugado:\t" + numeroDiasAlugado;
		emprestavel += "\nAno de lancamento:\t" + anoLancamento;
		emprestavel += "\nValor do aluguel:\t" + "R$" + valorAluguelDoisDecimais;

		return emprestavel;
	}

	// Getters e setters
	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		if ((titulo != null) && (!titulo.isBlank())) {
			this.titulo = titulo;
		} else {
			System.out.println("Titulo nao pode ser vazio!");
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
}
