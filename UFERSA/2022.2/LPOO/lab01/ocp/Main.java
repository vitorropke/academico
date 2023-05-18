package lab01.ocp;

public class Main {

	public static void main(String[] args) {
		CookBookDiscount cookBookDiscount = new CookBookDiscount();
		BiographyDiscount biographyDiscount = new BiographyDiscount();
		
		System.out.println("Valor inicial do livro de receitas: R$" + cookBookDiscount.baseValue);
		System.out.println("Valor inicial da biografia: R$" + biographyDiscount.baseValue + '\n');
		
		DiscountManager discountManager = new DiscountManager();
		discountManager.processBookDiscount(cookBookDiscount);
		discountManager.processBookDiscount(biographyDiscount);
		
		System.out.println("\nValor final do livro de receitas: R$" + cookBookDiscount.baseValue);
		System.out.println("Valor final da biografia: R$" + biographyDiscount.baseValue);
	}

}
