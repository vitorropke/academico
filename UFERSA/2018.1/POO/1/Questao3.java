import java.util.Scanner; // Importa biblioteca para entrada de dados

class Potencia{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in); // Cria classe para entrada de dados
		int base, expoente, resultado = 1; // Declaração de variáveis
		
		System.out.print("Digite uma base: ");
		base = entrada.nextInt(); // Entrada de dados
		System.out.print("Digite um expoente: ");
		expoente = entrada.nextInt(); // Entrada de dados
		
		for(int contador = 1; contador <= expoente; contador++){
			resultado = resultado * base;
		}
		
		System.out.println("\n" + base + "^" + expoente + " = " + resultado);
	}
}