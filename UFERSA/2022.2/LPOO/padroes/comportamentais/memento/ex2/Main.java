package padroes.comportamentais.memento.ex2;

public class Main {

	public static void main(String[] args) {
		Originator originator = new Originator();
		originator.save();
		
		Caretaker caretaker = new Caretaker(originator);
		caretaker.undo();

	}

}
