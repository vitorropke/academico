package prova;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Servidor {

	private static List<Usuario> usuariosCadastrados = new ArrayList<>(
			Arrays.asList(new Cliente("cliente", "123"), new Funcionario("funcionario", "456")));
	public static final String endereco = "192.168.0.107";
	public static final int porta = 1099;

	private static void config() {
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

	public static void main(String[] args) {
		config();

		try {
			ImplLoja loja = new ImplLoja();
			Loja skeleton = (Loja) UnicastRemoteObject.exportObject(loja, 0);

			LocateRegistry.createRegistry(porta);

			Registry registro = LocateRegistry.getRegistry(porta);
			registro.bind("Loja", skeleton);

			System.out.println("Servidor pronto:");
		} catch (Exception e) {
			System.err.println("Servidor: " + e.toString());
			e.printStackTrace();
		}

	}

	public static Usuario autenticarUsuario(String login, String senha) {
		for (Usuario usuario : usuariosCadastrados) {
			if (usuario.getNome().equals(login) && usuario.getSenha().equals(senha)) {
				return usuario;
			}
		}

		return null;
	}

}
