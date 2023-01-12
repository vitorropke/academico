package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestimoVO;

public class EmprestimoDAO {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/emprestimos.dat");

	public static File getArquivo() {
		return arquivo;
	}

	public void cadastrar(EmprestimoVO emprestimo) {
		try {
			FileOutputStream arquivoGravador = new FileOutputStream(arquivo, true);
			// Classe responsável por inserir o empréstimo
			ObjectOutputStream objetoGravador = new ObjectOutputStream(arquivoGravador);

			// Grava o objeto empréstimo no arquivo
			objetoGravador.writeObject(emprestimo);
			objetoGravador.flush();
			arquivoGravador.close();
			objetoGravador.close();

			System.out.println("Emprestimo gravado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void alterar(EmprestimoVO emprestimo) {
		try {
			ArrayList<EmprestimoVO> emprestimos = new ArrayList<EmprestimoVO>();

			// Procura pelo empréstimo enquanto salva os outros em um vetor de empréstimos
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				EmprestimoVO emprestimoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os empréstimos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestimoLeitura = (EmprestimoVO) objetoLeitura.readObject();

					// Compara os empréstimos pelo id deles
					if (emprestimoLeitura.getIdEmprestimo() == emprestimo.getIdEmprestimo()) {
						// Quando for o empréstimo a ser alterado, insere no vetor, o empréstimo que vem
						// do parâmetro do método 'alterar'
						emprestimos.add(emprestimo);
					} else {
						// Quando não for o empréstimo a ser alterado, insere do arquivo
						emprestimos.add(emprestimoLeitura);
					}
				}

				arquivoLeitura.close();
			}

			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorEmprestimos = emprestimos.size();

			for (int i = 0; i < tamanhoVetorEmprestimos; i++) {
				// Classe responsável por inserir os empréstimos
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava o objeto empréstimo no arquivo
				objetoGravador.writeObject(emprestimos.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Emprestimo alterado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void deletar(EmprestimoVO emprestimo) {
		try {
			ArrayList<EmprestimoVO> emprestimos = new ArrayList<EmprestimoVO>();

			// Procura pelo empréstimo enquanto salva os outros em um vetor de empréstimos
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				EmprestimoVO emprestimoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os empréstimos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestimoLeitura = (EmprestimoVO) objetoLeitura.readObject();

					// Compara os empréstimos pelo id deles
					if (emprestimoLeitura.getIdEmprestimo() != emprestimo.getIdEmprestimo()) {
						// Quando não encontrar o empréstimo, insere no vetor
						// Quando encontrar o empréstimo, não insere no vetor
						emprestimos.add(emprestimoLeitura);
					}
				}

				arquivoLeitura.close();
			}

			FileOutputStream arquivoGravador = new FileOutputStream(arquivo);
			ObjectOutputStream objetoGravador;
			int tamanhoVetorEmprestimos = emprestimos.size();

			for (int i = 0; i < tamanhoVetorEmprestimos; i++) {
				// Classe responsável por inserir o empréstimo
				objetoGravador = new ObjectOutputStream(arquivoGravador);

				// Grava o empréstimo no arquivo
				objetoGravador.writeObject(emprestimos.get(i));
				objetoGravador.flush();
			}

			arquivoGravador.close();

			System.out.println("Emprestimo apagado com sucesso!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void pesquisar() {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				EmprestimoVO emprestimo;

				int indiceEmprestimo = 1;
				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os empréstimos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestimo = (EmprestimoVO) objetoLeitura.readObject();
					System.out.println("\nEmprestimo " + indiceEmprestimo + '\n');
					System.out.println(emprestimo.toString());
					System.out.println("==============================================");
					indiceEmprestimo++;
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public EmprestimoVO pesquisar(EmprestimoVO emprestimo) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				EmprestimoVO emprestimoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os empréstimos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestimoLeitura = (EmprestimoVO) objetoLeitura.readObject();

					// Compara os empréstimos pelo id deles
					if (emprestimoLeitura.getIdEmprestimo() == emprestimo.getIdEmprestimo()) {
						arquivoLeitura.close();
						objetoLeitura.close();
						return emprestimoLeitura;
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Emprestimo nao encontrado!");
		return null;
	}

	public ArrayList<EmprestimoVO> listar() {
		ArrayList<EmprestimoVO> emprestimos = new ArrayList<EmprestimoVO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				EmprestimoVO emprestimoLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os empréstimos do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					emprestimoLeitura = (EmprestimoVO) objetoLeitura.readObject();

					emprestimos.add(emprestimoLeitura);
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return emprestimos;
	}
}
