package prova1_1;

public class P4 {
	static Processo p4 = new Processo("P4", "127.0.0.4", 5003, P3.p3, P1.p1);

	public static void main(String[] args) {
		System.out.println("Processo P4\n");
		p4.executar();
	}
}
