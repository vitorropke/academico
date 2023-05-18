package lab03.builder;

public class Director {
	public void buildSimpleHouse(HouseBuilder houseBuilder) {
		houseBuilder.reset();
		houseBuilder.buildFloor("Terra batida");
		houseBuilder.buildWalls(4);
		houseBuilder.buildDoor(2);
		houseBuilder.buildWindows(2);
		houseBuilder.buildRoof("Telhado de palha");
	}
	
	public void buildComplexHouse(HouseBuilder houseBuilder) {
		houseBuilder.reset();
		houseBuilder.buildFloor("Ceramica");
		houseBuilder.buildWalls(10);
		houseBuilder.buildDoor(23);
		houseBuilder.buildWindows(30);
		houseBuilder.buildRoof("Telhado de ceramica");
		houseBuilder.buildGarage();
	}
}
