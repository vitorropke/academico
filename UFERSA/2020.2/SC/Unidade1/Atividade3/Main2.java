import java.util.Random;

class Main2 {
	public static void main(String[] args) {
		String mensagemEncriptada;
		String mensagemDecriptada;
		String mensagem = "farofa temperada";

		// Cria uma chave aleatória, alfanumérica
		// https://www.baeldung.com/java-random-string
		int		limiteInferior = 48;	// numeral '0'
		int		limiteSuperior = 122;	// letra 'z'
		int		tamanhoChave = 32;		// tamanho da chave
		Random	random = new Random();

		// string aleatória 'chave'
		String chave = random.ints(limiteInferior, limiteSuperior + 1)
		.filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
		.limit(tamanhoChave)
		.collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
		.toString();

		System.out.print("Mensagem:            ");
		System.out.println(mensagem);

		System.out.print("Chave:               ");
		System.out.println(chave);
		System.out.println();

		/*
		mensagemEncriptada = CifraDeVernam.encriptar(mensagem, chave);

		System.out.print("Mensagem encriptada: ");
		System.out.println(mensagemEncriptada);

		mensagemDecriptada = CifraDeVernam.decriptar(mensagemEncriptada, chave);

		System.out.print("Mensagem decriptada: ");
		System.out.println(mensagemDecriptada);
		System.out.println();
		*/
		
		String[] chaves = Aes.expandirChave(chave);

		// 16 caracteres na entrada
		if (chaves.length == 44) {
			for (int i = 0; i < 44; i++) {
				System.out.print(i + ": ");
				System.out.println(chaves[i]);
			}
		// 24 caracteres na entrada
		} else if (chaves.length == 52) {
			for (int i = 0; i < 52; i++) {
				System.out.print(i + ": ");
				System.out.println(chaves[i]);
			}
		// 32 caracteres na entrada
		} else if (chaves.length == 60) {
			for (int i = 0; i < 60; i++) {
				System.out.print(i + ": ");
				System.out.println(chaves[i]);
			}
		}
	}
}
