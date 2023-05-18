package lab02.dip;

public class Main {

	public static void main(String[] args) {
		Book book = new Book();
		DVD dvd = new DVD();
		Shelf shelf = new Shelf();

		shelf.addProduct(book);
		shelf.addProduct(dvd);

		shelf.customizeShelf();

		System.out.println();

		book.seeReviews();
		book.getSample();

		System.out.println();

		dvd.seeReviews();
		dvd.getSample();
	}

}
