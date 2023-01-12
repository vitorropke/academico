import java.util.Scanner; // Importa biblioteca para entrada de dados
import java.text.DecimalFormat; // Importa biblioteca para mudança de casas decimais

class Montante{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in); // Cria classe para entrada de dados
		DecimalFormat df = new DecimalFormat("0.##"); //Cria classe para mudança de casas decimais
		double capital, jurosMensal, montanteAnual, montanteMensal, taxa, tempo = 12; // Declaração de variáveis
		
		System.out.print("Digite o valor do capital: ");
		capital = Double.parseDouble(entrada.nextLine()); // Entrada de dados
		System.out.print("Digite o valor dos juros por mes: ");
		jurosMensal = Double.parseDouble(entrada.nextLine()); // Entrada de dados
		
		// Calculos
		taxa = jurosMensal/(capital * tempo); 
		montanteAnual = capital * (1 + taxa * tempo);
		montanteMensal = montanteAnual / 12;
		String montante = df.format(montanteMensal); // Cria uma string com o valor do montante em duas ou uma casa(s) decimal(is)
		
		System.out.println("\nMontante mensal = R$" + montante); //Imprime resultado do montante
	}
}