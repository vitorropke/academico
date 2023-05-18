package padroes.estruturais.proxy.ex1;

import java.util.ArrayList;
import java.util.List;

public class Main {
	// https://www.devmedia.com.br/conheca-o-pattern-proxy-gof-gang-of-four/4066
	public static void main(String[] args) {
		List<Pessoa> pessoas = new ArrayList<Pessoa>();

		// Cria cada Proxy para encapsular o acesso à classe "PessoaImpl".
		pessoas.add(new ProxyPessoa("A"));
		pessoas.add(new ProxyPessoa("B"));
		pessoas.add(new ProxyPessoa("C"));

		// Busca do banco de dados.
		System.out.println("Nome: " + pessoas.get(0).getNome());
		// Busca do banco de dados.
		System.out.println("Nome: " + pessoas.get(1).getNome());
		// Já buscou essa pessoa. Retorna do cache
		System.out.println("Nome: " + pessoas.get(0).getNome());

		// A terceira pessoa nunca será consultada no banco de dados
		// (melhor performance - lazy loading)
		System.out.println("Id da 3ª - " + pessoas.get(2).getId());
		// pode imprimir o ID do objeto, e o proxy nao será inicializado.
	}
}
