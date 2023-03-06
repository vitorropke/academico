package prova1_2;

public class P4 {
	static ProcessoSecundario p4 = new ProcessoSecundario("P4", "127.0.0.4", 5003, P1.p1);

	public static void main(String[] args) {
		System.out.println("Processo P4\n");
		p4.executar();
	}
}
