package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class OperacaoDAO<VO> implements OperacaoInterDAO<VO> {
	@Override
	public void cadastrar(VO entidade, File arquivo) {
		try {
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo, true);
			// Classe responsável por inserir o objeto
			ObjectOutputStream objetoGravador = new ObjectOutputStream(arquivoGravador);

			// Grava o objeto entidade no arquivo
			objetoGravador.writeObject(entidade);
			objetoGravador.flush();
			arquivoGravador.close();
			objetoGravador.close();

			System.out.println("Objeto gravado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public void pesquisar(File arquivo) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO entidade;

				int indice = 1;
				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os objetos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					entidade = (VO) objetoLeitura.readObject();
					System.out.println("\nObjeto " + indice + '\n');
					System.out.println(entidade.toString());
					System.out.println("==============================================");
					indice++;
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public ArrayList<VO> listar(File arquivo) {
		ArrayList<VO> entidades = new ArrayList<VO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO entidadeLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os objetos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					entidadeLeitura = (VO) objetoLeitura.readObject();

					entidades.add(entidadeLeitura);
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return entidades;
	}

	@Override
	public void alterar(VO entidade, File arquivo) {
		// TODO Auto-generated method stub

	}

	@Override
	public void deletar(VO entidade, File arquivo) {
		// TODO Auto-generated method stub

	}

	@Override
	public VO pesquisar(VO entidade, File arquivo) {
		// TODO Auto-generated method stub
		return null;
	}
}
