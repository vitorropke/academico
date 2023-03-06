package prova1_2;

import java.io.Serializable;

public abstract class Processo implements Serializable {
	private static final long serialVersionUID = 1L;

	private String nome;
	private String endereco;
	private int porta;

	public Processo(String nome, String endereco, int porta) {
		setNome(nome);
		setEndereco(endereco);
		setPorta(porta);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public int getPorta() {
		return porta;
	}

	public void setPorta(int porta) {
		this.porta = porta;
	}
}
