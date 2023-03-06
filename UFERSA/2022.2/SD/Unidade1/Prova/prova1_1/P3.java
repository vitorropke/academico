package prova1_1;

public class P3 {
	static Processo p3 = new Processo("P3", "127.0.0.3", 5002, P2.p2, P4.p4);

	public static void main(String[] args) {
		System.out.println("Processo P3\n");
		p3.executar();
	}
}
