package prova1_2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ThreadReceptora implements Runnable {
	private int portaServidor;

	public ThreadReceptora(int portaServidor) {
		this.portaServidor = portaServidor;
	}

	@Override
	public void run() {
		try {
			boolean conexao = true;
			while (conexao) {
				ServerSocket servidor = new ServerSocket(portaServidor);
				Socket cliente = servidor.accept();
				servidor.close();

				ObjectInputStream entrada = new ObjectInputStream(cliente.getInputStream());
				Mensagem mensagem = (Mensagem) entrada.readObject();

				// Verifica se é para sair.
				if (mensagem.getMensagem().equalsIgnoreCase("tchau")) {
					conexao = false;
				}

				System.out.println("\n\nMensagem recebida de " + mensagem.getProcessoOrigem().getNome() + ": "
						+ mensagem.getMensagem() + "\n");

				// Se a porta do servidor for igual à porta do processo central (no momento é
				// p1).
				if (portaServidor == P1.p1.getPorta()) {
					if (mensagem.getProcessoDestino().getPorta() == P1.p1.getPorta()) {
						// Se for broadcast.
						Processo[] processos = { P2.p2, P3.p3, P4.p4 };

						for (Processo processoAtual : processos) {
							// Não envia a mensagem para o remetente nem para o processo central.
							if (processoAtual.getPorta() != mensagem.getProcessoOrigem().getPorta()) {
								ThreadEmissora.enviarMensagem(mensagem, processoAtual);

								System.out.println("\nMensagem enviada para " + processoAtual.getNome() + ": "
										+ mensagem.getMensagem() + "\n");
							}
						}
					} else {
						// Se for unicast.
						ThreadEmissora.enviarMensagem(mensagem, mensagem.getProcessoDestino());

						System.out.println("\nMensagem enviada para " + mensagem.getProcessoDestino().getNome() + ": "
								+ mensagem.getMensagem() + "\n");
					}
				}
			}

			System.exit(0);
		} catch (IOException e) {
			System.err.println("Nao e possivel operar esse tipo de dado. Tente outra vez!\n\n");
			e.printStackTrace();
			e.getStackTrace();
			e.getLocalizedMessage();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
