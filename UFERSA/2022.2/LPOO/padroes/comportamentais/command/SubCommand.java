package padroes.comportamentais.command;

public class SubCommand implements Command {

	private Receiver receiver;
	private double number1;
	private double number2;

	public SubCommand(Receiver receiver, double number1, double number2) {
		this.receiver = receiver;
		this.number1 = number1;
		this.number2 = number2;
	}

	public Receiver getReceiver() {
		return receiver;
	}

	public void setReceiver(Receiver receiver) {
		this.receiver = receiver;
	}

	public double getNumber1() {
		return number1;
	}

	public void setNumber1(double number1) {
		this.number1 = number1;
	}

	public double getNumber2() {
		return number2;
	}

	public void setNumber2(double number2) {
		this.number2 = number2;
	}

	@Override
	public void execute() {
		receiver.subtracao(number1, number2);
	}

}
