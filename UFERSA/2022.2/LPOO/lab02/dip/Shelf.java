package lab02.dip;

import java.util.ArrayList;

public class Shelf {
	private ArrayList<Product> products = new ArrayList<Product>();

	Shelf() {
	}

	public ArrayList<Product> getProducts() {
		return products;
	}

	public void setProducts(ArrayList<Product> products) {
		for (Product product : products) {
			if ((product == null)) {
				System.out.println("Produto invalido, encontrado");
				return;
			}
		}
		this.products = products;
	}

	void addProduct(Product product) {
		if ((product == null)) {
			System.out.println("Produto invalido");
			return;
		} else {
			products.add(product);
		}
	}

	void customizeShelf() {
		System.out.println(products);
	}
}
