package lab03.prototype;

public class Circle extends Shape {
	private int radius;

	public Circle() {
	}

	public Circle(Circle circle) {
		super(circle);
		setRadius(circle.radius);
	}

	@Override
	public String toString() {
		return super.toString() + ", radius=" + radius;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	@Override
	public Circle clone() {
		return new Circle(this);
	}
}
