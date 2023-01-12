import java.util.Scanner;

class Teste03{
	public static void main(String[] args){
		int operador1, operador2;
		
		Scanner entrada = new Scanner(System.in);
		
		System.out.print("Digite o primeiro operador: ");
		operador1 = entrada.nextInt();
		
		System.out.print("Digite o segundo operador: ");
		operador2 = entrada.nextInt();
		
		Calculadora calculadora = new Calculadora(operador1, operador2);
		
		System.out.println("\n");
		
		System.out.println("Soma = " + calculadora.somarOperandos());
		System.out.println("Multiplicacao = " + calculadora.multiplicarOperandos());
		
		System.out.println("\n");
		
		System.out.print("Digite o primeiro operador: ");
		operador1 = entrada.nextInt();
		
		System.out.print("Digite o segundo operador: ");
		operador2 = entrada.nextInt();
		
		System.out.println("\n");
		
		calculadora.alterarOperandos(operador1, operador2);
		
		System.out.println(calculadora.toString());
	}
}