import java.util.Calendar;

class Locadora {
	public static void main(String[] args) {
		// atributos escritos entre aspas simples '' significa que são opcionais, segundo os construtores

		// titulo, genero, numeroPaginas, numeroExemplares, 'numeroEmprestimos', 'numeroDiasAlugado'
		// anoLancamento, valorAluguel
		Livro livro1 = new Livro("oi", "romance", 150, 4, 2010, 12);
		Livro livro2 = new Livro("em", "acao", 220, 1, 2018, 26);
		// titulo, nomeBanda, estilo, numeroExemplares, 'numeroEmprestimos', 'numeroDiasAlugado'
		// anoLancamento, valorAluguel
		Disco disco1 = new Disco("ola", "ssd", "pagode", 15, 2, 28, 2018, 8.80f);
		
		// nome, cpf, endereco, 'email', 'telefone'
		Cliente cliente1 = new Cliente("joao", "19315322061", "rua 1",
			"123abc@gmail.com", "(84) 3000-0000");
		
		// login, senha, nome, cpf, endereco, 'email', 'telefone'
		Usuario usuario1 = new Usuario("jose123", "abc123", "jose", "324.281.100-39",
			"rua 2", "abc@gmail.com", "(84) 1234-5678");
		// login, senha, nome, cpf, endereco, 'email', 'telefone'
		Funcionario funcionario1 = new Funcionario("a", "vcdf", "Menino",
			"072.325.480-01", "rua 3", "a@hotmail.com", "(84) 0000-0000");
		// login, senha, nome, cpf, endereco, 'email', 'telefone'
		Gerente gerente1 = new Gerente("gen", "asds", "aaaa", "327.886.720-39",
			"rua 4", "gen@gmail.com", "(84) 99999-9999");
		
		Emprestimo emprestimo1 = new Emprestimo();

		// https://www.tutorialspoint.com/java/util/calendar_setfield4
		// create a calendar
		Calendar cal = Calendar.getInstance();
		Calendar cal1 = Calendar.getInstance();

		// set the year,month, day, hour, minute, second
		// the month starts with 0 and goes to 11
		cal.set(2021, 3, 04, 04, 15, 20);
		cal1.set(2021, 3, 30, 04, 15, 20);

		// print current time
		//System.out.println("Current year is :" + cal.getTime());

		// Livro
		System.out.println("\nLivro\n");
		System.out.println(livro1);

		System.out.println();

		// Disco
		System.out.println("\nDisco\n");
		System.out.println(disco1);

		System.out.println();

		// Cliente
		System.out.println("\nCliente\n");
		System.out.println(cliente1);
		
		System.out.println();

		// Usuário
		System.out.println("\nUsuario\n");
		System.out.println(usuario1);

		System.out.println();

		// Funcionário
		System.out.println("\nFuncionario\n");
		System.out.println(funcionario1);

		System.out.println();

		// Gerente
		System.out.println("\nGerente\n");
		System.out.println(gerente1);

		System.out.println();

		// Empréstimo
		System.out.println("\nEmprestimo\n");
		System.out.print(emprestimo1);
		
		System.out.println();

		System.out.println("\n-----------------------Emprestou 1 livro-------------------------");

		// livro, quantidade, cliente, dataDevolucaoProposta
		emprestimo1.alugarLivro(livro1, 2, cliente1, cal);

		// Empréstimo
		System.out.println("\nEmprestimo\n");
		System.out.print(emprestimo1);
		
		System.out.println();

		// Livro
		System.out.println("\nLivro\n");
		System.out.println(livro1);

		System.out.println();

		// Cliente
		System.out.println("\nCliente\n");
		System.out.println(cliente1);
		
		System.out.println();

		System.out.println("\n-----------------------Emprestou 1 livro e 1 disco--------------------------");

		// livro, quantidade, cliente, dataDevolucaoProposta
		emprestimo1.alugarLivro(livro2, 1, cliente1, cal);
		emprestimo1.alugarDisco(disco1, 1, cliente1, cal);

		// Cliente
		System.out.println("\nCliente\n");
		System.out.println(cliente1);
		
		System.out.println();

		System.out.println("\n--------------------Devolveu 2 livros e 1 disco---------------------------");

		// livro, quantidade, cliente, dataDevolucaoEfetiva
		emprestimo1.devolverLivro(livro1, 5, cliente1, cal1);
		emprestimo1.devolverLivro(livro2, 5, cliente1, cal1);
		emprestimo1.devolverDisco(disco1, 5, cliente1, cal1);
		//System.out.println("Numero de exemplares: " + livro1.getNumeroExemplares());

		// Cliente
		System.out.println("\nCliente\n");
		System.out.println(cliente1);
		
		System.out.println();
	}
}
