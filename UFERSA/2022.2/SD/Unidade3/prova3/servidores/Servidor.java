package prova3.servidores;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.concurrent.ThreadLocalRandom;

import prova3.loja.ImplLoja;
import prova3.loja.Loja;

public abstract class Servidor {

	private static void config(String endereco) {
		/*
		 * Quando um objeto remoto é registrado em um servidor RMI, o servidor precisa
		 * informar aos clientes como se conectar a esse objeto. Uma das informações
		 * necessárias é o endereço IP ou nome de host do servidor. O mecanismo RMI do
		 * Java usa a propriedade do sistema "java.rmi.server.hostname" para determinar
		 * qual endereço IP ou nome de host o servidor deve usar para se registrar.
		 */
		System.setProperty("java.rmi.server.hostname", endereco);
		/*
		 * Ao definir a propriedade do sistema "java.security.policy" para um arquivo de
		 * política, como "java.policy", o programa Java informa ao ambiente de tempo de
		 * execução Java qual arquivo de política deve ser usado para determinar as
		 * permissões de segurança que o programa possui.
		 * 
		 */
		System.setProperty("java.security.policy", "java.policy");
		/*
		 * O arquivo de política especifica as permissões concedidas a um aplicativo
		 * Java. Ele pode ser usado para limitar as operações que o aplicativo pode
		 * realizar, como ler ou gravar arquivos no sistema de arquivos, acessar
		 * recursos de rede, interagir com o sistema operacional ou executar código
		 * nativo.
		 */
		/*
		 * if (System.getSecurityManager() == null) { System.setSecurityManager(new
		 * SecurityManager()); }
		 */
	}

	public static void executar(String endereco, int porta) {
		config(endereco);

		try {
			ImplLoja loja = new ImplLoja();
			Loja skeleton = (Loja) UnicastRemoteObject.exportObject(loja, 0);

			LocateRegistry.createRegistry(porta);

			String nome = "Loja";
			Registry registro = LocateRegistry.getRegistry(porta);
			registro.bind(nome, skeleton);

			System.out.println("Servidor pronto:");

			while (true) {
				Thread.sleep(1000);

				// Simula uma queda de 5 segundos
				if (ThreadLocalRandom.current().nextInt(0, 10) == 5) {
					System.err.println("Offline!");

					registro.unbind(nome);
					UnicastRemoteObject.unexportObject(loja, true);
					Thread.sleep(5000);
					skeleton = (Loja) UnicastRemoteObject.exportObject(loja, 0);
					registro.rebind(nome, skeleton);

					System.out.println("Online!");
				}
			}
		} catch (Exception e) {
			System.err.println("Servidor: " + e.toString());
			e.printStackTrace();
		}

	}

}
