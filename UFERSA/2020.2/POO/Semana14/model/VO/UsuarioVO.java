package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.util.ArrayList;

public abstract class UsuarioVO extends PessoaVO {
	private static final long serialVersionUID = 1L;

	// Variáveis
	private String login;
	private String senha;

	// Construtores
	public UsuarioVO() {
	}

	public UsuarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco) {
		super(nome, cpf, endereco);
		setLogin(login);
		setSenha(senha);
	}

	public UsuarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email) {
		super(nome, cpf, endereco, email);
		setLogin(login);
		setSenha(senha);
	}

	public UsuarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email, ArrayList<String> telefone) {
		super(nome, cpf, endereco, email, telefone);
		setLogin(login);
		setSenha(senha);
	}

	// toString
	@Override
	public String toString() {
		String usuario = "";

		usuario = "\nLogin:\t\t" + login;
		usuario += "\nSenha:\t\t" + senha;

		usuario += super.toString() + "\n";

		return usuario;
	}

	// Getters e setters
	public String getLogin() {
		return login;
	}

	public void setLogin(String login) {
		if ((login != null) && (!login.isBlank())) {
			this.login = login;
		} else {
			System.out.println("Login nao pode ser vazio!");
		}
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		if ((senha != null) && (!senha.isBlank())) {
			this.senha = senha;
		} else {
			System.out.println("Senha nao pode ser vazia!");
		}
	}
}
