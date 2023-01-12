class Carro{
	String placa, modelo;
	int ano;
	
	public Carro(){
		
	}
	
	public Carro(String placa, int ano, String modelo){
		this.placa = placa;
		this.modelo = modelo;
		
		if(ano > 1807 && ano < 2019){
			this.ano = ano;
		}
	}
	
	public Carro(String placa, String modelo){
		this.placa = placa;
		this.modelo = modelo;
	}
	
	public void mostrarPlaca(){
		System.out.println("Placa: " + placa);
	}
	
	public void mostrarAno(){
		System.out.println("Ano: " + ano);
	}
	
	public void mostrarModelo(){
		System.out.println("Modelo: " + modelo);
	}
	
	public String toString(){
		String saida;
		
		saida = "Placa: " + placa +
				"\nAno: " + ano +
				"\nModelo: " + modelo;
		
		return saida;
	}
}