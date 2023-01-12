package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.util.ArrayList;
import java.util.Calendar;

import br.edu.ufersa.ropke.locadoramaven.model.VO.ClienteVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.DiscoVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestavelVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestimoVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.FuncionarioVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.GerenteVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.LivroVO;

public class MainDAO {
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
		ArrayList<LivroVO> livros = new ArrayList<LivroVO>();

		// titulo, banda, estilo, 'numeroExemplares', 'numeroEmprestimos',
		// 'numeroDiasAlugado', anoLancamento, valorAluguel
		DiscoVO disco1 = new DiscoVO("ola", "ssd", "pagode", 15, 2, 28, 2018, 8.80f);
		ArrayList<DiscoVO> discos = new ArrayList<DiscoVO>();

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

		// Cria objetos do tipo DAO
		LivroDAO livroDAO = new LivroDAO();
		DiscoDAO discoDAO = new DiscoDAO();
		ClienteDAO clienteDAO = new ClienteDAO();
		FuncionarioDAO funcionarioDAO = new FuncionarioDAO();
		GerenteDAO gerenteDAO = new GerenteDAO();
		EmprestimoDAO emprestimoDAO = new EmprestimoDAO();

		// Livros
		System.out.println(
				"-------------------------------------------Livros--------------------------------------------");
		System.out.println("\nLivro\n");
		livroDAO.cadastrar(livro1);
		livroDAO.cadastrar(livro2);
		livroDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera livro 1----------------------------------------");
		livro1.setNumeroPaginas(140);
		livroDAO.alterar(livro1);
		livroDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera livro 2----------------------------------------");
		livro2.setAnoLancamento(1999);
		livroDAO.alterar(livro2);
		livroDAO.pesquisar();

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta livro 1----------------------------------------"
		 * ); livroDAO.deletar(livro1); livroDAO.pesquisar();
		 */

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa titulo----------------------------------------");
		livros = livroDAO.pesquisarTitulo("em");
		int numeroLivros = livros.size();
		for (int i = 0; i < numeroLivros; i++) {
			System.out.println(livros.get(i));
			System.out.println("========================================");
		}

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa genero----------------------------------------");
		livros = livroDAO.pesquisarGenero("acao");
		numeroLivros = livros.size();
		for (int i = 0; i < numeroLivros; i++) {
			System.out.println(livros.get(i));
			System.out.println("========================================");
		}

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa ano-------------------------------------------");
		livros = livroDAO.pesquisarAnoLancamento(2001);
		numeroLivros = livros.size();
		for (int i = 0; i < numeroLivros; i++) {
			System.out.println(livros.get(i));
			System.out.println("========================================");
		}

		// Discos
		System.out.println(
				"-------------------------------------------Discos---------------------------------------------");
		System.out.println("\nDisco\n");
		discoDAO.cadastrar(disco1);
		discoDAO.pesquisar();

		System.out.println();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera disco 1----------------------------------------");
		disco1.setNumeroExemplares(80);
		discoDAO.alterar(disco1);
		discoDAO.pesquisar();

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta disco 1----------------------------------------"
		 * ); discoDAO.deletar(disco1); discoDAO.pesquisar();
		 */

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa titulo----------------------------------------");
		discos = discoDAO.pesquisarTitulo("em");
		int numeroDiscos = discos.size();
		for (int i = 0; i < numeroDiscos; i++) {
			System.out.println(discos.get(i));
			System.out.println("========================================");
		}

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa banda-----------------------------------------");
		discos = discoDAO.pesquisarBanda("ssd");
		numeroDiscos = discos.size();
		for (int i = 0; i < numeroDiscos; i++) {
			System.out.println(discos.get(i));
			System.out.println("========================================");
		}

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa estilo----------------------------------------");
		discos = discoDAO.pesquisarEstilo("pagode");
		numeroDiscos = discos.size();
		for (int i = 0; i < numeroDiscos; i++) {
			System.out.println(discos.get(i));
			System.out.println("========================================");
		}

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa ano-------------------------------------------");
		discos = discoDAO.pesquisarAnoLancamento(2018);
		numeroDiscos = discos.size();
		for (int i = 0; i < numeroDiscos; i++) {
			System.out.println(discos.get(i));
			System.out.println("========================================");
		}

		// Clientes
		System.out.println(
				"-------------------------------------------Clientes--------------------------------------------");
		System.out.println("\nCliente\n");
		clienteDAO.cadastrar(cliente1);
		clienteDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera cliente 1----------------------------------------");
		enderecos.set(0, "Rua longe do local");
		cliente1.setEndereco(enderecos);
		clienteDAO.alterar(cliente1);
		clienteDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Pesquisa nome-------------------------------------------");
		ArrayList<ClienteVO> clientes = clienteDAO.pesquisarNome("ao");
		int numeroClientes = clientes.size();
		for (int i = 0; i < numeroClientes; i++) {
			System.out.println(clientes.get(i));
			System.out.println("==============================================");
		}

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta cliente 1----------------------------------------"
		 * ); clienteDAO.deletar(cliente1); clienteDAO.pesquisar();
		 */

		// Funcionários
		System.out.println(
				"-----------------------------------------Funcionarios------------------------------------------");
		System.out.println("\nFuncionario\n");
		funcionarioDAO.cadastrar(funcionario1);
		funcionarioDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera funcionario 1----------------------------------------");

		funcionario1.setEndereco(enderecos);
		funcionarioDAO.alterar(funcionario1);
		funcionarioDAO.pesquisar();

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta funcionario 1----------------------------------------"
		 * ); funcionarioDAO.deletar(funcionario1); funcionarioDAO.pesquisar();
		 */

		// Gerentes
		System.out.println(
				"-------------------------------------------Gerentes--------------------------------------------");
		System.out.println("\nGerente\n");
		gerenteDAO.cadastrar(gerente1);
		gerenteDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera gerente 1----------------------------------------");
		gerente1.setEndereco(enderecos);
		gerenteDAO.alterar(gerente1);
		gerenteDAO.pesquisar();

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta gerente 1----------------------------------------"
		 * ); gerenteDAO.deletar(gerente1); gerenteDAO.pesquisar();
		 */

		// Empréstimos
		System.out.println(
				"------------------------------------------Emprestimos------------------------------------------");
		System.out.println("\nEmprestimo\n");
		emprestimoDAO.cadastrar(emprestimo1);
		emprestimoDAO.pesquisar();

		System.out.println();
		System.out.println(
				"---------------------------------------Altera emprestimo 1----------------------------------------");
		emprestimo1.setDataEmprestimo(cal);
		emprestimoDAO.alterar(emprestimo1);
		emprestimoDAO.pesquisar();

		/*
		 * System.out.println(); System.out.
		 * println("---------------------------------------Deleta emprestimo 1----------------------------------------"
		 * ); emprestimoDAO.deletar(emprestimo1); emprestimoDAO.pesquisar();
		 */
	}
}
