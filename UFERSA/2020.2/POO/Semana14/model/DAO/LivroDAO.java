package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.LivroVO;

public class LivroDAO extends EmprestavelDAO<LivroVO> {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/livros.dat");

	public static File getArquivo() {
		return arquivo;
	}

	public void cadastrar(LivroVO livro) {
		super.cadastrar(livro, arquivo);
	}

	public void alterar(LivroVO livro) {
		super.alterar(livro, arquivo);
	}

	public void deletar(LivroVO livro) {
		super.deletar(livro, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public LivroVO pesquisar(LivroVO livro) {
		return super.pesquisar(livro, arquivo);
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

	public ArrayList<LivroVO> pesquisarGenero(String genero) {
		ArrayList<LivroVO> livros = new ArrayList<LivroVO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				LivroVO livroLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os livros do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					livroLeitura = (LivroVO) objetoLeitura.readObject();

					// Salva o livro no vetor quando parte do nome do gênero coincidir com o
					// parâmetro
					if (livroLeitura.getGenero().contains(genero)) {
						livros.add(livroLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return livros;
	}
}
