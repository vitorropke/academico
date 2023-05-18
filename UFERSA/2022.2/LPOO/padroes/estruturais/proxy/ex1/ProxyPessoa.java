package padroes.estruturais.proxy.ex1;

public class ProxyPessoa implements Pessoa {
	private String id;
	private Pessoa pessoa;

	public ProxyPessoa(String nome) {
		this.id = nome;
	}

	@Override
	public String getNome() {
		if (pessoa == null) {
			// Apenas cria o objeto real quando chamar este método.
			pessoa = PessoaDAO.getPessoaByID(id);
		}
		// Retorna o objeto real.
		return pessoa.getNome();
	}

	@Override
	public String getId() {
		return id;
	}
}
