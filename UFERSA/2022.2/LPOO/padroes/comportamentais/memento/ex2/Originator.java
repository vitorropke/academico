package padroes.comportamentais.memento.ex2;

public class Originator {

	private int state;

	public Memento save() {
		return new ConcreteMemento(state);
	}

	public void restore(Memento memento) {
		ConcreteMemento cm = (ConcreteMemento) memento;
		state = cm.getState();
	}

}
