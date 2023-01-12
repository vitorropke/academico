import java.util.Scanner; // Importa biblioteca para entrada de dados

class Soma{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in); // Cria classe para entrada de dados
		int numero, soma = 0; // Declaração de variáveis
		
		System.out.print("Digite um numero: ");
		numero = entrada.nextInt(); // Entrada de dados
		
		for(int contador = 1; contador <= numero; contador++){
			soma += contador;
		}
		
		System.out.println("\nA soma dos " + numero + " primeiros numeros inteiros positivos e igual a " + soma);
	}
}