package lab03.singleton;

public class Main {

	public static void main(String[] args) {
		// Cria a instancia
		Singleton.getInstance();

		System.out.println();
		// Usa a instancia criada
		Singleton.getInstance();
		Singleton.getInstance();
		Singleton.getInstance();
	}

}
