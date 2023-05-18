package lab01.srp;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		Book book0 = new Book("Titulo 0", "Autor 0");
		Book book1 = new Book("Titulo 1", "Autor 1");
		Book book2 = new Book("Titulo 2", "Autor 2");

		ArrayList<Book> books = new ArrayList<Book>();
		books.add(book0);
		books.add(book1);
		books.add(book2);

		InventoryView inventory = new InventoryView(books);
		inventory.searchBook();
	}

}
