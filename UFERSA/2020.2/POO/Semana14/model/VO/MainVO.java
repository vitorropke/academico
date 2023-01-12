package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.util.ArrayList;
import java.util.Calendar;

public class MainVO {
	public static void main(String[] args) {
		ArrayList<String> enderecos = new ArrayList<String>();
		ArrayList<String> emails = new ArrayList<String>();
		ArrayList<String> telefones = new ArrayList<String>();

		enderecos.add("rua 1");
		enderecos.add(null);
		emails.add("123abc@gmail.com");
		telefones.add("(84) 3000-0000");

		// titulo, genero, numeroPaginas, 'numeroExemplares', 'numeroEmprestimos',
		// 'numeroDiasAlugado', anoLancamento, valorAluguel
		LivroVO livro1 = new LivroVO("oi", "romance", 150, 4, 2010, 12);
		LivroVO livro2 = new LivroVO("em", "acao", 220, 1, 2018, 26);

		// titulo, banda, estilo, 'numeroExemplares', 'numeroEmprestimos',
		// 'numeroDiasAlugado', anoLancamento, valorAluguel
		DiscoVO disco1 = new DiscoVO("ola", "ssd", "pagode", 15, 2, 28, 2018, 8.80f);

		// nome, cpf, endereco, 'email', 'telefone'
		ClienteVO cliente1 = new ClienteVO("joao", "19315322061", enderecos, emails, telefones);

		enderecos.set(0, "rua 3");
		enderecos.set(1, "avenida 20");
		emails.set(0, "a@hotmail.com");
		telefones.set(0, "(84) 0000-0000");
		// login, senha, nome, cpf, endereco, 'email', 'telefone'
		FuncionarioVO funcionario1 = new FuncionarioVO("a", "vcdf", "Menino", "072.325.480-01", enderecos, emails,
				telefones);

		enderecos.set(0, "rua 4");
		emails.set(0, "a@hotmail.com");
		telefones.set(0, "(84) 99999-9999");
		// login, senha, nome, cpf, endereco, 'email', 'telefone'
		GerenteVO gerente1 = new GerenteVO("gen", "asds", "aaaa", "327.886.720-39", enderecos, emails, telefones);

		ArrayList<Calendar> datasDevolucao = new ArrayList<Calendar>();
		ArrayList<EmprestavelVO> emprestaveis = new ArrayList<EmprestavelVO>();
		ArrayList<Integer> quantidadesEmprestavel = new ArrayList<Integer>();

		// https://www.tutorialspoint.com/java/util/calendar_setfield4
		// create a calendar
		Calendar cal = Calendar.getInstance();
		Calendar cal0 = Calendar.getInstance();
		// set the year, month, day, hour, minute, second
		// the month starts with 0 and goes to 11
		cal.set(2021, 5, 29, 04, 15, 20);
		cal0.set(2021, 5, 1, 04, 15, 20);
		datasDevolucao.add(cal);
		datasDevolucao.add(cal0);

		emprestaveis.add(livro1);
		emprestaveis.add(disco1);

		quantidadesEmprestavel.add(2);
		quantidadesEmprestavel.add(1);

		EmprestimoVO emprestimo1 = new EmprestimoVO();
		emprestimo1.setDataDevolucaoEmprestavel(datasDevolucao);
		emprestimo1.setEmprestavel(emprestaveis);
		emprestimo1.setQuantidadeEmprestavel(quantidadesEmprestavel);
		emprestimo1.setCliente(cliente1);

		// Livros
		System.out.println(
				"-------------------------------------------Livros--------------------------------------------");
		System.out.println("\nLivro");
		System.out.println(livro1);
		System.out.println(livro2);

		// Discos
		System.out.println(
				"-------------------------------------------Discos---------------------------------------------");
		System.out.println("\nDisco");
		System.out.println(disco1);

		// Clientes
		System.out.println(
				"-------------------------------------------Clientes--------------------------------------------");
		System.out.println("\nCliente");
		System.out.println(cliente1);

		// Funcionários
		System.out.println(
				"-----------------------------------------Funcionarios------------------------------------------");
		System.out.println("\nFuncionario");
		System.out.println(funcionario1);

		// Gerentes
		System.out.println(
				"-------------------------------------------Gerentes--------------------------------------------");
		System.out.println("\nGerente");
		System.out.println(gerente1);

		// Empréstimos
		System.out.println(
				"------------------------------------------Emprestimos------------------------------------------");
		System.out.println("\nEmprestimo");
		System.out.println(emprestimo1);
	}
}
