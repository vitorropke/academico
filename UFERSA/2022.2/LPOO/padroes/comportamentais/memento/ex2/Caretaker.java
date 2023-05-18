package padroes.comportamentais.memento.ex2;

import java.util.Stack;

public class Caretaker implements Memento {

	private Originator originator;
	private Stack<Memento> history;

	public Caretaker(Originator originator) {
		this.originator = originator;
		history = new Stack<>();
	}

	public void undo() {
		Memento memento = history.pop();
		originator.restore(memento);
	}

}
