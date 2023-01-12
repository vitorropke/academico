package programaPrincipal;

import classeNo.No;

public class Questao2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		No noA = new No();
		No noB = new No();
		No noC = new No();
		No noD = new No();
		No noE = new No();
		
		No noAdicao = new No();
		No noSubtracao = new No();
		No noMultiplicacao = new No();
		No noDivisao = new No();
		
		noA.valor = 'a';
		noB.valor = 'b';
		noC.valor = 'c';
		noD.valor = 'd';
		noE.valor = 'e';
		
		noAdicao.valor = '+';
		noSubtracao.valor = '-';
		noMultiplicacao.valor = '*';
		noDivisao.valor = '/';
		
		noAdicao.esquerdo = noA;
		noAdicao.direito = noMultiplicacao;
		noMultiplicacao.esquerdo = noB;
		noMultiplicacao.direito = noDivisao;
		noDivisao.esquerdo = noC;
		noDivisao.direito = noSubtracao;
		noSubtracao.esquerdo = noD;
		noSubtracao.direito = noE;
		
		System.out.print(noAdicao.esquerdo.valor);
		System.out.print(noAdicao.valor);
		System.out.print(noMultiplicacao.esquerdo.valor);
		System.out.print(noAdicao.direito.valor);
		System.out.print(noDivisao.esquerdo.valor);
		System.out.print(noDivisao.valor);
		System.out.print(noSubtracao.esquerdo.valor);
		System.out.print(noSubtracao.valor);
		System.out.print(noSubtracao.direito.valor);
	}

}
