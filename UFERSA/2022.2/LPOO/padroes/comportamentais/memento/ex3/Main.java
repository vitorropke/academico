package padroes.comportamentais.memento.ex3;

public class Main {

	public static void main(String[] args) {
		Originator originator = new Originator(10, 50);
		System.out.println(originator.add());

		Caretaker caretaker = new Caretaker(originator);
		caretaker.save();

		originator.setNum1(55);
		originator.setNum2(120);

		System.out.println(originator.add());

		caretaker.undo();

		System.out.println(originator.add());
	}

}
