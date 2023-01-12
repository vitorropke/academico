package com.company;

public class Pessoa {
	private int idade;
	private String nome;
	private String CPF;
	private String endereco;
	private String email;

	public Pessoa(int idade, String nome, String CPF, String endereco, String email) {
		this.idade = idade;
		this.nome = nome;
		this.CPF = CPF;
		this.endereco = endereco;
		this.email = email;

	}

	public int getIdade() {
		return idade;
	}

	public Pessoa setIdade(int idade) {
		this.idade = idade;
		return this;
	}

	public String getNome() {
		return nome;
	}

	public Pessoa setNome(String nome) {
		this.nome = nome;
		return this;
	}

	public String getCPF() {
		return CPF;
	}

	public Pessoa setCPF(String CPF) {
		this.CPF = CPF;
		return this;
	}

	public String getEndereco() {
		return endereco;
	}

	public Pessoa setEndereco(String endereco) {
		this.endereco = endereco;
		return this;
	}

	public String getEmail() {
		return email;
	}

	public Pessoa setEmail(String email) {
		this.email = email;
		return this;
	}

	@Override
	public String toString() {
		return "Pessoa{" + "idade=" + idade + ", nome='" + nome + '\'' + ", CPF='" + CPF + '\'' + ", endereco='"
				+ endereco + '\'' + ", email='" + email + '\'' + '}';
	}
	// TODO: 31/03/2021
}
