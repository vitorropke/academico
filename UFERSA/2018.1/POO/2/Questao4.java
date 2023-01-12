import java.util.Scanner;

class Teste2{
	public static void main(String[] args){
		String placa1, placa2, modelo1, modelo2;
		int ano1, ano2;
		
		Scanner entrada = new Scanner(System.in);
		
		System.out.print("Digite a placa do carro 1: ");
		placa1 = entrada.next();
		
		System.out.print("Digite o ano do carro 1: ");
		ano1 = entrada.nextInt();
		
		System.out.print("Digite o modelo do carro 1: ");
		modelo1 = entrada.next();
		
		System.out.println("\n");
		
		System.out.print("Digite a placa do carro 2: ");
		placa2 = entrada.next();
		
		System.out.print("Digite o ano do carro 2: ");
		ano2 = entrada.nextInt();
		
		System.out.print("Digite o modelo do carro 2: ");
		modelo2 = entrada.next();
		
		System.out.println("\n");
		
		Carro carro1 = new Carro(placa1, ano1, modelo1);
		Carro carro2 = new Carro(placa2, ano2, modelo2);
		
		carro1.mostrarPlaca();
		carro1.mostrarAno();
		carro1.mostrarModelo();
		
		System.out.println("\n");
		
		carro2.mostrarPlaca();
		carro2.mostrarAno();
		carro2.mostrarModelo();
	}
}