package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.PessoaVO;

public class PessoaDAO<VO extends PessoaVO> extends OperacaoDAO<VO> {
	@SuppressWarnings("unchecked")
	@Override
	public void alterar(VO pessoa, File arquivo) {
		try {
			ArrayList<VO> pessoas = new ArrayList<VO>();

			// Procura pela pessoa enquanto salva os outros em um vetor de pessoas
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO pessoaLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar as pessoas do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					pessoaLeitura = (VO) objetoLeitura.readObject();

					// Compara as pessoas pelo CPF delas
					if (pessoaLeitura.getCpf().equals(pessoa.getCpf())) {
						// Quando for a pessoa a ser alterada, insere no vetor, a pessoa que vem do
						// parâmetro do método 'alterar'
						pessoas.add(pessoa);
					} else {
						// Quando não for a pessoa a ser alterada, insere do arquivo
						pessoas.add(pessoaLeitura);
					}
				}

				arquivoLeitura.close();
			}

			// Escrita com o objeto modificado
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorPessoas = pessoas.size();

			for (int i = 0; i < tamanhoVetorPessoas; i++) {
				// Classe responsável por inserir os objetos
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava o objeto pessoa no arquivo
				objetoGravador.writeObject(pessoas.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Pessoa alterada com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public void deletar(VO pessoa, File arquivo) {
		try {
			ArrayList<VO> pessoas = new ArrayList<VO>();

			// Procura pela pessoa enquanto salva os outros em um vetor de pessoas
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO pessoaLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar as pessoas do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					pessoaLeitura = (VO) objetoLeitura.readObject();

					// Compara as pessoas pelo CPF delas
					if (!pessoaLeitura.getCpf().equals(pessoa.getCpf())) {
						// Quando não encontrar a pessoa, insere no vetor
						// Quando encontrar a pessoa, não insere no vetor
						pessoas.add(pessoaLeitura);
					}
				}

				arquivoLeitura.close();
			}

			// Escrita com a pessoa removida
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorPessoas = pessoas.size();

			for (int i = 0; i < tamanhoVetorPessoas; i++) {
				// Classe responsável por inserir as pessoas
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava a pessoa no arquivo
				objetoGravador.writeObject(pessoas.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Pessoa apagada com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public VO pesquisar(VO pessoa, File arquivo) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				String cpf;
				VO pessoaLeitura;

				// Reduz o CPF, removendo tudo que não é dígito
				cpf = pessoa.getCpf().replaceAll("\\D+", "");

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar as pessoas do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					pessoaLeitura = (VO) objetoLeitura.readObject();

					// Retorna a pessoa quando obter o mesmo cpf
					if (pessoaLeitura.getCpf().equals(cpf)) {
						arquivoLeitura.close();
						objetoLeitura.close();
						return pessoaLeitura;
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Pessoa nao encontrada");
		return null;
	}
}