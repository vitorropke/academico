package questao3.execucao;

import questao3.ADB.ADB;

public class ProgramaADB {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ADB arvoreDBinaria = new ADB();
		
		arvoreDBinaria.inserir("1", 0);
		arvoreDBinaria.inserir("0", 1);
		arvoreDBinaria.inserir("0", 2);
		arvoreDBinaria.inserir("1", 3);
		arvoreDBinaria.imprimir();
	}

}
