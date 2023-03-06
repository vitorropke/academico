package prova1_2;

public class ProcessoCentral extends Processo {
	private static final long serialVersionUID = 1L;

	public ProcessoCentral(String nome, String endereco, int porta) {
		super(nome, endereco, porta);
	}

	public void executar() {
		ThreadEmissora emissor = new ThreadEmissora(this, this);
		ThreadReceptora receptor = new ThreadReceptora(super.getPorta());

		Thread t0 = new Thread(emissor);
		Thread t1 = new Thread(receptor);

		t0.start();
		t1.start();
	}
}
