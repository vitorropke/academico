package padroes.comportamentais.memento.ex1;

import java.util.Stack;

import padroes.comportamentais.memento.ex1.Originator.Memento;

public class Caretaker {

	private Originator originator;
	private Stack<Memento> history;

	public void doSomething() {
		Memento memento = originator.save();
		history.push(memento);
	}

	public void undo() {
		Memento memento = history.pop();
		originator.restore(memento);
	}

}
