package prova3.armazenamento;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;

import prova3.loja.Carro;

public class DAO {

	private static final String nomeArquivo = "src/prova3/armazenamento/carros.obj";

	public static void escreverArquivo(List<Carro> carros) {
		try {
			FileOutputStream fos = new FileOutputStream(nomeArquivo);
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(carros);
			oos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	public static List<Carro> lerArquivo() {
		List<Carro> carros = null;
		try {
			FileInputStream fis = new FileInputStream(nomeArquivo);
			try (ObjectInputStream ois = new ObjectInputStream(fis)) {
				carros = (List<Carro>) ois.readObject();
			}
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}

		return carros;
	}

}
