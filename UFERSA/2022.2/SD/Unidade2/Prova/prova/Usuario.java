package prova;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import prova.categorias.*;

public class Usuario {

	private static List<Carro> carrosComprados = new ArrayList<>();
	private static Scanner teclado = new Scanner(System.in);
	private static Loja stub;

	private String nome;
	private String senha;

	public Usuario(String nome, String senha) {
		setNome(nome);
		setSenha(senha);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	private static void config() {
		System.setProperty("java.security.policy", "java.policy");
		/*
		 * if (System.getSecurityManager() == null) { System.setSecurityManager(new
		 * SecurityManager()); }
		 */
	}

	public static void main(String[] args) {
		config();

		System.out.print("Informe o nome/endereco do RMIRegistry: ");
		String host = inserirString();

		Usuario usuario = null;
		do {
			System.out.print("Informe seu login: ");
			String login = inserirString();
			System.out.print("Informe sua senha: ");
			String senha = inserirString();
			usuario = Servidor.autenticarUsuario(login, senha);

			if (usuario == null) {
				System.err.println("Usuario nao cadastrado!\n");
			}
		} while (usuario == null);

		try {
			Registry registro = LocateRegistry.getRegistry(host, Servidor.porta);
			stub = (Loja) registro.lookup("Loja");

			boolean conexao = true;
			do {
				System.out.println("0 - Sair da loja");
				System.out.println("1 - Listar carros");
				System.out.println("2 - Pesquisar carro");
				System.out.println("3 - Exibir a quantidade de carros");
				System.out.println("4 - Comprar um carro");
				if (usuario instanceof Funcionario) {
					System.out.println("5 - Adicionar um carro");
					System.out.println("6 - Alterar os dados dum carro");
					System.out.println("7 - Apagar um carro");
				}
				System.out.print("Informe o que voce quer fazer: ");
				int operacao = teclado.nextInt();
				teclado.nextLine();
				System.out.println();

				switch (operacao) {
				case 0:
					conexao = false;

					break;
				case 1:
					System.out.println("1 - Listar todos carros");
					System.out.println("2 - Listar os carros de uma categoria");
					System.out.print("Informe a listagem: ");
					int listagemEscolhida = teclado.nextInt();
					teclado.nextLine();
					System.out.println();

					operarListagem(listagemEscolhida);

					break;
				case 2:
					System.out.print("Digite o nome ou Renavam do carro: ");
					String nomeOuRenavamDoCarro = inserirString();

					Carro carro = stub.pesquisarCarro(nomeOuRenavamDoCarro);
					if (carro == null) {
						System.err.println("Nao tem carro com esse nome ou Renavam na loja!\n");
					} else {
						System.out.println(carro);
					}

					break;
				case 3:
					System.out.println("A loja possui " + stub.exibirQuantidadeCarros() + " carros\n");

					break;
				case 4:
					carro = stub.comprarCarro(selecionarCarro());
					if (carro == null) {
						System.err.println("Nao tem esse carro na loja!\n");
					} else {
						carrosComprados.add(carro);

						System.out.println("Seu(s) carro(s)\n" + carrosComprados + "\n");
					}

					break;
				default:
					if (usuario instanceof Funcionario) {
						switch (operacao) {
						case 5:
							System.out.print("Digite o nome do carro: ");
							String nomeDoCarro = inserirString();

							System.out.print("Digite o Renavam do carro: ");
							String renavamDoCarro = inserirString();

							Categoria categoriaDoCarro = selecionarCategoria();

							System.out.print("Digite o ano de fabricacao do carro: ");
							int anoDeFabricacaoDoCarro = teclado.nextInt();
							teclado.nextLine();
							System.out.println();

							System.out.print("Digite a quantidade disponivel do carro: ");
							int quantidadeDisponivelDoCarro = inserirQuantidade();

							System.out.print("Digite o preco do carro: ");
							float precoDoCarro = teclado.nextInt();
							teclado.nextLine();
							System.out.println();

							System.out
									.println(stub
											.adicionarCarro(new Carro(nomeDoCarro, renavamDoCarro, categoriaDoCarro,
													anoDeFabricacaoDoCarro, quantidadeDisponivelDoCarro, precoDoCarro))
											+ "\n");

							break;
						case 6:
							carro = selecionarCarro();
							if (carro == null) {
								System.err.println("Nao tem esse carro na loja!\n");
							} else {
								Carro carroModificado = modificarDadoCarro(carro);

								if (carroModificado != null) {
									System.out.println(stub.alterarCarro(carro, carroModificado) + "\n");
								}
							}

							break;
						case 7:
							System.out.print("Digite o nome do carro a ser apagado: ");
							nomeDoCarro = inserirString();

							List<Carro> carrosDaLoja = stub.apagarCarro(nomeDoCarro);
							if (carrosDaLoja == null) {
								System.err.println("Nao tem esse carro na loja!\n");
							} else {
								System.out.println(carrosDaLoja + "\n");
							}

							break;
						default:
							System.err.println("Operacao desconhecida. Por favor, informe uma operacao valida!\n");

							break;
						}
					} else {
						System.err.println("Operacao desconhecida. Por favor, informe uma operacao valida!\n");
					}

					break;
				}
			} while (conexao);

			System.err.println("Tchau!\n");
		} catch (Exception e) {
			System.err.println("Usuario: " + e.toString());
			e.printStackTrace();
		}
	}

	private static String inserirString() {
		do {
			String string = teclado.nextLine();
			System.out.println();

			if (string.isBlank()) {
				System.err.print("Por favor, digite alguma coisa: ");
			} else {
				return string;
			}
		} while (true);
	}

	private static int inserirQuantidade() {
		do {
			int quantidade = teclado.nextInt();
			teclado.nextLine();
			System.out.println();

			if (quantidade <= 0) {
				System.err.print("Por favor, digite uma quantidade maior que 0: ");
			} else {
				return quantidade;
			}
		} while (true);
	}

	private static void operarListagem(int operacaoDeListagem) throws RemoteException {
		switch (operacaoDeListagem) {
		case 1:
			System.out.println(stub.listarCarros() + "\n");

			break;
		case 2:
			System.out.println(stub.listarCarrosPorCategoria(selecionarCategoria()) + "\n");

			break;
		default:
			System.err.println("Listagem invalida!\n");

			break;
		}
	}

	private static Categoria selecionarCategoria() {
		do {
			System.out.println("1 - Economico");
			System.out.println("2 - Intermediario");
			System.out.println("3 - Executivo");
			System.out.print("Informe a categoria: ");
			int categoriaEscolhida = teclado.nextInt();
			teclado.nextLine();
			System.out.println();

			switch (categoriaEscolhida) {
			case 1:
				return new Economico();
			case 2:
				return new Intermediario();
			case 3:
				return new Executivo();
			default:
				System.err.println("Categoria indefinida! Por favor, insira uma categoria valida!\n");

				break;
			}
		} while (true);
	}

	private static Carro selecionarCarro() throws RemoteException {
		List<Carro> carrosDaLoja = stub.listarCarros();
		for (int i = 0; i < carrosDaLoja.size(); i++) {
			System.out.print(i + " - " + carrosDaLoja.get(i));
		}

		do {
			System.out.print("Selecione o carro: ");
			int indiceCarroEscolhido = teclado.nextInt();
			teclado.nextLine();
			System.out.println();

			if ((indiceCarroEscolhido >= 0) && (indiceCarroEscolhido < carrosDaLoja.size())) {
				return carrosDaLoja.get(indiceCarroEscolhido);
			} else {
				System.err.println("Nao tem esse carro na loja! Por favor, selecione um carro que existe na loja!\n");
			}
		} while (true);
	}

	private static Carro modificarDadoCarro(Carro carro) throws RemoteException {
		System.out.println("1 - Nome");
		System.out.println("2 - Renavam");
		System.out.println("3 - Categoria");
		System.out.println("4 - Ano de fabricacao");
		System.out.println("5 - Quantidade disponivel");
		System.out.println("6 - Preco do carro");
		System.out.print("Informe o dado a ser modificado no carro: ");
		int dadoEscolhido = teclado.nextInt();
		teclado.nextLine();
		System.out.println();

		switch (dadoEscolhido) {
		case 1:
			System.out.print("Digite o novo nome do carro: ");

			return new Carro(inserirString(), carro.getRenavan(), carro.getCategoria(), carro.getAnoFabricacao(),
					carro.getQuantidadeDisponivel(), carro.getPreco());

		case 2:
			System.out.print("Digite o novo Renavam do carro: ");

			return new Carro(carro.getNome(), inserirString(), carro.getCategoria(), carro.getAnoFabricacao(),
					carro.getQuantidadeDisponivel(), carro.getPreco());
		case 3:
			System.out.print("Digite a nova categoria do carro: ");

			return new Carro(carro.getNome(), carro.getRenavan(), selecionarCategoria(), carro.getAnoFabricacao(),
					carro.getQuantidadeDisponivel(), carro.getPreco());
		case 4:
			System.out.print("Digite o novo ano de fabricacao do carro: ");
			int novoAnoFabricacao = teclado.nextInt();
			teclado.nextLine();
			System.out.println();

			return new Carro(carro.getNome(), carro.getRenavan(), carro.getCategoria(), novoAnoFabricacao,
					carro.getQuantidadeDisponivel(), carro.getPreco());
		case 5:
			System.out.print("Digite a nova quantidade disponivel do carro: ");

			return new Carro(carro.getNome(), carro.getRenavan(), carro.getCategoria(), carro.getAnoFabricacao(),
					inserirQuantidade(), carro.getPreco());
		case 6:
			System.out.print("Digite o novo preco do carro: ");
			int novoPreco = teclado.nextInt();
			teclado.nextLine();
			System.out.println();

			return new Carro(carro.getNome(), carro.getRenavan(), carro.getCategoria(), carro.getAnoFabricacao(),
					carro.getQuantidadeDisponivel(), novoPreco);
		default:
			System.err.println("Nada foi modificado!\n");

			break;
		}

		return null;
	}

}
