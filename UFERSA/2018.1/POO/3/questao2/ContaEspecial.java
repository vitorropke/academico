public class ContaEspecial extends ContaBancaria{
	private float limite;

	public float getLimite() {
		return limite;
	}
	public void setLimite(float limite) {
		if(limite > 0) {
			this.limite = limite;
		}else {
			this.limite = 0;
		}
	}
	
	public void sacar(float valor) {
		if((saldo >= valor) || ((saldo < 0) && (valor <= getLimite()))) {
			saldo -= valor;
		}else {
			System.out.println("Saldo insuficiente!");
		}
	}
}
