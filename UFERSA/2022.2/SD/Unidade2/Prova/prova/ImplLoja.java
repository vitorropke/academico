package prova;

import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import prova.categorias.*;

public class ImplLoja implements Loja {

	List<Carro> carros = new ArrayList<>(
			Arrays.asList(new Carro("Fiat Novo Uno", "19329025091", new Economico(), 2024, 5, 45000),
					new Carro("Chevrolet Onix", "12143350874", new Economico(), 2023, 15, 82490),
					new Carro("Ford Ka", "82631490820", new Economico(), 2016, 8, 51990),

					new Carro("Ford Ka Sedan", "01342773028", new Intermediario(), 2021, 7, 49000),
					new Carro("Chevrolet Onix Plus", "07562383139", new Intermediario(), 2019, 3, 87590),
					new Carro("Hyundai HB20S", "33444810737", new Intermediario(), 2023, 4, 88790),

					new Carro("Toyota Corolla", "17171554803", new Executivo(), 2023, 2, 146890),
					new Carro("Honda Civic", "36378745710", new Executivo(), 2018, 1, 244900),
					new Carro("Chevrolet Cruze", "30785277872", new Executivo(), 2023, 4, 148650)));

	@Override
	public List<Carro> adicionarCarro(Carro carro) throws RemoteException {
		carros.add(carro);

		return listarCarros();
	}

	@Override
	public List<Carro> listarCarros() throws RemoteException {
		// ordena os carros pelo nome
		Collections.sort(carros);

		return carros;
	}

	@Override
	public List<Carro> listarCarrosPorCategoria(Categoria categoriaCarro) throws RemoteException {
		List<Carro> carrosFiltrados = carros.stream()
				.filter(carro -> carro.getCategoria().getClass().equals(categoriaCarro.getClass()))
				.collect(Collectors.toList());

		// ordena os carros pelo nome
		Collections.sort(carrosFiltrados);

		return carrosFiltrados;
	}

	@Override
	public List<Carro> alterarCarro(Carro carroOriginal, Carro carroModificado) throws RemoteException {
		carros.set(encontrarIndiceDoCarroComparandoTudo(carroOriginal), carroModificado);

		return listarCarros();
	}

	@Override
	public List<Carro> apagarCarro(String nomeCarro) throws RemoteException {
		int indiceCarro = encontrarIndiceDoCarroPorNomeOuRenavam(nomeCarro);
		if (indiceCarro != -1) {
			carros.remove(indiceCarro);
		} else {
			return null;
		}

		return listarCarros();
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
		for (int i = 0; i < carros.size(); i++) {
			if (carros.get(i).getNome().equals(nomeOuRenavamCarro)
					|| carros.get(i).getRenavan().equals(nomeOuRenavamCarro)) {
				return i;
			}
		}

		return -1;
	}

	private int encontrarIndiceDoCarroComparandoTudo(Carro carro) {
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

}
