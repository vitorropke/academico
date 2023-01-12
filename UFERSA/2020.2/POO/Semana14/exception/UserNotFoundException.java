package br.edu.ufersa.ropke.locadoramaven.exception;

public class UserNotFoundException extends RuntimeException {
	private static final long serialVersionUID = 1L;

	public UserNotFoundException() {
		super("Usuario nao encontrado");
	}
}
