package br.edu.ufersa.ropke.locadoramaven.exception;

public class FoundException extends RuntimeException {
	private static final long serialVersionUID = 1L;

	public FoundException() {
		super("Objeto ja existe");
	}
}
