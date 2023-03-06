package prova1_1;

public class Processo {
	private String nomeProcesso;
	private String endereco;
	private int porta;
	private Processo processoAnterior;
	private Processo proximoProcesso;

	public Processo(String nomeProcesso, String endereco, int porta, Processo processoAnterior,
			Processo proximoProcesso) {
		setNomeProcesso(nomeProcesso);
		setEndereco(endereco);
		setPorta(porta);
		setProcessoAnterior(processoAnterior);
		setProximoProcesso(proximoProcesso);
	}

	public String getNomeProcesso() {
		return nomeProcesso;
	}

	public void setNomeProcesso(String nomeProcesso) {
		this.nomeProcesso = nomeProcesso;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public int getPorta() {
		return porta;
	}

	public void setPorta(int porta) {
		this.porta = porta;
	}

	public Processo getProcessoAnterior() {
		return processoAnterior;
	}

	public void setProcessoAnterior(Processo processoAnterior) {
		this.processoAnterior = processoAnterior;
	}

	public Processo getProximoProcesso() {
		return proximoProcesso;
	}

	public void setProximoProcesso(Processo proximoProcesso) {
		this.proximoProcesso = proximoProcesso;
	}

	public void executar() {
		ThreadEmissora emissor = new ThreadEmissora(proximoProcesso);
		ThreadReceptora receptor = new ThreadReceptora(porta, processoAnterior, proximoProcesso);

		Thread t0 = new Thread(emissor);
		Thread t1 = new Thread(receptor);

		t0.start();
		t1.start();
	}
}
