package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;
import java.util.Calendar;

import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.exception.NotFoundException;
import br.edu.ufersa.ropke.locadoramaven.exception.FoundException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.EmprestavelDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestavelVO;

public abstract class EmprestavelBO<VO extends EmprestavelVO> extends OperacaoBO<VO> {
	private EmprestavelDAO<VO> emprestavelDAO = new EmprestavelDAO<VO>();

	public boolean isNull(VO emprestavel, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if ((emprestavel != null) && (arquivo != null)) {
			// Verifica se parâmetros importantes não são nulos
			if (emprestavel.getTitulo() != null) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	@Override
	public void cadastrar(VO emprestavel, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(emprestavel, arquivo)) {
			// Verifica se o emprestavel não existe no sistema
			if (emprestavelDAO.pesquisar(emprestavel, arquivo) == null) {
				emprestavelDAO.cadastrar(emprestavel, arquivo);
			} else {
				throw new FoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void alterar(VO emprestavel, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(emprestavel, arquivo)) {
			// Verifica se o emprestavel existe no sistema
			if (emprestavelDAO.pesquisar(emprestavel, arquivo) != null) {
				emprestavelDAO.alterar(emprestavel, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void deletar(VO emprestavel, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(emprestavel, arquivo)) {
			// Verifica se o emprestavel existe no sistema
			if (emprestavelDAO.pesquisar(emprestavel, arquivo) != null) {
				emprestavelDAO.deletar(emprestavel, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public VO pesquisar(VO emprestavel, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(emprestavel, arquivo)) {
			return emprestavelDAO.pesquisar(emprestavel, arquivo);
		} else {
			return null;
		}
	}

	public ArrayList<VO> pesquisarTitulo(String titulo, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if ((titulo != null) && (!titulo.isBlank()) && (arquivo != null)) {
			return emprestavelDAO.pesquisarTitulo(titulo, arquivo);
		} else {
			return new ArrayList<VO>();
		}
	}

	public ArrayList<VO> pesquisarAnoLancamento(int anoLancamento, File arquivo) {
		int anoAtual = Calendar.getInstance().get(Calendar.YEAR);

		// Verifica se a entrada de argumentos é vaĺida
		if ((anoLancamento <= anoAtual) && (arquivo != null)) {
			return emprestavelDAO.pesquisarAnoLancamento(anoLancamento, arquivo);
		} else {
			return new ArrayList<VO>();
		}
	}
}
