package lab01.srp;

import java.util.ArrayList;

public class InventoryView {
	private ArrayList<Book> books = new ArrayList<Book>();

	public InventoryView(ArrayList<Book> books) {
		setBooks(books);
	}

	public ArrayList<Book> getBooks() {
		return books;
	}

	public void setBooks(ArrayList<Book> books) {
		for (Book book : books) {
			if ((book == null) || (book.getTitle() == null) || (book.getAuthor() == null)) {
				System.out.println("Valor invalido, encontrado");
				return;
			}
		}
		this.books = books;
	}

	public void searchBook() {
		System.out.println(books);
	}
}
