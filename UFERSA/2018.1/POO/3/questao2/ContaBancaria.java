public class ContaBancaria {
	private String nomeCliente;
	private int numeroConta;
	protected float saldo;
	
	public String getNomeCliente() {
		return nomeCliente;
	}
	public void setNomeCliente(String nomeCliente) {
		if(!nomeCliente.isEmpty()) {
			this.nomeCliente = nomeCliente;
		}else {
			this.nomeCliente = "Cliente desconhecido";
		}
	}
	
	public int getNumeroConta() {
		return numeroConta;
	}
	public void setNumeroConta(int numeroConta) {
		if(numeroConta > 0) {
			this.numeroConta = numeroConta;
		}else {
			this.numeroConta = 1;
		}
	}
	
	public float getSaldo() {
		return saldo;
	}
	public void setSaldo(float saldo) {
		if(saldo > 0) {
			this.saldo = saldo;
		}else {
			this.saldo = 0;
		}
	}
	
	public void sacar(float valor) {
		if(saldo >= valor) {
			saldo -= valor;
		}else {
			System.out.println("Saldo insuficiente!");
		}
	}
	
	public void depositar(float valor) {
		if(valor > 0) {
			saldo += valor;
		}else {
		}
	}
}
