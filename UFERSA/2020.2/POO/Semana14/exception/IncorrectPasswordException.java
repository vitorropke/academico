package br.edu.ufersa.ropke.locadoramaven.exception;

public class IncorrectPasswordException extends RuntimeException {
	private static final long serialVersionUID = 1L;

	public IncorrectPasswordException() {
		super("Senha incorreta");
	}
}
