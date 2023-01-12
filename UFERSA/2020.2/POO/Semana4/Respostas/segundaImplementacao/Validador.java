import java.util.InputMismatchException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Validador {
	// Validador de cpf
	// https://www.devmedia.com.br/validando-o-cpf-em-uma-aplicacao-java/22097
	public static boolean isCpf(String cpf) {
		// considera-se erro, CPF's formados por uma sequencia de numeros iguais
		if (cpf.equals("00000000000") || cpf.equals("11111111111")
				|| cpf.equals("22222222222") || cpf.equals("33333333333")
				|| cpf.equals("44444444444") || cpf.equals("55555555555")
				|| cpf.equals("66666666666") || cpf.equals("77777777777")
				|| cpf.equals("88888888888") || cpf.equals("99999999999")
				|| (cpf.length() != 11)) {
			return false;
		}

		char	digito10, digito11;
		int		somaDigitos, resto, numero, peso;

		// "try" - protege o codigo para eventuais erros de conversao de tipo (int)
		try {
			// Calculo do 1º. Digito Verificador
			somaDigitos = 0;
			peso = 10;
			for (int x = 0; x < 9; x++) {
				/*
				 *	converte o x-esimo caractere do cpf em um numero:
				 *	por exemplo, transforma o caractere '0' no inteiro 0
				 *	(48 é a posicao de '0' na tabela ASCII)
				 */
				numero = (int)(cpf.charAt(x) - 48);
				somaDigitos = somaDigitos + (numero * peso);
				peso = peso - 1;
			}

			resto = 11 - (somaDigitos % 11);
			if ((resto == 10) || (resto == 11)) {
				digito10 = '0';
			} else {
				digito10 = (char)(resto + 48); // converte no respectivo caractere numerico
			}

			// Calculo do 2º. Digito Verificador
			somaDigitos = 0;
			peso = 11;
			for(int x = 0; x < 10; x++) {
				numero = (int)(cpf.charAt(x) - 48);
				somaDigitos = somaDigitos + (numero * peso);
				peso = peso - 1;
			}

			resto = 11 - (somaDigitos % 11);
			if ((resto == 10) || (resto == 11)) {
				digito11 = '0';
			} else {
				digito11 = (char)(resto + 48);
			}

			// Verifica se os digitos calculados conferem com os digitos informados.
			if ((digito10 == cpf.charAt(9)) && (digito11 == cpf.charAt(10))) {
				return true;
			} else {
				return false;
			}
		} catch (InputMismatchException erro) {
			return false;
		}
	}

	// https://stackoverflow.com/questions/8204680/java-regex-email
	public static boolean isEmail(String email) {
		final Pattern EMAIL_REGEX = Pattern.compile("[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?", Pattern.CASE_INSENSITIVE);
		return EMAIL_REGEX.matcher(email).matches();
	}
}
