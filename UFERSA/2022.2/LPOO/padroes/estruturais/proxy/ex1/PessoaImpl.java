package padroes.estruturais.proxy.ex1;

public class PessoaImpl implements Pessoa {
	// Objeto real.
	private String nome;
	private String id;

	public PessoaImpl(String nome, String id) {
		this.nome = nome;
		this.id = id;
		// Simula retorno do banco de dados.
		System.out.println("Retornou a pessoa do banco de dados -> " + nome);
	}

	@Override
	public String getNome() {
		return nome;
	}

	@Override
	public String getId() {
		return id;
	}
}
