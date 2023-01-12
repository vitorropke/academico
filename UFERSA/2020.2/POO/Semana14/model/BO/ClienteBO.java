package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.DAO.ClienteDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.ClienteVO;

public class ClienteBO extends PessoaBO<ClienteVO> {
	private final File arquivo = ClienteDAO.getArquivo();
	private ClienteDAO clienteDAO = new ClienteDAO();

	public void cadastrar(ClienteVO cliente) {
		super.cadastrar(cliente, arquivo);
	}

	public void alterar(ClienteVO cliente) {
		super.alterar(cliente, arquivo);
	}

	public void deletar(ClienteVO cliente) {
		super.deletar(cliente, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public ClienteVO pesquisar(ClienteVO cliente) {
		return super.pesquisar(cliente, arquivo);
	}
	
	public ArrayList<ClienteVO> listar() {
		return super.listar(arquivo);
	}

	public ArrayList<ClienteVO> pesquisarNome(String nome) {
		if ((nome != null) && (!nome.isBlank())) {
			return clienteDAO.pesquisarNome(nome);
		} else {
			return new ArrayList<ClienteVO>();
		}
	}

	public ClienteVO pesquisarCpf(String cpf) {
		if ((cpf != null) && (!cpf.isBlank())) {
			return clienteDAO.pesquisarCpf(cpf);
		} else {
			return null;
		}
	}
}
