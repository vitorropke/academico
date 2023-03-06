package prova1_2;

public class ProcessoSecundario extends Processo {
	private static final long serialVersionUID = 1L;

	private ProcessoCentral processoCentral;

	public ProcessoSecundario(String nome, String endereco, int porta, ProcessoCentral processoCentral) {
		super(nome, endereco, porta);
		setProcessoCentral(processoCentral);
	}

	public ProcessoCentral getProcessoCentral() {
		return processoCentral;
	}

	public void setProcessoCentral(ProcessoCentral processoCentral) {
		this.processoCentral = processoCentral;
	}

	public void executar() {
		ThreadEmissora emissor = new ThreadEmissora(this, processoCentral);
		ThreadReceptora receptor = new ThreadReceptora(super.getPorta());

		Thread t0 = new Thread(emissor);
		Thread t1 = new Thread(receptor);

		t0.start();
		t1.start();
	}
}
