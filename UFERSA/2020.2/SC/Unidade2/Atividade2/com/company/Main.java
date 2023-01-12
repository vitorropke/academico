package com.company;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner entradaUsuario = new Scanner(System.in)) {
			String login;
			String senha;

			Banco b = new Banco().setTipoBanco("Banco do Brasil");

			Pessoa aleff = new Pessoa(23, "Aleff", "01766325580", "Rua Boston, 163", "a@a.com");
			Pessoa p = new Pessoa(21, "asas", "123", "Maria Salem Duarte", "tt@hotmail");
			Pessoa p2 = new Pessoa(25, "asd", "456", "Maria Salem asd", "42@sds");

			b.criarConta("a", "a", aleff);
			b.criarConta("abc", "abc", p);
			b.criarConta("def", "def", p2);

			// Autentica o cliente
			System.out.println("Login: ");
			login = entradaUsuario.nextLine();

			Conta conta = b.buscarConta(login).get();
			int chavesaux[] = conta.getChaves();

			System.out.println("Senha: ");
			senha = entradaUsuario.nextLine();
			int senhaencrip[];
			senhaencrip = RSA.encriptar(senha, chavesaux[0], chavesaux[1]);

			conta.autenticar(senhaencrip);

			int comando;
			String saqueSolicitado, depositoSolicitado, valorTransferencia, loginContaDestino;
			Conta contaDestino;
			boolean sair = false;

			while (!sair) {
				System.out.println();
				System.out.println("1: Sacar");
				System.out.println("2: Depositar");
				System.out.println("3: Transferir");
				System.out.println("4: Consultar saldo");
				System.out.println("5: Simular rendimento");
				System.out.println("6: Aplicar rendimento - Poupança");
				System.out.println("7: Aplicar rendimento - Renda fixa");
				System.out.println("Qualquer outro número: Sair");
				System.out.print("Digite o comando a ser executado: ");
				comando = entradaUsuario.nextInt();
				entradaUsuario.nextLine();

				switch (comando) {
				case 1:
					System.out.print("\nDigite o valor do saque: ");
					saqueSolicitado = entradaUsuario.nextLine();

					conta.solicitarSaque(saqueSolicitado);
					break;
				case 2:
					System.out.print("\nDigite o valor do deposito: ");
					depositoSolicitado = entradaUsuario.nextLine();

					conta.solicitarDeposito(depositoSolicitado);
					break;
				case 3:
					System.out.print("\nDigite a conta destino usando o login PIX: ");
					loginContaDestino = entradaUsuario.nextLine();

					contaDestino = b.buscarConta(loginContaDestino).get();

					System.out.print("\nDigite o valor de transferencia: ");
					valorTransferencia = entradaUsuario.nextLine();

					conta.solicitarTransfer(contaDestino, valorTransferencia);
					break;
				case 4:
					System.out.print("\nSeu saldo é " + conta.getSaldo());
					break;
				case 5:
					conta.simularRendimento();
					break;
				case 6:
					conta.adicionalPoupanca();
					break;
				case 7:
					conta.adicionalRendaFixa();
					break;
				default:
					sair = true;
					break;
				}
			}
		}
	}
}
