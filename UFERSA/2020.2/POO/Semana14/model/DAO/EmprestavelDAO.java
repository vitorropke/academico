package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestavelVO;

public class EmprestavelDAO<VO extends EmprestavelVO> extends OperacaoDAO<VO> {
	@SuppressWarnings("unchecked")
	@Override
	public void alterar(VO emprestavel, File arquivo) {
		try {
			ArrayList<VO> emprestaveis = new ArrayList<VO>();

			// Procura pelo emprestável enquanto salva os outros em um vetor de emprestáveis
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO emprestavelLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os emprestáveis do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestavelLeitura = (VO) objetoLeitura.readObject();

					// Compara os emprestáveis pelo título deles
					if (emprestavelLeitura.getTitulo().equals(emprestavel.getTitulo())) {
						// Quando for o emprestável a ser alterado, insere no vetor, o emprestável que
						// vem do parâmetro do método 'alterar'
						emprestaveis.add(emprestavel);
					} else {
						// Quando não for o emprestável a ser alterado, insere do arquivo
						emprestaveis.add(emprestavelLeitura);
					}
				}

				arquivoLeitura.close();
			}

			// Escrita com o emprestável modificado
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorEmprestaveis = emprestaveis.size();

			for (int i = 0; i < tamanhoVetorEmprestaveis; i++) {
				// Classe responsável por inserir os emprestáveis
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava o emprestável no arquivo
				objetoGravador.writeObject(emprestaveis.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Emprestavel alterado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public void deletar(VO emprestavel, File arquivo) {
		try {
			ArrayList<VO> emprestaveis = new ArrayList<VO>();

			// Procura pelo emprestável enquanto salva os outros em um vetor de emprestáveis
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO emprestavelLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os emprestáveis do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestavelLeitura = (VO) objetoLeitura.readObject();

					// Compara os emprestáveis pelo título deles
					if (!emprestavelLeitura.getTitulo().equals(emprestavel.getTitulo())) {
						// Quando não encontrar o emprestável, insere no vetor
						// Quando encontrar o emprestável, não insere no vetor
						emprestaveis.add(emprestavelLeitura);
					}
				}

				arquivoLeitura.close();
			}

			// Escrita com o emprestável removido
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorEmprestaveis = emprestaveis.size();

			for (int i = 0; i < tamanhoVetorEmprestaveis; i++) {
				// Classe responsável por inserir os emprestáveis
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava o emprestável no arquivo
				objetoGravador.writeObject(emprestaveis.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Emprestavel apagado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public VO pesquisar(VO emprestavel, File arquivo) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO emprestavelLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os emprestáveis do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestavelLeitura = (VO) objetoLeitura.readObject();

					// Retorna o emprestável quando obter o mesmo título
					if (emprestavelLeitura.getTitulo().equals(emprestavel.getTitulo())) {
						arquivoLeitura.close();
						objetoLeitura.close();
						return emprestavelLeitura;
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Emprestavel nao encontrado");
		return null;
	}

	@SuppressWarnings("unchecked")
	public ArrayList<VO> pesquisarTitulo(String titulo, File arquivo) {
		ArrayList<VO> emprestaveis = new ArrayList<VO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO emprestavelLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os emprestáveis do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestavelLeitura = (VO) objetoLeitura.readObject();

					// Salva o emprestável no vetor quando parte do nome do título coincidir com o
					// parâmetro
					if (emprestavelLeitura.getTitulo().contains(titulo)) {
						emprestaveis.add(emprestavelLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return emprestaveis;
	}

	@SuppressWarnings("unchecked")
	public ArrayList<VO> pesquisarAnoLancamento(int anoLancamento, File arquivo) {
		ArrayList<VO> emprestaveis = new ArrayList<VO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO emprestavelLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os emprestáveis do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestavelLeitura = (VO) objetoLeitura.readObject();

					// Salva o emprestável no vetor quando o ano for igual ao parâmetro
					if (emprestavelLeitura.getAnoLancamento() == anoLancamento) {
						emprestaveis.add(emprestavelLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return emprestaveis;
	}
}
