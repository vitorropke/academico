
public class Mouse extends Produto{
	private String tipo;

	public Mouse(String tipo, String descricao) {
		super();
		this.tipo = "Mouse �tico";
		this.descricao = "Sa�da USB. 1.600 dpi";
	}
	
	public String getDescricao() {
		return descricao + " " + tipo;
	}
	
}
