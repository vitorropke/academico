package com.company;

import java.util.Random;
import java.math.BigInteger;
import java.io.UnsupportedEncodingException;

public class RSA {
	static Random random = new Random();

	// https://stackoverflow.com/questions/2385909/what-would-be-the-fastest-method-to-test-for-primality-in-java
	public static boolean isPrime(int n) {
		if (n < 2) {
			return false;
		}
		if ((n == 2) || (n == 3)) {
			return true;
		}
		if ((n % 2 == 0) || (n % 3 == 0)) {
			return false;
		}

		int sqrtN = (int) Math.sqrt(n) + 1;

		for (int i = 6; i <= sqrtN; i += 6) {
			if ((n % (i - 1) == 0) || (n % (i + 1) == 0)) {
				return false;
			}
		}
		return true;
	}

	public static int[] twoRandomPrimes(int numeroMaximo) {
		int numeroAleatorio = random.nextInt(numeroMaximo);
		int resultados[] = new int[2];

		// Gera números aleatórios até achar um primo
		while (!isPrime(numeroAleatorio)) {
			numeroAleatorio = random.nextInt(numeroMaximo);
		}

		// Salva o número encotrado na primeira posição do vetor
		resultados[0] = numeroAleatorio;
		numeroAleatorio = random.nextInt(numeroMaximo);

		// Gera números aleatórios até achar um primo e que seja diferente do primeiro
		// número
		while (!isPrime(numeroAleatorio) || numeroAleatorio == resultados[0]) {
			numeroAleatorio = random.nextInt(numeroMaximo);
		}

		// Salva o número encotrado na segunda posição do vetor
		resultados[1] = numeroAleatorio;

		resultados[0] = 397;
		resultados[1] = 3;

		return resultados;
	}

	// https://www.geeksforgeeks.org/java-program-for-common-divisors-of-two-numbers/
	// https://www.baeldung.com/java-greatest-common-divisor
	public static int maximoDivisorComum(int a, int b) {
		if (a == 0) {
			return b;
		}

		return maximoDivisorComum(b % a, a);
	}

	// https://www.geeksforgeeks.org/java-program-for-common-divisors-of-two-numbers/
	public static boolean coprimo(int a, int b) {
		if (maximoDivisorComum(a, b) == 1) {
			return true;
		} else {
			return false;
		}
	}

	// retirado do slide do professor
	public static int inversoMultiplicativo(int e, int funcaoTotiente) {
		int indice = 1;

		while (true) {
			if ((e * indice) % funcaoTotiente == 1) {
				return indice;
			}

			indice++;
		}
	}

	public static int[] gerarChaves() {
		int chaves[] = new int[3];

		int numerosPeQ[];
		int n;
		int funcaoTotiente;

		do {
			// encontra 'p' e 'q', com número máximo no parâmetro
			// 'p' é a primeira chave privada e 'q' é a segunda chave privada
			numerosPeQ = RSA.twoRandomPrimes(Integer.SIZE);
			// calcula 'n'
			n = numerosPeQ[0] * numerosPeQ[1];
			// calcula phi(n)
			funcaoTotiente = (numerosPeQ[0] - 1) * (numerosPeQ[1] - 1);
		} while (funcaoTotiente < 3);

		int e;
		do {
			// encontra 'e', com valor máximo definido pela funcao Totiente de 'n'
			// enquanto 'e' e a função totiente não forem coprimos, procure por outro número
			// e enquanto o valor for menor que 2
			e = random.nextInt(funcaoTotiente);
		} while (e < 2 || !coprimo(e, funcaoTotiente));

		// calcula 'd'
		int d = inversoMultiplicativo(e, funcaoTotiente);

		chaves[0] = n;
		chaves[1] = e;
		chaves[2] = d;

		return chaves;
	}

	public static int[] encriptar(String entrada, int n, int e) {
		int tamanhoEntrada = entrada.length();
		int cifras[] = new int[tamanhoEntrada];
		BigInteger charToBig;
		BigInteger bigN = BigInteger.valueOf(n);
		BigInteger bigE = BigInteger.valueOf(e);

		// Percorre cada caractere da entrada
		for (int i = 0; i < tamanhoEntrada; i++) {
			// char para big int
			charToBig = BigInteger.valueOf(entrada.charAt(i));

			// entrada[i]^e % n
			cifras[i] = charToBig.modPow(bigE, bigN).intValue();
		}

		return cifras;
	}

	public static String decriptar(int[] entrada, int n, int d) {
		String saida = "";
		BigInteger bigEntrada;
		BigInteger bigN = BigInteger.valueOf(n);
		BigInteger bigD = BigInteger.valueOf(d);

		int tamanhoEntrada = entrada.length;

		// Percorre cada valor da entrada
		for (int i = 0; i < tamanhoEntrada; i++) {
			bigEntrada = BigInteger.valueOf(entrada[i]);

			try {
				// entrada[i]^d % n
				saida += new String(bigEntrada.modPow(bigD, bigN).toByteArray(), "UTF-8");
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
		}

		return saida;
	}
}
