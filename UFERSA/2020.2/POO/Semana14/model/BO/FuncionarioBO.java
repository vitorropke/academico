package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.DAO.FuncionarioDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.FuncionarioVO;

public class FuncionarioBO extends UsuarioBO<FuncionarioVO> {
	private final File arquivo = FuncionarioDAO.getArquivo();

	public void cadastrar(FuncionarioVO funcionario) {
		super.cadastrar(funcionario, arquivo);
	}

	public void alterar(FuncionarioVO funcionario) {
		super.alterar(funcionario, arquivo);
	}

	public void deletar(FuncionarioVO funcionario) {
		super.deletar(funcionario, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public FuncionarioVO pesquisar(FuncionarioVO funcionario) {
		return super.pesquisar(funcionario, arquivo);
	}

	public ArrayList<FuncionarioVO> listar() {
		return super.listar(arquivo);
	}

	public FuncionarioVO pesquisarLogin(FuncionarioVO funcionario) {
		return super.pesquisarLogin(funcionario, arquivo);
	}

	public boolean autenticar(FuncionarioVO funcionario) {
		return super.autenticar(funcionario, arquivo);
	}
}
