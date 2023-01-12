package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.DiscoDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.DiscoVO;

public class DiscoBO extends EmprestavelBO<DiscoVO> {
	private final File arquivo = DiscoDAO.getArquivo();
	private DiscoDAO discoDAO = new DiscoDAO();

	public boolean isNull(DiscoVO disco) {
		// Verifica se a entrada de argumentos não é nula
		if ((disco != null) && (arquivo != null)) {
			// Verifica se parâmetros importantes não são nulos
			if ((disco.getBanda() != null) && (disco.getEstilo() != null)) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	public void cadastrar(DiscoVO disco) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(disco)) {
			super.cadastrar(disco, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void alterar(DiscoVO disco) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(disco)) {
			super.alterar(disco, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void deletar(DiscoVO disco) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(disco)) {
			super.deletar(disco, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public DiscoVO pesquisar(DiscoVO disco) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(disco)) {
			return super.pesquisar(disco, arquivo);
		} else {
			throw new InvalidParameterException();
		}
	}

	public ArrayList<DiscoVO> listar() {
		return super.listar(arquivo);
	}

	public ArrayList<DiscoVO> pesquisarTitulo(String titulo) {
		return super.pesquisarTitulo(titulo, arquivo);
	}

	public ArrayList<DiscoVO> pesquisarAnoLancamento(int anoLancamento) {
		return super.pesquisarAnoLancamento(anoLancamento, arquivo);
	}

	public ArrayList<DiscoVO> pesquisarBanda(String banda) {
		if ((banda != null) && (!banda.isBlank())) {
			return discoDAO.pesquisarBanda(banda);
		} else {
			return new ArrayList<DiscoVO>();
		}
	}

	public ArrayList<DiscoVO> pesquisarEstilo(String estilo) {
		if ((estilo != null) && (!estilo.isBlank())) {
			return discoDAO.pesquisarEstilo(estilo);
		} else {
			return new ArrayList<DiscoVO>();
		}
	}
}
