package padroes.estruturais.proxy.ex1;

public class PessoaDAO {
	// Simula acesso ao banco de dados.
	public static Pessoa getPessoaByID(String id) {
		System.out.println("select * from PESSOA where id=" + id);
		return new PessoaImpl("Pessoa " + id, id);
	}
}
