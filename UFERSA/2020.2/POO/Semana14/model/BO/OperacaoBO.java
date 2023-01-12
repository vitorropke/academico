package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.OperacaoDAO;

public abstract class OperacaoBO<VO> implements OperacaoInterBO<VO> {
	private OperacaoDAO<VO> operacaoDAO = new OperacaoDAO<VO>();

	public boolean isNull(File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (arquivo != null) {
			return false;
		} else {
			return true;
		}
	}

	@Override
	public void pesquisar(File arquivo) {
		// Verifica se a entrada de argumento não é nula
		if (!isNull(arquivo)) {
			operacaoDAO.pesquisar(arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public ArrayList<VO> listar(File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(arquivo)) {
			return operacaoDAO.listar(arquivo);
		} else {
			return new ArrayList<VO>();
		}
	}
}
