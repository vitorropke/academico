package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.LivroDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.LivroVO;

public class LivroBO extends EmprestavelBO<LivroVO> {
	private final File arquivo = LivroDAO.getArquivo();
	private LivroDAO livroDAO = new LivroDAO();

	public boolean isNull(LivroVO livro) {
		// Verifica se a entrada de argumentos não é nula
		if ((livro != null) && (arquivo != null)) {
			// Verifica se parâmetros importantes não são nulos
			if ((livro.getNumeroPaginas() != 0) && (livro.getGenero() != null)) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	public void cadastrar(LivroVO livro) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(livro)) {
			super.cadastrar(livro, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void alterar(LivroVO livro) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(livro)) {
			super.alterar(livro, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void deletar(LivroVO livro) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(livro)) {
			super.deletar(livro, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public LivroVO pesquisar(LivroVO livro) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(livro)) {
			return super.pesquisar(livro, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public ArrayList<LivroVO> listar() {
		return super.listar(arquivo);
	}

	public ArrayList<LivroVO> pesquisarTitulo(String titulo) {
		return super.pesquisarTitulo(titulo, arquivo);
	}

	public ArrayList<LivroVO> pesquisarAnoLancamento(int anoLancamento) {
		return super.pesquisarAnoLancamento(anoLancamento, arquivo);
	}

	public ArrayList<LivroVO> pesquisarGenero(String titulo) {
		if ((titulo != null) && (!titulo.isBlank())) {
			return livroDAO.pesquisarGenero(titulo);
		} else {
			return new ArrayList<LivroVO>();
		}
	}
}
