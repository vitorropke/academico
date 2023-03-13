package prova1_2;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ThreadEmissora implements Runnable {
	private Processo processoRemetente;
	private ProcessoCentral processoCentral;

	public ThreadEmissora(Processo processoRemetente, ProcessoCentral processoCentral) {
		this.processoRemetente = processoRemetente;
		this.processoCentral = processoCentral;
	}

	public static void enviarMensagem(Mensagem mensagem, Processo processoDestinatario) {
		try {
			Socket socket = new Socket(processoDestinatario.getEndereco(), processoDestinatario.getPorta());
			ObjectOutputStream saida = new ObjectOutputStream(socket.getOutputStream());
			saida.writeObject(mensagem);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
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
			Processo processoDestinatario = null;

			String processoDestino = "";
			do {
				System.out.println();
				System.out.println("P1 (todos)");
				for (int i = 2; i <= 4; i++) {
					System.out.println("P" + i);
				}
				System.out.print("Digite para quem deseja envia-la: ");
				processoDestino = teclado.nextLine();

				switch (processoDestino.toUpperCase()) {
				case "P1":
				case "1":
					processoDestinatario = P1.p1;
					break;
				case "P2":
				case "2":
					processoDestinatario = P2.p2;
					break;
				case "P3":
				case "3":
					processoDestinatario = P3.p3;
					break;
				case "P4":
				case "4":
					processoDestinatario = P4.p4;
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

			Mensagem mensagem = new Mensagem(mensagemTeclado, processoRemetente, processoDestinatario);

			if (processoRemetente.equals(processoCentral)) {
				// Se o remetente for o processo central, envia a mensagem direto ao
				// destinatário.
				enviarMensagem(mensagem, processoDestinatario);
			} else {
				// Caso contrário, envia a mensagem para o processo central.
				enviarMensagem(mensagem, processoCentral);
			}

			System.out.print("\nMensagem enviada para ");
			System.out.print((processoDestinatario.getPorta() == processoCentral.getPorta()) ? "todos"
					: processoDestinatario.getNome());
			System.out.println(": " + mensagem.getMensagem() + "\n");
		} while (conexao);

		teclado.close();
		System.exit(0);
	}
}
