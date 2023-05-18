package lab03.prototype;

public class Rectangle extends Shape {
	private int width;
	private int height;

	public Rectangle() {
	}

	public Rectangle(Rectangle rectangle) {
		super(rectangle);
		setWidth(rectangle.width);
		setHeight(rectangle.height);
	}

	@Override
	public String toString() {
		return super.toString() + ", width=" + width + ", height=" + height;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	@Override
	public Rectangle clone() {
		return new Rectangle(this);
	}
}
