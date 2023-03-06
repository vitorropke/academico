package prova1_2;

public class P3 {
	static ProcessoSecundario p3 = new ProcessoSecundario("P3", "127.0.0.3", 5002, P1.p1);

	public static void main(String[] args) {
		System.out.println("Processo P3\n");
		p3.executar();
	}
}
