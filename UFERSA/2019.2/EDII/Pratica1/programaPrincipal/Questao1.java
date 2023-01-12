package programaPrincipal;

import classeNo.No;

public class Questao1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		No noA = new No();
		No noB = new No();
		No noC = new No();
		No noD = new No();
		No noE = new No();
		No noF = new No();
		
		noA.valor = 'a';
		noB.valor = 'b';
		noC.valor = 'c';
		noD.valor = 'd';
		noE.valor = 'e';
		noF.valor = 'f';
		
		noA.esquerdo = noB;
		noA.direito = noC;
		noB.esquerdo = noD;
		noB.direito = noE;
		noC.direito = noF;
		
		System.out.println(noA.valor);
		System.out.println(noA.esquerdo.valor);
		System.out.println(noB.esquerdo.valor);
		System.out.println(noB.direito.valor);
		System.out.println(noA.direito.valor);
		System.out.println(noC.direito.valor);
	}

}
