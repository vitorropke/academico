package padroes.comportamentais.command;

public class Invoker {

	private Command command;

	public Invoker() {

	}

	public Invoker(Command command) {
		setCommand(command);
	}

	public Command getCommand() {
		return command;
	}

	public void setCommand(Command command) {
		this.command = command;
	}

	public void executeCommand() {
		command.execute();
	}

}
