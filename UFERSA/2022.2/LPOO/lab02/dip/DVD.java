package lab02.dip;

public class DVD implements Product {
	DVD() {
	}

	@Override
	public String toString() {
		return "Isso is um DVD, hashCode()=" + hashCode() + '\n';
	}

	@Override
	public void seeReviews() {
		System.out.println("10\n9\n10");
	}

	@Override
	public void getSample() {
		System.out.println("Isso é uma amostra também.");
	}

}
