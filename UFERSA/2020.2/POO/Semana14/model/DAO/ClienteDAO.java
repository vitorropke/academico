package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import br.edu.ufersa.ropke.locadoramaven.model.VO.ClienteVO;

public class ClienteDAO extends PessoaDAO<ClienteVO> {
	private static final File arquivo = new File(
			"src/main/java/br/edu/ufersa/ropke/locadoramaven/model/DAO/arquivos/clientes.dat");

	public static File getArquivo() {
		return arquivo;
	}

	public void cadastrar(ClienteVO cliente) {
		super.cadastrar(cliente, arquivo);
	}

	public void alterar(ClienteVO cliente) {
		super.alterar(cliente, arquivo);
	}

	public void deletar(ClienteVO cliente) {
		super.deletar(cliente, arquivo);
	}

	public void pesquisar() {
		super.pesquisar(arquivo);
	}

	public ClienteVO pesquisar(ClienteVO cliente) {
		return super.pesquisar(cliente, arquivo);
	}

	public ArrayList<ClienteVO> listar() {
		return super.listar(arquivo);
	}

	public ArrayList<ClienteVO> pesquisarNome(String nome) {
		ArrayList<ClienteVO> clientes = new ArrayList<ClienteVO>();

		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				ClienteVO clienteLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os clientes do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					clienteLeitura = (ClienteVO) objetoLeitura.readObject();

					// Salva o cliente no vetor quando o nome conter parte da string que vem do
					// parâmetro
					if (clienteLeitura.getNome().contains(nome)) {
						clientes.add(clienteLeitura);
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return clientes;
	}

	public ClienteVO pesquisarCpf(String cpf) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				ClienteVO clienteLeitura;

				// Reduz o CPF, removendo tudo que não é dígito
				cpf = cpf.replaceAll("\\D+", "");

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os clientes do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					clienteLeitura = (ClienteVO) objetoLeitura.readObject();

					// Retorna o cliente quando obter o mesmo cpf
					if (clienteLeitura.getCpf().equals(cpf)) {
						arquivoLeitura.close();
						objetoLeitura.close();
						return clienteLeitura;
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("O cliente nao existe no sistema!");
		return null;
	}
}
