public class Banco {
	public static void main(String[] args) {
		ContaPoupanca cliente = new ContaPoupanca();
		
		// a) Colocando os dados do cliente
		cliente.setNomeCliente("Fulano de Souza");
		cliente.setNumeroConta(1);
		cliente.setSaldo(2000);
		
		// b) Cliente sacou
		cliente.sacar(150);
		System.out.println("Saque efetuado. Agora tu tens R$" + cliente.saldo);
		
		// c) Cliente depositou
		cliente.depositar(2400);
		
		// Colocando dados da poupança
		cliente.setDiaDeRendimento(12);
		cliente.setTaxaDeRendimento(0.2);
		cliente.calcularNovoSaldo();
		
		// d) Mostrando o saldo com valores do rendimento
		System.out.println("Com rendimento, agora tu tens R$" + cliente.saldo);
		
		// e) Mostrando os dados do cliente
		System.out.println("\nDados do cliente");
		System.out.println("Nome do cliente: " + cliente.getNomeCliente());
		System.out.println("Número da conta do cliente: " + cliente.getNumeroConta());
		System.out.println("Saldo do cliente: " + cliente.getSaldo());
	}
}
