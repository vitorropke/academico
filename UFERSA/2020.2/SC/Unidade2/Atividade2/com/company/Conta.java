package com.company;

import java.util.Calendar;

public class Conta extends Banco {
	private String login;
	private String senha;
	private Pessoa titular;
	private int numero;
	private double saldo;
	private int chaves[];
	private Calendar dataCriacaoConta;
	private int diasCorridos = 0;

	public int[] getChaves() {
		return chaves;
	}

	public void setChaves(int[] chaves) {
		this.chaves = chaves;
	}

	public Conta(String login, String senha, Pessoa titular, int numero) {
		setLogin(login);
		setSenha(senha);
		this.saldo = 0;
		this.titular = titular;
		this.numero = numero;
		this.chaves = RSA.gerarChaves();
		this.dataCriacaoConta = Calendar.getInstance();
	}

	public void autenticar(int[] senha) {
		String senhadecrip = RSA.decriptar(senha, chaves[0], chaves[2]);

		if (senhadecrip.equals(getSenha())) {
			System.out.println("Acesso garantido!\n");
		} else {
			System.out.println("Acesso negado!");
			System.exit(0);
		}
	}

	public void solicitarSaque(String valor) {
		int crip[] = RSA.encriptar(valor, chaves[0], chaves[1]);
		try {
			// double aux = Double.parseDouble(valor);
		} catch (NumberFormatException e) {
			System.out.println("Numero com formato errado!");
		}
		System.out.println(
				"******************\n" + "Solicitação de Saque enviada\n" + "Valor: " + crip + "\n******************");
		this.sacar(crip);
	}

	public void sacar(int[] valor) {
		String decrip = RSA.decriptar(valor, chaves[0], chaves[2]);
		System.out.println("******************\n" + "Solicitação de Deposito recebida\n" + "Valor: R$" + decrip
				+ "\n******************");
		double valord = Double.parseDouble(decrip);
		if (this.saldo >= valord) {
			this.saldo -= valord;
			System.out.println("Valor sacado: " + valord);
			System.out.println("Novo saldo: " + this.saldo);
		} else {
			System.out.println("Saldo insuficiente");
		}
	}

	public void solicitarDeposito(String valor) {
		int crip[] = RSA.encriptar(valor, chaves[0], chaves[1]);
		try {
			// double aux = Double.parseDouble(valor);
		} catch (NumberFormatException e) {
			System.out.println("Numero com formato errado!");
		}
		System.out.println("******************\n" + "Solicitação de Deposita enviada\n" + "Valor: " + crip
				+ "\n******************");
		this.depositar(crip);
	}

	private void depositar(int[] valor) {

		String decrip = RSA.decriptar(valor, chaves[0], chaves[2]);
		System.out.println("******************\n" + "Solicitação de Deposito recebida\n" + "Valor: R$" + decrip
				+ "\n******************");
		double valord = Double.parseDouble(decrip);
		this.saldo += valord;
		System.out.print("Depositado:  R$");
		System.out.printf("%.2f", valord);
		System.out.println();
		System.out.print("Novo: saldo: R$");
		System.out.printf("%.2f", this.saldo);
		System.out.println();
	}

	public void solicitarTransfer(Conta conta, String valor) {
		int crip[] = RSA.encriptar(valor, chaves[0], chaves[1]);
		try {
			// double aux = Double.parseDouble(valor);
		} catch (NumberFormatException e) {
			System.out.println("Numero com formato errado!");
		}
		System.out.println("******************\n" + "Solicitação de transferencia enviada\n" + "Valor: " + crip
				+ "\n******************");
		this.transferir(conta, crip);
	}

	public void transferir(Conta conta, int[] valor) {
		String valorA = RSA.decriptar(valor, chaves[0], chaves[2]);
		double valord = Double.parseDouble(valorA);
		if (this.saldo >= valord) {
			conta.setSaldo(valord);
			this.saldo -= valord;
			System.out.print("Transferido: R$");
			System.out.printf("%.2f", valord);
			System.out.print(" para : " + conta.titular.getNome());
			System.out.println();
		} else {
			System.out.println("Saldo insuficiente");
		}
	}

	public void simularRendimento() {
		System.out.println();
		System.out.print("Rendimento em 3 meses:  R$");
		System.out.printf("%.2f", this.saldo * 0.05 * 3);
		System.out.println();
		System.out.print("Rendimento em 6 meses:  R$");
		System.out.printf("%.2f", this.saldo * 0.05 * 6);
		System.out.println();
		System.out.print("Rendimento em 12 meses: R$");
		System.out.printf("%.2f", this.saldo * 0.05 * 12);
		System.out.println();
	}

	public void adicionalPoupanca() {
		// http://burnignorance.com/java-web-development-tips/calculating-difference-between-two-dates-using-java/
		// Create one calendar instances
		Calendar dataAtual = Calendar.getInstance();

		// Get the difference between two dates in milliseconds
		long diffInMillisec = dataAtual.getTimeInMillis() - dataCriacaoConta.getTimeInMillis();

		// Get difference between two dates in days
		diasCorridos += diffInMillisec / (24 * 60 * 60 * 1000);

		if (diasCorridos > 30) {
			for (int i = diasCorridos; i > 0; i -= 30) {
				saldo += saldo * 0.005;
				diasCorridos -= 30;
			}
		}

		System.out.print("\nNovo saldo: R$");
		System.out.printf("%.2f", this.saldo);
		System.out.println();
	}

	public void adicionalRendaFixa() {
		// http://burnignorance.com/java-web-development-tips/calculating-difference-between-two-dates-using-java/
		// Create one calendar instances
		Calendar dataAtual = Calendar.getInstance();

		// Get the difference between two dates in milliseconds
		long diffInMillisec = dataAtual.getTimeInMillis() - dataCriacaoConta.getTimeInMillis();

		// Get difference between two dates in days
		diasCorridos += diffInMillisec / (24 * 60 * 60 * 1000);

		if (diasCorridos > 30) {
			for (int i = diasCorridos; i > 0; i -= 30) {
				saldo += saldo * 0.015;
				diasCorridos -= 30;
			}
		}

		System.out.print("\nNovo saldo: R$");
		System.out.printf("%.2f", this.saldo);
		System.out.println();
	}

	public String getLogin() {
		return login;
	}

	public void setLogin(String login) {
		if ((login != null) && (login != "")) {
			this.login = login;
		} else {
			System.out.println("Login nao pode ser vazio!");
		}
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		if ((senha != null) && (senha != "")) {
			this.senha = senha;
		} else {
			System.out.println("Senha nao pode ser vazia!");
		}
	}

	public Pessoa getTitular() {
		return titular;
	}

	public void setTitular(Pessoa titular) {
		this.titular = titular;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	@Override
	public String toString() {
		return "Conta{" + "titular=" + titular + ", numero=" + numero + ", saldo=" + saldo + '}';
	}
}
