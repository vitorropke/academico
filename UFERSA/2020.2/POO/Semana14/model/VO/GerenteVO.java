package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.util.ArrayList;

public class GerenteVO extends UsuarioVO {
	private static final long serialVersionUID = 1L;
	private static boolean tipoUsuario = true;

	// Construtores
	public GerenteVO() {
	}

	public GerenteVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco) {
		super(login, senha, nome, cpf, endereco);
	}

	public GerenteVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email) {
		super(login, senha, nome, cpf, endereco, email);
	}

	public GerenteVO(String login, String senha, String nome, String cpf, ArrayList<String> endereco,
			ArrayList<String> email, ArrayList<String> telefone) {
		super(login, senha, nome, cpf, endereco, email, telefone);
	}

	// toString
	@Override
	public String toString() {
		String gerente = "";

		gerente += "\nTipo:\t\t";

		if (tipoUsuario) {
			gerente += "Gerente\n";
		} else {
			gerente += "Funcionario\n";
		}

		gerente += super.toString();

		return gerente;
	}

	// Getters e setters
	public static boolean isTipoUsuario() {
		return tipoUsuario;
	}

	public static void setTipoUsuario(boolean tipoUsuario) {
		GerenteVO.tipoUsuario = tipoUsuario;
	}
}
