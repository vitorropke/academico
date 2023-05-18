package lab03.builder;

public class House implements HouseBuilder {
	private House house;
	private String floorMaterial;
	private int wallsNumber;
	private int doorsNumber;
	private int windowsNumber;
	private String roofMaterial;
	private boolean hasGarage;

	// Getters e setters============================================================
	public House getHouse() {
		return house;
	}

	public void setHouse(House house) {
		this.house = house;
	}

	public String getFloorMaterial() {
		return floorMaterial;
	}

	public void setFloorMaterial(String floorMaterial) {
		this.floorMaterial = floorMaterial;
	}

	public int getWallsNumber() {
		return wallsNumber;
	}

	public void setWallsNumber(int wallsNumber) {
		this.wallsNumber = wallsNumber;
	}

	public int getDoorsNumber() {
		return doorsNumber;
	}

	public void setDoorsNumber(int doorsNumber) {
		this.doorsNumber = doorsNumber;
	}

	public int getWindowsNumber() {
		return windowsNumber;
	}

	public void setWindowsNumber(int windowsNumber) {
		this.windowsNumber = windowsNumber;
	}

	public String getRoofMaterial() {
		return roofMaterial;
	}

	public void setRoofMaterial(String roofMaterial) {
		this.roofMaterial = roofMaterial;
	}

	public boolean isHasGarage() {
		return hasGarage;
	}

	public void setHasGarage(boolean hasGarage) {
		this.hasGarage = hasGarage;
	}

	// ToString=====================================================================
	@Override
	public String toString() {
		return "Material do piso\t=\t" + floorMaterial + "\nNumero de paredes\t=\t" + wallsNumber
				+ "\nNumero de portas\t=\t" + doorsNumber + "\nNumero de janelas\t=\t" + windowsNumber
				+ "\nMaterial do telhado\t=\t" + roofMaterial + "\nTem garagem\t\t=\t" + (hasGarage ? "Sim" : "Nao");
	}

	// Métodos======================================================================
	@Override
	public void reset() {
		house = new House();
	}

	@Override
	public void buildFloor(String floorMaterial) {
		this.floorMaterial = floorMaterial;
	}

	@Override
	public void buildWalls(int wallsNumber) {
		this.wallsNumber = wallsNumber;
	}

	@Override
	public void buildDoor(int doorsNumber) {
		this.doorsNumber = doorsNumber;
	}

	@Override
	public void buildWindows(int windowsNumber) {
		this.windowsNumber = windowsNumber;
	}

	@Override
	public void buildRoof(String roofMaterial) {
		this.roofMaterial = roofMaterial;
	}

	@Override
	public void buildGarage() {
		hasGarage = true;
	}

	@Override
	public HouseBuilder getResult() {
		return house;
	}
}
