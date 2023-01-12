package br.edu.ufersa.ropke.locadoramaven.exception;

public class InvalidParameterException extends RuntimeException {
	private static final long serialVersionUID = 1L;

	public InvalidParameterException() {
		super("Um ou mais parametros estao invalidos (nulos ou vazios)");
	}
}
