package prova1_1;

import java.io.Serializable;

public class Mensagem implements Serializable {
	private static final long serialVersionUID = 1L;

	private String mensagem;
	private int portaDestino;
	private long idProcessoOrigem;

	public Mensagem(String mensagem, int portaDestino, long idProcessoOrigem) {
		setMensagem(mensagem);
		setPortaDestino(portaDestino);
		setIdProcessoOrigem(idProcessoOrigem);
	}

	public String getMensagem() {
		return mensagem;
	}

	public void setMensagem(String mensagem) {
		this.mensagem = mensagem;
	}

	public int getPortaDestino() {
		return portaDestino;
	}

	public void setPortaDestino(int portaDestino) {
		this.portaDestino = portaDestino;
	}

	public long getIdProcessoOrigem() {
		return idProcessoOrigem;
	}

	public void setIdProcessoOrigem(long idProcessoOrigem) {
		this.idProcessoOrigem = idProcessoOrigem;
	}
}
