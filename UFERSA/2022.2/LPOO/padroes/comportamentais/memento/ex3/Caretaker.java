package padroes.comportamentais.memento.ex3;

import java.util.Stack;

import padroes.comportamentais.memento.ex3.Originator.Memento;

public class Caretaker {

	private Originator originator;
	private Stack<Memento> history;

	public Caretaker(Originator originator) {
		this.originator = originator;
		history = new Stack<>();
	}

	public void save() {
		Memento memento = originator.save();
		history.push(memento);
	}

	public void undo() {
		Memento memento = history.pop();
		originator.restore(memento);
	}

}
