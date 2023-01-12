package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.util.ArrayList;

public class ClienteVO extends PessoaVO {
	private static final long serialVersionUID = 1L;

	// Construtores
	public ClienteVO() {
	}

	public ClienteVO(String nome, String cpf, ArrayList<String> endereco) {
		super(nome, cpf, endereco);
	}

	public ClienteVO(String nome, String cpf, ArrayList<String> endereco, ArrayList<String> email) {
		super(nome, cpf, endereco, email);
	}

	public ClienteVO(String nome, String cpf, ArrayList<String> endereco, ArrayList<String> email,
			ArrayList<String> telefone) {
		super(nome, cpf, endereco, email, telefone);
	}
}
