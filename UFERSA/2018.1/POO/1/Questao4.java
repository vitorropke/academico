import java.util.Scanner; // Importa biblioteca para entrada de dados

class Fatorial{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in); // Cria classe para entrada de dados
		int fatorial = 1, numero; // Declaracao de variaveis
		
		System.out.print("Digite um numero: "); 
		numero = entrada.nextInt(); // Entrada de dados
		
		for(int contador = 1; contador <= numero; contador++){
			fatorial = fatorial * contador;
		}
		
		System.out.println("\nFatorial = " + fatorial);
	}
}