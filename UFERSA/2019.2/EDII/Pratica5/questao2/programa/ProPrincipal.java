package questao2.programa;
import questao2.ABAA.*;

public class ProPrincipal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//SLIDE 14 - ÁRVORE DA ESQUERDA
		No noA = new No(null, null, 'A');
		No noB = new No(null, null, 'B');
		No noC = new No(null, null, 'C');
		No noD = new No(null, null, 'D');
		No noE = new No(null, null, 'E');
		No noF = new No(null, null, 'F');
		No noG = new No(null, null, 'G');
		No noH = new No(null, null, 'H');
		No noI = new No(null, null, 'I');
		No noJ = new No(null, null, 'J');
		
		No no1 = new No(noA, noB, '1');
		noA.setPai(no1);
		noB.setPai(no1);
		
		No no2 = new No(no1, noC, '2');
		no1.setPai(no2);
		noC.setPai(no2);
		
		No no6 = new No(noF, noG, '6');
		noF.setPai(no6);
		noG.setPai(no6);
		
		No no5 = new No(noE, no6, '5');
		noE.setPai(no5);
		no6.setPai(no5);
		
		No no4 = new No(noD, no5, '4');
		noD.setPai(no4);
		no5.setPai(no4);
		
		No no8 = new No(noH, noI, '8');
		noH.setPai(no8);
		noI.setPai(no8);
		
		No no7 = new No(no4, no8, '7');
		no4.setPai(no7);
		no8.setPai(no7);
		
		No no3 = new No(no2, no7, '3');
		no2.setPai(no3);
		no7.setPai(no3);
		
		No no9 = new No(no3, noJ, '9');
		no3.setPai(no9);
		noJ.setPai(no9);
		
		No raiz = no9;
		
		//Passa a raiz
		System.out.println("Pré-ordem: ");
		raiz.preOrdem(raiz);
		System.out.println();
		System.out.println("Ordem: ");
		raiz.Ordem(raiz);
		System.out.println();
		
		raiz.difusaoCompleta(raiz, no6);
		raiz.rotacaoDireitaSimples(no4);
		raiz.rotacaoEsquerdaSimples(no4);
		
		System.out.println();
		System.out.println("Após a difusão completa do nó 6:");
		System.out.println("Pré-ordem: ");
		raiz.preOrdem(raiz);
		System.out.println();
		System.out.println("Ordem: ");
		raiz.Ordem(raiz);
		System.out.println();
		
		//Escolhi o nó 3
		raiz.difusao(raiz, no3);
		
		System.out.println("Após a difusão do nó 3:");
		System.out.println();
		System.out.println("Pré-ordem: ");
		raiz.preOrdem(raiz);
		System.out.println();
		System.out.println("Ordem: ");
		raiz.Ordem(raiz);
		System.out.println();
	}

}
