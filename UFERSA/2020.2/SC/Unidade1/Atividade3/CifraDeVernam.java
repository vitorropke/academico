import java.util.Random;

public class CifraDeVernam {
	public static String encriptar(String mensagem, String chave) {
		if (mensagem.length() != chave.length()) {
			// a mensagem não pode ter tamanho diferente da chave
			System.out.println("Falha na encriptacao. Chave possui comprimento diferente da mensagem.");
			return "";
		}

		String mensagemEncriptada = "";

		for (int i = 0; i < mensagem.length(); i++) {
			// XOR de cada caractere
			mensagemEncriptada += (char)(mensagem.charAt(i) ^ chave.charAt(i));
		}

		return mensagemEncriptada;
	}

	public static String decriptar(String mensagem, String chave) {
		if (mensagem.length() != chave.length()) {
			// a mensagem não pode ter tamanho diferente da chave
			System.out.println("Falha na decriptacao. Chave possui comprimento diferente da mensagem.");
			return "";
		}

		String mensagemDecriptada = "";

		for (int i = 0; i < mensagem.length(); i++) {
			// XOR de cada caractere
			mensagemDecriptada += (char)(mensagem.charAt(i) ^ chave.charAt(i));
		}

		return mensagemDecriptada;
	}

	public static String gerarChave(String mensagem) {
		// Cria uma chave aleatória, alfanumérica
		// https://www.baeldung.com/java-random-string
		int		limiteInferior = 48;	// numeral '0'
		int		limiteSuperior = 122;	// letra 'z'
		int		tamanhoChave = mensagem.length();		// tamanho da chave
		Random	random = new Random();

		// string aleatória 'chave'
		String chave = random.ints(limiteInferior, limiteSuperior + 1)
		.filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
		.limit(tamanhoChave)
		.collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
		.toString();

		return chave;
	}

	public static String gerarChave(int tamanhoChave) {
		// Cria uma chave aleatória, alfanumérica
		// https://www.baeldung.com/java-random-string
		int		limiteInferior = 48;	// numeral '0'
		int		limiteSuperior = 122;	// letra 'z'
		Random	random = new Random();

		// string aleatória 'chave'
		String chave = random.ints(limiteInferior, limiteSuperior + 1)
		.filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
		.limit(tamanhoChave)
		.collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
		.toString();

		return chave;
	}
}
