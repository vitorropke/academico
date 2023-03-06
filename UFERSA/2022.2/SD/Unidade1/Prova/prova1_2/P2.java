package prova1_2;

public class P2 {
	static ProcessoSecundario p2 = new ProcessoSecundario("P2", "127.0.0.2", 5001, P1.p1);

	public static void main(String[] args) {
		System.out.println("Processo P2\n");
		p2.executar();
	}
}
