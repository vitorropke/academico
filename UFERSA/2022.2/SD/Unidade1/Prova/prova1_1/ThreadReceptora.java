package prova1_1;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.lang.management.ManagementFactory;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class ThreadReceptora implements Runnable {
	private int porta;
	private Processo processoRemetente;
	private Processo processoDestinatario;

	public ThreadReceptora(int porta, Processo processoRemetente, Processo processoDestinatario) {
		this.porta = porta;
		this.processoRemetente = processoRemetente;
		this.processoDestinatario = processoDestinatario;
	}

	@Override
	public void run() {
		try {
			boolean conexao = true;
			do {
				// Cria o datagrama para receber uma mensagem.
				byte[] bufferRecebimento = new byte[1024];
				DatagramPacket datagramaRecebimento = new DatagramPacket(bufferRecebimento, bufferRecebimento.length);

				// Aguarda até o recebimento da mensagem.
				DatagramSocket socket = new DatagramSocket(porta);
				socket.receive(datagramaRecebimento);
				bufferRecebimento = datagramaRecebimento.getData();

				// Transforma os bytes em objeto.
				ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(bufferRecebimento));
				Mensagem mensagem = (Mensagem) ois.readObject();

				// Verifica se é para sair.
				if (mensagem.getMensagem().equalsIgnoreCase("tchau")) {
					conexao = false;
				}

				System.out.print("\n\n");
				long pid = ManagementFactory.getRuntimeMXBean().getPid();
				System.out.print(
						"[" + (((pid % 2) == 0) ? (pid * 2) : pid) + " - " + mensagem.getIdProcessoOrigem() + "] ");
				System.out.println("Mensagem recebida de " + processoRemetente.getNomeProcesso() + ": "
						+ mensagem.getMensagem() + "\n");

				// Verifica se o processo que recebeu a mensagem não está no destino.
				// Se não estiver no destino, envia a mensagem para o próximo nó.
				if (mensagem.getPortaDestino() != socket.getLocalPort()) {
					// Atualiza o ID.
					mensagem.setIdProcessoOrigem(pid);

					ThreadEmissora.enviarMensagem(mensagem, processoDestinatario);
				}

				socket.close();
			} while (conexao);
		} catch (IOException e) {
			System.err.println("Nao e possivel operar esse tipo de dado. Tente outra vez!\n\n");
			e.printStackTrace();
			e.getStackTrace();
			e.getLocalizedMessage();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		System.exit(0);
	}
}
