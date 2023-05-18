package prova3.loja;

import java.io.Serializable;

import prova3.categorias.*;

public class Carro implements Serializable, Comparable<Carro> {

	private static final long serialVersionUID = 1L;

	private String nome;
	private String renavan;
	private Categoria categoria;
	private int anoFabricacao;
	private int quantidadeDisponivel;
	private double preco;

	public Carro(String nome, String renavan, Categoria categoria, int anoFabricacao, int quantidadeDisponivel,
			double preco) {
		this.nome = nome;
		this.renavan = renavan;
		this.categoria = categoria;
		this.anoFabricacao = anoFabricacao;
		this.quantidadeDisponivel = quantidadeDisponivel;
		this.preco = preco;
	}

	@Override
	public String toString() {
		String resultado = "";

		resultado += "nome=" + nome;
		resultado += ", renavan=" + renavan;

		resultado += ", categoria=";
		if (categoria instanceof Economico) {
			resultado += "economico";
		} else if (categoria instanceof Intermediario) {
			resultado += "intermediario";
		} else {
			resultado += "executivo";
		}

		resultado += ", ano de fabricacao=" + anoFabricacao;
		resultado += ", quantidade disponivel=" + quantidadeDisponivel;
		resultado += ", preco=" + preco + "\n";

		return resultado;
	}

	@Override
	public int compareTo(Carro outroCarro) {
		return nome.compareTo(outroCarro.getNome());
	}

	public static long getSerialversionuid() {
		return serialVersionUID;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getRenavan() {
		return renavan;
	}

	public void setRenavan(String renavan) {
		this.renavan = renavan;
	}

	public Categoria getCategoria() {
		return categoria;
	}

	public void setCategoria(Categoria categoria) {
		this.categoria = categoria;
	}

	public int getAnoFabricacao() {
		return anoFabricacao;
	}

	public void setAnoFabricacao(int anoFabricacao) {
		this.anoFabricacao = anoFabricacao;
	}

	public int getQuantidadeDisponivel() {
		return quantidadeDisponivel;
	}

	public void setQuantidadeDisponivel(int quantidadeDisponivel) {
		this.quantidadeDisponivel = quantidadeDisponivel;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

}
