package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.exception.NotFoundException;
import br.edu.ufersa.ropke.locadoramaven.exception.FoundException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.PessoaDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.PessoaVO;

public abstract class PessoaBO<VO extends PessoaVO> extends OperacaoBO<VO> {
	private PessoaDAO<VO> pessoaDAO = new PessoaDAO<VO>();

	public boolean isNull(VO pessoa, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if ((pessoa != null) && (arquivo != null)) {
			// Verifica se parâmetros importantes não são nulos
			if ((pessoa.getNome() != null) && (pessoa.getCpf() != null) && (pessoa.getEndereco() != null)) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	@Override
	public void cadastrar(VO pessoa, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(pessoa, arquivo)) {
			if (pessoaDAO.pesquisar(pessoa, arquivo) == null) {
				pessoaDAO.cadastrar(pessoa, arquivo);
			} else {
				throw new FoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void alterar(VO pessoa, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(pessoa, arquivo)) {
			if (pessoaDAO.pesquisar(pessoa, arquivo) != null) {
				pessoaDAO.alterar(pessoa, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void deletar(VO pessoa, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(pessoa, arquivo)) {
			if (pessoaDAO.pesquisar(pessoa, arquivo) != null) {
				pessoaDAO.deletar(pessoa, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public VO pesquisar(VO pessoa, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(pessoa, arquivo)) {
			return pessoaDAO.pesquisar(pessoa, arquivo);
		} else {
			return null;
		}
	}
}
