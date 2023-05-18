package padroes.comportamentais.memento.ex1;

public class Originator {

	private int state;

	public Memento save() {
		return new Memento(state);
	}

	public void restore(Memento memento) {
		state = memento.getState();
	}

	public final class Memento {

		private final int state;

		private Memento(int state) {
			this.state = state;
		}

		private int getState() {
			return state;
		}

	}

}
