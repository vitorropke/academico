package prova3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;

import prova3.categorias.Categoria;
import prova3.loja.Carro;
import prova3.loja.Loja;
import prova3.servidores.*;

public class ServiceGateway {

	private static int servidorAtual = -1;
	private static Registry[] registros;
	private static Loja[] stub;

	public ServiceGateway() {
		if (stub == null) {
			registros = new Registry[3];
			stub = new Loja[3];

			String[] enderecos = { Servidor0.getEndereco(), Servidor1.getEndereco(), Servidor2.getEndereco() };
			int[] portas = { Servidor0.getPorta(), Servidor1.getPorta(), Servidor2.getPorta() };

			for (int i = 0; i < 3; i++) {
				boolean conectou = false;
				while (!conectou) {
					try {
						registros[i] = LocateRegistry.getRegistry(enderecos[i], portas[i]);
						stub[i] = (Loja) registros[i].lookup("Loja");
						conectou = true;
						System.out.println("Conectado!");
						System.out.println();
					} catch (Exception e) {
						System.err.println("Conectando ao servidor " + i);
						try {
							Thread.sleep(200);
						} catch (Exception e1) {
							e1.printStackTrace();
						}
					}
				}
			}
		}
	}

	public List<Carro> adicionarCarro(Carro carro) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].adicionarCarro(carro);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].adicionarCarro(carro);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public List<Carro> alterarCarro(Carro carroOriginal, Carro carroModificado) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].alterarCarro(carroOriginal, carroModificado);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].alterarCarro(carroOriginal, carroModificado);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public List<Carro> apagarCarro(String nomeOuRenavamCarro) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].apagarCarro(nomeOuRenavamCarro);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].apagarCarro(nomeOuRenavamCarro);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public List<Carro> listarCarros() {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				System.out.println();
				return stub[servidorAtual].listarCarros();
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].listarCarros();
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public List<Carro> listarCarrosPorCategoria(Categoria categoria) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].listarCarrosPorCategoria(categoria);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].listarCarrosPorCategoria(categoria);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public Carro pesquisarCarro(String nomeOuRenavamCarro) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].pesquisarCarro(nomeOuRenavamCarro);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].pesquisarCarro(nomeOuRenavamCarro);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public int exibirQuantidadeCarros() {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].exibirQuantidadeCarros();
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].exibirQuantidadeCarros();
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	public Carro comprarCarro(Carro carro) {
		while (true) {
			proximoServidor();
			try {
				System.out.println("Enviando requisicao para o servidor " + servidorAtual);
				return stub[servidorAtual].comprarCarro(carro);
			} catch (RemoteException e) {
				System.err.println("Servidor " + servidorAtual + " com problema! Tentando novamente!");
				System.out.println();
				try {
					reconectar();
					return stub[servidorAtual].comprarCarro(carro);
				} catch (Exception e1) {
					System.err.println("Nao foi possivel reconectar! Enviando requisicao para outro servidor!");
					System.out.println();
				}
			}
		}
	}

	private void proximoServidor() {
		servidorAtual++;
		if (servidorAtual == 3) {
			servidorAtual = 0;
		}
	}

	private void reconectar() throws Exception {
		Thread.sleep(200);
		stub[servidorAtual] = (Loja) registros[servidorAtual].lookup("Loja");
	}

}
