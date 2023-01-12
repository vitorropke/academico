public class ContaPoupanca extends ContaBancaria{
	private int diaDeRendimento;
	private double taxaDeRendimento;
	
	public int getDiaDeRendimento() {
		return diaDeRendimento;
	}
	public void setDiaDeRendimento(int diaDeRendimento) {
		if(diaDeRendimento > 0) {
			this.diaDeRendimento = diaDeRendimento;
		}else {
			this.diaDeRendimento = 0;
		}
	}
	
	public double getTaxaDeRendimento() {
		return taxaDeRendimento;
	}
	public void setTaxaDeRendimento(double taxaDeRendimento) {
		if(taxaDeRendimento > 0) {
			this.taxaDeRendimento = taxaDeRendimento;
		}else {
			this.taxaDeRendimento = 0;
		}
	}
	
	public void calcularNovoSaldo() {
		saldo += saldo * getTaxaDeRendimento() * getDiaDeRendimento();
	}
}
