package prova3.loja;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

import prova3.categorias.Categoria;

public interface Loja extends Remote {

	List<Carro> adicionarCarro(Carro carro) throws RemoteException;

	List<Carro> alterarCarro(Carro carroOriginal, Carro carroModificado) throws RemoteException;

	List<Carro> apagarCarro(String nomeCarro) throws RemoteException;

	List<Carro> listarCarros() throws RemoteException;

	List<Carro> listarCarrosPorCategoria(Categoria categoriaCarro) throws RemoteException;

	Carro pesquisarCarro(String nomeOuRenavamCarro) throws RemoteException;

	int exibirQuantidadeCarros() throws RemoteException;

	Carro comprarCarro(Carro carro) throws RemoteException;

}
