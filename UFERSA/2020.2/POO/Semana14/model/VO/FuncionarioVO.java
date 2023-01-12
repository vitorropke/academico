package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.util.ArrayList;

public class FuncionarioVO extends UsuarioVO {
	private static final long serialVersionUID = 1L;
	private static boolean tipoUsuario = false;

	// Construtores
	public FuncionarioVO() {
	}

	public FuncionarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco) {
		super(login, senha, nome, cpf, endereco);
	}

	public FuncionarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email) {
		super(login, senha, nome, cpf, endereco, email);
	}

	public FuncionarioVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email, ArrayList<String> telefone) {
		super(login, senha, nome, cpf, endereco, email, telefone);
	}

	// toString
	@Override
	public String toString() {
		String funcionario = "";

		funcionario += "\nTipo:\t\t";

		if (tipoUsuario) {
			funcionario += "Gerente\n";
		} else {
			funcionario += "Funcionario\n";
		}

		funcionario += super.toString();

		return funcionario;
	}

	// Getters e setters
	public static boolean isTipoUsuario() {
		return tipoUsuario;
	}

	public static void setTipoUsuario(boolean tipoUsuario) {
		FuncionarioVO.tipoUsuario = tipoUsuario;
	}
}
