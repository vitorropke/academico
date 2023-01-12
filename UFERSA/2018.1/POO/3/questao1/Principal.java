import java.util.Scanner;

public class Principal {
	static Scanner entrada = new Scanner(System.in);
	
	public static void adicionarBiblioteca(Biblioteca biblioteca) {
		String nome, local;
		
		System.out.print("Digite o nome da biblioteca: ");
		nome = entrada.nextLine();
		biblioteca.setNome(nome);
		
		System.out.print("Digite o local da biblioteca: ");
		local = entrada.nextLine();
		biblioteca.setLocal(local);
	}
	
	public static void adicionarLivro(Livro livro) {
		String titulo, autor;
		int ano, paginas;
		
		System.out.print("Digite o t�tulo do livro: ");
		titulo = entrada.nextLine();
		livro.setTitulo(titulo);
		
		System.out.print("Digite o autor do livro: ");
		autor = entrada.nextLine();
		livro.setNomeDoAutor(autor);
		
		System.out.print("Digite o ano de publica��o do livro: ");
		ano = entrada.nextInt();
		livro.setAnoDePublicacao(ano);
		
		System.out.print("Digite o n�mero de p�ginas do livro: ");
		paginas = entrada.nextInt();
		livro.setNumeroDePaginas(paginas);
	}
	
	public static void mostrarBibliotecas(Biblioteca biblioteca) {
		System.out.println("\nNome da biblioteca: " + biblioteca.getNome());
		System.out.println("Local da biblioteca: " + biblioteca.getLocal());
		System.out.println("N�mero de livros: " + Biblioteca.getLivros());
	}
	
	public static void mostrarLivros(Livro livro) {
		System.out.println("\nTitulo do livro: " + livro.getTitulo());
		System.out.println("Nome do autor: " + livro.getNomeDoAutor());
		System.out.println("Ano de publicacao: " + livro.getAnoDePublicacao());
		System.out.println("Numero de paginas: " + livro.getNumeroDePaginas());
	}
	
	public static void estaDisponivel(Livro livro) {
		if(livro.isStatus()) {
			System.out.println("\nO livro est� dispon�vel!");
		}else {
			System.out.println("\nO livro est� emprestado!");
		}
	}
	
	public static void main(String[] args) {
		
		Biblioteca biblioteca = new Biblioteca();
		Livro livro = new Livro();
		
		adicionarBiblioteca(biblioteca);
		adicionarLivro(livro);
		Biblioteca.setLivros(1);
		
		mostrarBibliotecas(biblioteca);
		mostrarLivros(livro);
		
		livro.setStatus(true);
		estaDisponivel(livro);
		
		livro.setStatus(false);
		estaDisponivel(livro);
		
		entrada.close();
	}
}
