package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;

import br.edu.ufersa.ropke.locadoramaven.exception.FoundException;
import br.edu.ufersa.ropke.locadoramaven.exception.IncorrectPasswordException;
import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.exception.NotFoundException;
import br.edu.ufersa.ropke.locadoramaven.exception.UserNotFoundException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.UsuarioDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.UsuarioVO;

public abstract class UsuarioBO<VO extends UsuarioVO> extends PessoaBO<VO> {
	private UsuarioDAO<VO> usuarioDAO = new UsuarioDAO<VO>();

	@Override
	public boolean isNull(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if ((usuario != null) && (arquivo != null)) {
			// Verifica se parâmetros importantes não são nulos
			if ((usuario.getLogin() != null) && (usuario.getSenha() != null)) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	@Override
	public void cadastrar(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			if (usuarioDAO.pesquisarLogin(usuario, arquivo) == null) {
				super.cadastrar(usuario, arquivo);
			} else {
				throw new FoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void alterar(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			if (usuarioDAO.pesquisarLogin(usuario, arquivo) != null) {
				super.alterar(usuario, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public void deletar(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			if (usuarioDAO.pesquisarLogin(usuario, arquivo) != null) {
				super.deletar(usuario, arquivo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	@Override
	public VO pesquisar(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			return super.pesquisar(usuario, arquivo);
		} else {
			return null;
		}
	}

	public VO pesquisarLogin(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			return usuarioDAO.pesquisarLogin(usuario, arquivo);
		} else {
			return null;
		}
	}

	public boolean autenticar(VO usuario, File arquivo) {
		// Verifica se a entrada de argumentos não é nula
		if (!isNull(usuario, arquivo)) {
			VO usuarioEncontrado = usuarioDAO.pesquisarLogin(usuario, arquivo);

			// Vê se o login foi encontrado
			if (usuarioEncontrado == null) {
				throw new UserNotFoundException();
			} else if (usuarioEncontrado.getSenha().equals(usuario.getSenha())) {
				// Verifica se a senha está correta
				return true;
			} else {
				throw new IncorrectPasswordException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}
}
