import java.util.Scanner; // Importa biblioteca para entrada de dados

class Impar{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in); // Cria classe para entrada de dados
		int numero, contador = 1, numerosImpares = 0; // Declaração de variáveis
		
		System.out.print("Digite um numero: ");
		numero = entrada.nextInt(); // Entrada de dados
		
		System.out.println("\n");
		
		while(numerosImpares < numero){
			if(contador % 2 == 1){
				System.out.print(contador);
				numerosImpares++;
				if(numerosImpares == numero){
					System.out.print(".");
				}else{
					System.out.print(",");
				}
			}
			contador++; // Aqui os numeros avançam no fim de cada laço, assim o proximo será verificado se é impar ou não
		}
	}
}