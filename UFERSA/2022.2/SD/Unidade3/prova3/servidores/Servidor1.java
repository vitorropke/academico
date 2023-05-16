package prova3.servidores;

public class Servidor1 {

	private static final String endereco = "127.0.0.2";
	private static final int porta = 65001;

	public static String getEndereco() {
		return endereco;
	}

	public static int getPorta() {
		return porta;
	}

	public static void main(String[] args) {
		Servidor.executar(endereco, porta);
	}

}
