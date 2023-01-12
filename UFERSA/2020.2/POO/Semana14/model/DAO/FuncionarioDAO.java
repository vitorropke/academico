package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.FuncionarioVO;

public class FuncionarioDAO extends UsuarioDAO<FuncionarioVO> {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/funcionarios.dat");

	public static File getArquivo() {
		return arquivo;
	}

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
}
