package lab03.prototype;

public class Main {
	public static void main(String[] args) {
		Circle circle = new Circle();
		circle.setRadius(5);
		circle.setX(15);
		circle.setY(90);
		circle.setColor("Green");

		Circle copiedCircle = circle.clone();

		System.out.println("Circulo original: " + circle);
		System.out.println("Circulo copiado:  " + copiedCircle);

		System.out.println("\nModificacao do circulo copiado\n");
		copiedCircle.setColor("White");

		System.out.println("Circulo original: " + circle);
		System.out.println("Circulo copiado:  " + copiedCircle);

		System.out.println();

		Rectangle rectangle = new Rectangle();
		rectangle.setWidth(50);
		rectangle.setHeight(94);
		rectangle.setX(7);
		rectangle.setY(88);
		rectangle.setColor("Red");

		Rectangle copiedRectangle = rectangle.clone();

		System.out.println("Retangulo original: " + rectangle);
		System.out.println("Retangulo copiado:  " + copiedRectangle);

		System.out.println("\nModificacao do retangulo copiado\n");
		copiedRectangle.setColor("Orange");
		copiedRectangle.setX(2);

		System.out.println("Retangulo original: " + rectangle);
		System.out.println("Retangulo copiado:  " + copiedRectangle);
	}
}
