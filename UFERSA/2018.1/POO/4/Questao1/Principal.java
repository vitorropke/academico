import java.util.LinkedList;
import java.util.List;

public class Principal {

	public static void main(String[] args) {
		List<Produto> carrinho = new LinkedList<Produto>();
		
		carrinho.add(new Mouse("Ryzer", "USB ouro. 12000dpi"));
		carrinho.add(new Livro("Maur�cio de Souza", "Turma da M�nica"));
		
		//(Produto)carrinho.getDescricao();
	}

}
