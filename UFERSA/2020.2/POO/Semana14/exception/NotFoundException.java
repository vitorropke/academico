package br.edu.ufersa.ropke.locadoramaven.exception;

public class NotFoundException extends RuntimeException {
	private static final long serialVersionUID = 1L;

	public NotFoundException() {
		super("Objeto nao existe");
	}
}
