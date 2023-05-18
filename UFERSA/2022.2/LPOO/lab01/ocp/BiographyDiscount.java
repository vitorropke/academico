package lab01.ocp;

public class BiographyDiscount implements BookDiscount {
	public float baseValue = 25.02f;

	@Override
	public String getBookDiscount() {
		float discount = 10f;

		baseValue = baseValue - discount;
		
		String stringBaseValue = String.format("%.2f", baseValue);
		String stringDiscount = String.format("%.2f", discount);

		return "Desconto de R$" + stringDiscount + ", resultando em R$" + stringBaseValue + " no valor final do produto";
	}

}
