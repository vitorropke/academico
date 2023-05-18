package lab03.singleton;

public class Singleton {
	private static Singleton instance;

	private Singleton() {
		System.out.println("Voce criou uma nova instancia!");
	}

	public static Singleton getInstance() {
		if (instance == null) {
			instance = new Singleton();
		} else {
			System.out.println("Voce esta usando uma instancia ja criada!");
		}

		return instance;
	}
}
