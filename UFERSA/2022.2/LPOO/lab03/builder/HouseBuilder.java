package lab03.builder;

public interface HouseBuilder {
	void reset();
	
	void buildFloor(String floorMaterial);

	void buildWalls(int wallsNumber);

	void buildDoor(int doorsNumber);

	void buildWindows(int doorsNumber);

	void buildRoof(String roofMaterial);

	void buildGarage();

	HouseBuilder getResult();
}
