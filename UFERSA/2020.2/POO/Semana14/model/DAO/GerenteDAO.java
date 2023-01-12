package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.GerenteVO;

public class GerenteDAO extends UsuarioDAO<GerenteVO> {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/gerentes.dat");

	public static File getArquivo() {
		return arquivo;
	}

	public void cadastrar(GerenteVO gerente) {
		super.cadastrar(gerente, arquivo);
	}

	public void alterar(GerenteVO gerente) {
		super.alterar(gerente, arquivo);
	}

	public void deletar(GerenteVO gerente) {
		super.deletar(gerente, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public GerenteVO pesquisar(GerenteVO gerente) {
		return super.pesquisar(gerente, arquivo);
	}

	public ArrayList<GerenteVO> listar() {
		return super.listar(arquivo);
	}

	public GerenteVO pesquisarLogin(GerenteVO gerente) {
		return super.pesquisarLogin(gerente, arquivo);
	}
}
