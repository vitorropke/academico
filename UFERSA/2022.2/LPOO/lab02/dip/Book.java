package lab02.dip;

public class Book implements Product {
	Book() {
	}

	@Override
	public String toString() {
		return "Isso is um livro, hashCode()=" + hashCode() + '\n';
	}

	@Override
	public void seeReviews() {
		System.out.println("10\n10\n10\nTudo 10");
	}

	@Override
	public void getSample() {
		System.out.println("Isso é uma amostra. Confia!");
	}

}
