package prova3.loja;

import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import prova3.Cliente;
import prova3.Funcionario;
import prova3.armazenamento.DAO;
import prova3.categorias.*;
import prova3.usuarios.Usuario;

public class ImplLoja implements Loja {

	private static List<Usuario> usuariosCadastrados = new ArrayList<>(
			Arrays.asList(new Cliente("cliente", "123"), new Funcionario("funcionario", "456")));
	private static List<Carro> carros = DAO.lerArquivo();
	/*
	 * private static List<Carro> carros = new ArrayList<>( Arrays.asList(new
	 * Carro("Fiat Novo Uno", "19329025091", new Economico(), 2024, 5, 45000), new
	 * Carro("Chevrolet Onix", "12143350874", new Economico(), 2023, 15, 82490), new
	 * Carro("Ford Ka", "82631490820", new Economico(), 2016, 8, 51990),
	 * 
	 * new Carro("Ford Ka Sedan", "01342773028", new Intermediario(), 2021, 7,
	 * 49000), new Carro("Chevrolet Onix Plus", "07562383139", new Intermediario(),
	 * 2019, 3, 87590), new Carro("Hyundai HB20S", "33444810737", new
	 * Intermediario(), 2023, 4, 88790),
	 * 
	 * new Carro("Toyota Corolla", "17171554803", new Executivo(), 2023, 2, 146890),
	 * new Carro("Honda Civic", "36378745710", new Executivo(), 2018, 1, 244900),
	 * new Carro("Chevrolet Cruze", "30785277872", new Executivo(), 2023, 4,
	 * 148650)));
	 */

	@Override
	public List<Carro> adicionarCarro(Carro carro) throws RemoteException {
		carros = DAO.lerArquivo();
		carros.add(carro);
		DAO.escreverArquivo(carros);

		return listarCarros();
	}

	@Override
	public List<Carro> alterarCarro(Carro carroOriginal, Carro carroModificado) throws RemoteException {
		carros = DAO.lerArquivo();
		carros.set(encontrarIndiceDoCarroComparandoTudo(carroOriginal), carroModificado);
		DAO.escreverArquivo(carros);

		return listarCarros();
	}

	@Override
	public List<Carro> apagarCarro(String nomeCarro) throws RemoteException {
		int indiceCarro = encontrarIndiceDoCarroPorNomeOuRenavam(nomeCarro);
		if (indiceCarro != -1) {
			carros.remove(indiceCarro);
			DAO.escreverArquivo(carros);
		} else {
			return null;
		}

		return listarCarros();
	}

	@Override
	public List<Carro> listarCarros() throws RemoteException {
		carros = DAO.lerArquivo();
		// ordena os carros pelo nome
		Collections.sort(carros);

		return carros;
	}

	@Override
	public List<Carro> listarCarrosPorCategoria(Categoria categoriaCarro) throws RemoteException {
		carros = DAO.lerArquivo();
		List<Carro> carrosFiltrados = carros.stream()
				.filter(carro -> carro.getCategoria().getClass().equals(categoriaCarro.getClass()))
				.collect(Collectors.toList());

		// ordena os carros pelo nome
		Collections.sort(carrosFiltrados);

		return carrosFiltrados;
	}

	@Override
	public Carro pesquisarCarro(String nomeOuRenavamCarro) throws RemoteException {
		int indiceCarro = encontrarIndiceDoCarroPorNomeOuRenavam(nomeOuRenavamCarro);

		if (indiceCarro != -1) {
			return carros.get(indiceCarro);
		}

		return null;
	}

	@Override
	public int exibirQuantidadeCarros() throws RemoteException {
		int quantidade = 0;

		carros = DAO.lerArquivo();
		for (Carro carroAtual : carros) {
			quantidade += carroAtual.getQuantidadeDisponivel();
		}

		return quantidade;
	}

	@Override
	public Carro comprarCarro(Carro carro) throws RemoteException {
		if (carro == null) {
			return null;
		}

		if ((carro.getQuantidadeDisponivel() - 1) == 0) {
			apagarCarro(carro.getNome());
		} else {
			alterarCarro(carro, new Carro(carro.getNome(), carro.getRenavan(), carro.getCategoria(),
					carro.getAnoFabricacao(), carro.getQuantidadeDisponivel() - 1, carro.getPreco()));
		}

		return carro;
	}

	private int encontrarIndiceDoCarroPorNomeOuRenavam(String nomeOuRenavamCarro) {
		carros = DAO.lerArquivo();
		for (int i = 0; i < carros.size(); i++) {
			if (carros.get(i).getNome().equals(nomeOuRenavamCarro)
					|| carros.get(i).getRenavan().equals(nomeOuRenavamCarro)) {
				return i;
			}
		}

		return -1;
	}

	private int encontrarIndiceDoCarroComparandoTudo(Carro carro) {
		carros = DAO.lerArquivo();
		for (int i = 0; i < carros.size(); i++) {
			if (carros.get(i).getNome().equals(carro.getNome()) && carros.get(i).getRenavan().equals(carro.getRenavan())
					&& carros.get(i).getCategoria().getClass().equals(carro.getCategoria().getClass())
					&& carros.get(i).getAnoFabricacao() == carro.getAnoFabricacao()
					&& carros.get(i).getQuantidadeDisponivel() == carro.getQuantidadeDisponivel()
					&& carros.get(i).getPreco() == carro.getPreco()) {
				return i;
			}
		}

		return -1;
	}

	public static Usuario autenticarUsuario(String login, String senha) {
		for (Usuario usuario : usuariosCadastrados) {
			if (usuario.getNome().equals(login) && usuario.getSenha().equals(senha)) {
				return usuario;
			}
		}

		return null;
	}

}
