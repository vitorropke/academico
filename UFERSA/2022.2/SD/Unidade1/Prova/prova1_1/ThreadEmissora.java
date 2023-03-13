package prova1_1;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.lang.management.ManagementFactory;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class ThreadEmissora implements Runnable {
	private Processo processoDestinatario;

	public ThreadEmissora(Processo processoDestinatario) {
		this.processoDestinatario = processoDestinatario;
	}

	public static void enviarMensagem(Mensagem mensagem, Processo processoDestinatario) {
		try {
			// Converte o objeto "Mensagem" para outro objeto que pode ser convertido em
			// bytes.
			// https://stackoverflow.com/questions/4252294/sending-objects-across-network-using-udp-in-java
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(baos);
			oos.writeObject(mensagem);

			// Transformando em bytes.
			byte[] bufferEnvio = baos.toByteArray();

			InetAddress endereco = InetAddress.getByName(processoDestinatario.getEndereco());
			DatagramPacket datagramaEnvio = new DatagramPacket(bufferEnvio, bufferEnvio.length, endereco,
					processoDestinatario.getPorta());

			// Envia o datagrama.
			DatagramSocket socket = new DatagramSocket();
			socket.send(datagramaEnvio);
			socket.close();

			System.out.println("\nMensagem enviada para " + processoDestinatario.getNomeProcesso() + ": "
					+ mensagem.getMensagem() + "\n");
		} catch (IOException e) {
			System.err.println("Nao e possivel operar esse tipo de dado. Tente outra vez!\n\n");
			e.printStackTrace();
			e.getStackTrace();
			e.getLocalizedMessage();
		}
	}

	@Override
	public void run() {
		Scanner teclado = new Scanner(System.in);

		boolean conexao = true;
		do {
			// Lê a mensagem.
			System.out.print("Digite sua mensagem: ");
			String mensagemTeclado = teclado.nextLine();

			// Verifica se é para sair.
			if (mensagemTeclado.equalsIgnoreCase("tchau")) {
				conexao = false;
			}

			// Define o processo de destino.
			int portaDestino = processoDestinatario.getPorta();

			String processoDestino = "";
			do {
				System.out.println();
				for (int i = 1; i <= 4; i++) {
					System.out.println("P" + i);
				}
				System.out.print("Digite para quem deseja envia-la: ");
				processoDestino = teclado.nextLine();

				switch (processoDestino.toUpperCase()) {
				case "P1":
				case "1":
					portaDestino = P1.p1.getPorta();
					break;
				case "P2":
				case "2":
					portaDestino = P2.p2.getPorta();
					break;
				case "P3":
				case "3":
					portaDestino = P3.p3.getPorta();
					break;
				case "P4":
				case "4":
					portaDestino = P4.p4.getPorta();
					break;
				default:
					processoDestino = "";
					break;
				}

				// Exige nova entrada se for inválida.
				if (processoDestino.equals("")) {
					System.err.println("\nInforme um processo valido");
				}
			} while (processoDestino.equals(""));

			long pid = ManagementFactory.getRuntimeMXBean().getPid();
			Mensagem mensagem = new Mensagem(mensagemTeclado, portaDestino, pid);

			enviarMensagem(mensagem, processoDestinatario);
		} while (conexao);

		teclado.close();
		System.exit(0);
	}
}
