package prova1_1;

public class P2 {
	static Processo p2 = new Processo("P2", "127.0.0.2", 5001, P1.p1, P3.p3);

	public static void main(String[] args) {
		System.out.println("Processo P2\n");
		p2.executar();
	}
}
