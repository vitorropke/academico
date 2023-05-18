package lab03.prototype;

public abstract class Shape {
	private int x;
	private int y;
	private String color;

	public Shape() {
	}

	public Shape(Shape shape) {
		setX(shape.x);
		setY(shape.y);
		setColor(shape.color);
	}

	@Override
	public String toString() {
		return "x=" + x + ", y=" + y + ", color=" + color;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public abstract Shape clone();
}
