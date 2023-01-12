import java.util.Scanner;

class Teste{
	public static void main(String[] args){
		String nome1, nome2;
		int idade1, idade2;
		float altura1, altura2;
		
		Scanner entrada = new Scanner(System.in);
		
		System.out.print("Digite o nome do aluno 1: ");
		nome1 = entrada.next();
		
		System.out.print("Digite a idade do aluno 1: ");
		idade1 = entrada.nextInt();
		
		System.out.print("Digite a altura do aluno 1 em metros: ");
		altura1 = entrada.nextFloat();
		
		System.out.println("\n");
		
		System.out.print("Digite o nome do aluno 2: ");
		nome2 = entrada.next();
		
		System.out.print("Digite a idade do aluno 2: ");
		idade2 = entrada.nextInt();
		
		System.out.print("Digite a altura do aluno 2 em metros: ");
		altura2 = entrada.nextFloat();
		
		System.out.println("\n");
		
		Aluno aluno1 = new Aluno(nome1, idade1, altura1);
		Aluno aluno2 = new Aluno(nome2, idade2, altura2);
		
		aluno1.mostrarNome();
		aluno1.mostrarIdade();
		aluno1.mostrarAltura();
		
		System.out.println("\n");
		
		aluno2.mostrarNome();
		aluno2.mostrarIdade();
		aluno2.mostrarAltura();
	}
}