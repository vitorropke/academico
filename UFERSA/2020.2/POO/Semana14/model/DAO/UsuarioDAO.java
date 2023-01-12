package br.edu.ufersa.ropke.locadoramaven.model.DAO;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import br.edu.ufersa.ropke.locadoramaven.model.VO.UsuarioVO;

public class UsuarioDAO<VO extends UsuarioVO> extends PessoaDAO<VO> {
	@SuppressWarnings("unchecked")
	public VO pesquisarLogin(VO usuario, File arquivo) {
		try {
			if (arquivo.exists() && arquivo.isFile() && arquivo.canRead()) {
				FileInputStream arquivoLeitura = new FileInputStream(arquivo);
				ObjectInputStream objetoLeitura;
				VO usuarioLeitura;

				while (arquivoLeitura.available() > 0) {
					// Classe responsável por recuperar os usuários do arquivo
					objetoLeitura = new ObjectInputStream(arquivoLeitura);

					usuarioLeitura = (VO) objetoLeitura.readObject();

					// Retorna o usuário quando obter o mesmo login
					if (usuarioLeitura.getLogin().equals(usuario.getLogin())) {
						arquivoLeitura.close();
						objetoLeitura.close();
						return usuarioLeitura;
					}
				}

				arquivoLeitura.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Usuario nao encontrado");
		return null;
	}
}
