package padroes.comportamentais.command;

public class Receiver {

	public void adicao(double number1, double number2) {
		System.out.println(number1 + " + " + number2 + " = " + (number1 + number2));
	}

	public void subtracao(double number1, double number2) {
		System.out.println(number1 + " - " + number2 + " = " + (number1 - number2));
	}

	public void multiplicacao(double number1, double number2) {
		System.out.println(number1 + " * " + number2 + " = " + (number1 * number2));
	}

	public void divisao(double number1, double number2) {
		System.out.println(number1 + " / " + number2 + " = " + (number1 / number2));
	}

}
