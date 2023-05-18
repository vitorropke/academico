package padroes.comportamentais.memento.ex2;

public class ConcreteMemento implements Memento {

	private int state;

	public ConcreteMemento(int state) {
		this.state = state;
	}

	public int getState() {
		return state;
	}

}
