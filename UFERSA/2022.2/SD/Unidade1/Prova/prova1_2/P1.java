package prova1_2;

public class P1 {
	static ProcessoCentral p1 = new ProcessoCentral("P1", "127.0.0.1", 5000);

	public static void main(String[] args) {
		System.out.println("Processo P1\n");
		p1.executar();
	}
}
