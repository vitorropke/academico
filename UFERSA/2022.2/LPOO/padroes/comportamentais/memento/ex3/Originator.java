package padroes.comportamentais.memento.ex3;

public class Originator {

	private double num1;
	private double num2;

	public Originator(double num1, double num2) {
		this.num1 = num1;
		this.num2 = num2;
	}

	public double getNum1() {
		return num1;
	}

	public void setNum1(double num1) {
		this.num1 = num1;
	}

	public double getNum2() {
		return num2;
	}

	public void setNum2(double num2) {
		this.num2 = num2;
	}

	public double add() {
		return num1 + num2;
	}

	public double sub() {
		return num1 - num2;
	}

	public double mul() {
		return num1 * num2;
	}

	public double div() {
		return num1 / num2;
	}

	public Memento save() {
		return new Memento(num1, num2);
	}

	public void restore(Memento memento) {
		num1 = memento.getNum1();
		num2 = memento.getNum2();
	}

	public final class Memento {

		private final double num1;
		private final double num2;

		private Memento(double num1, double num2) {
			this.num1 = num1;
			this.num2 = num2;
		}

		private double getNum1() {
			return num1;
		}

		private double getNum2() {
			return num2;
		}

	}

}
