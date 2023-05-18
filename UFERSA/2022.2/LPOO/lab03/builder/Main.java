package lab03.builder;

public class Main {
	public static void main(String[] args) {
		Director director = new Director();
		HouseBuilder house = new House();

		director.buildSimpleHouse(house);
		System.out.println(house);
		
		System.out.println();

		HouseBuilder house0 = new House();
		director.buildComplexHouse(house0);
		System.out.println(house0);
	}
}
