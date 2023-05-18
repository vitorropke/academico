package lab01.srp;

public class Book {
	private String title;
	private String author;

	public Book(String title, String author) {
		setTitle(title);
		setAuthor(author);
	}

	@Override
	public String toString() {
		return "\nTitulo\t:\t" + title + "\nAutor\t:\t" + author + "\n";
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		if ((title != null) && !title.isBlank()) {
			this.title = title.trim();
		}
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		if ((author != null) && !author.isBlank()) {
			this.author = author.trim();
		}
	}
}
