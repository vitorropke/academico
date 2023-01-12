package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.DiscoVO;

public class DiscoDAO extends EmprestavelDAO<DiscoVO> {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/discos.dat");

	public static File getArquivo() {
		return arquivo;
	}

	public void cadastrar(DiscoVO disco) {
		super.cadastrar(disco, arquivo);
	}

	public void alterar(DiscoVO disco) {
		super.alterar(disco, arquivo);
	}

	public void deletar(DiscoVO disco) {
		super.deletar(disco, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public DiscoVO pesquisar(DiscoVO disco) {
		return super.pesquisar(disco, arquivo);
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
		ArrayList<DiscoVO> discos = new ArrayList<DiscoVO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				DiscoVO discoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os discos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					discoLeitura = (DiscoVO) objetoLeitura.readObject();

					// Salva o disco no vetor quando parte do nome da banda coincidir com o
					// parâmetro
					if (discoLeitura.getBanda().contains(banda)) {
						discos.add(discoLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return discos;
	}

	public ArrayList<DiscoVO> pesquisarEstilo(String estilo) {
		ArrayList<DiscoVO> discos = new ArrayList<DiscoVO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				DiscoVO discoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os discos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					discoLeitura = (DiscoVO) objetoLeitura.readObject();

					// Salva o disco no vetor quando parte do nome do estilo coincidir com o
					// parâmetro
					if (discoLeitura.getEstilo().contains(estilo)) {
						discos.add(discoLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return discos;
	}
}
