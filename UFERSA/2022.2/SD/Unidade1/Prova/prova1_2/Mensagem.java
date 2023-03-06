package prova1_2;

import java.io.Serializable;

public class Mensagem implements Serializable {
	private static final long serialVersionUID = 1L;

	private String mensagem;
	private Processo processoOrigem;
	private Processo processoDestino;

	public Mensagem(String mensagem, Processo processoOrigem, Processo processoDestino) {
		setMensagem(mensagem);
		setProcessoOrigem(processoOrigem);
		setProcessoDestino(processoDestino);
	}

	public String getMensagem() {
		return mensagem;
	}

	public void setMensagem(String mensagem) {
		this.mensagem = mensagem;
	}

	public Processo getProcessoOrigem() {
		return processoOrigem;
	}

	public void setProcessoOrigem(Processo processoOrigem) {
		this.processoOrigem = processoOrigem;
	}

	public Processo getProcessoDestino() {
		return processoDestino;
	}

	public void setProcessoDestino(Processo processoDestino) {
		this.processoDestino = processoDestino;
	}
}
