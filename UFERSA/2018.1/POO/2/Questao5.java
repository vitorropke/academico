class Calculadora{
	int operando1, operando2;
	
	public Calculadora(int operando1, int operando2){
		this.operando1 = operando1;
		this.operando2 = operando2;
	}
	
	public int somarOperandos(){
		return operando1 + operando2;
	}
	
	public int multiplicarOperandos(){
		return operando1 * operando2;
	}
	
	public void alterarOperandos(int operando1, int operando2){
		this.operando1 = operando1;
		this.operando2 = operando2;
	}
	
	public String toString(){
		return "Operando 1 = " + operando1 + 
				"\nOperando 2 = " + operando2;
	}
}