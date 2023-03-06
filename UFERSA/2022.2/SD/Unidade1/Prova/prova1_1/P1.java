package prova1_1;

public class P1 {
	static Processo p1 = new Processo("P1", "127.0.0.1", 5000, P4.p4, P2.p2);

	public static void main(String[] args) {
		System.out.println("Processo P1\n");
		p1.executar();
	}
}
