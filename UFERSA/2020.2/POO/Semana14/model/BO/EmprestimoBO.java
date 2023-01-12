package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.util.ArrayList;
import java.util.Calendar;

import br.edu.ufersa.ropke.locadoramaven.exception.InvalidParameterException;
import br.edu.ufersa.ropke.locadoramaven.exception.NotFoundException;
import br.edu.ufersa.ropke.locadoramaven.exception.FoundException;
import br.edu.ufersa.ropke.locadoramaven.model.DAO.EmprestimoDAO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.ClienteVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestavelVO;
import br.edu.ufersa.ropke.locadoramaven.model.VO.EmprestimoVO;

public class EmprestimoBO {
	private EmprestimoDAO emprestimoDAO = new EmprestimoDAO();

	public boolean isNull(EmprestimoVO emprestimo) {
		// Verifica se a entrada de argumento não é nula
		if (emprestimo != null) {
			// Verifica se parâmetros importantes não são nulos nem inválidos
			if ((emprestimo.getCliente() != null) && (emprestimo.getDataEmprestimo() != null)) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	public void cadastrar(EmprestimoVO emprestimo) {
		// Verifica se a entrada de argumento não é nula
		if (!isNull(emprestimo)) {
			// Verifica se o emprestimo não existe no sistema
			if (emprestimoDAO.pesquisar(emprestimo) == null) {
				emprestimoDAO.cadastrar(emprestimo);
			} else {
				throw new FoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	public void alterar(EmprestimoVO emprestimo) {
		// Verifica se a entrada de argumento não é nula
		if (!isNull(emprestimo)) {
			// Verifica se o emprestimo existe no sistema
			if (emprestimoDAO.pesquisar(emprestimo) != null) {
				emprestimoDAO.alterar(emprestimo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	public void deletar(EmprestimoVO emprestimo) {
		// Verifica se a entrada de argumento não é nula
		if (!isNull(emprestimo)) {
			// Verifica se o emprestimo existe no sistema
			if (emprestimoDAO.pesquisar(emprestimo) != null) {
				emprestimoDAO.deletar(emprestimo);
			} else {
				throw new NotFoundException();
			}
		} else {
			throw new InvalidParameterException();
		}
	}

	public void pesquisar() {
		emprestimoDAO.pesquisar();
	}

	public EmprestimoVO pesquisar(EmprestimoVO emprestimo) {
		// Verifica se a entrada de argumento não é nula
		if (!isNull(emprestimo)) {
			return emprestimoDAO.pesquisar(emprestimo);
		} else {
			return null;
		}
	}

	public ArrayList<EmprestimoVO> listar() {
		return emprestimoDAO.listar();
	}

	public void alugar(EmprestimoVO emprestimo, ArrayList<Calendar> dataDevolucaoProposta,
			ArrayList<EmprestavelVO> emprestavel, ArrayList<Integer> quantidadeEmprestavelEmprestada) {
		// Verifica se os dados não são nulos/vazios
		if ((emprestimo != null) && (!dataDevolucaoProposta.isEmpty()) && (!emprestavel.isEmpty())
				&& (!quantidadeEmprestavelEmprestada.isEmpty())) {
			int numeroEmprestaveis = emprestavel.size();

			// Verifica se os vetores possuem o mesmo tamanho
			if ((numeroEmprestaveis == dataDevolucaoProposta.size())
					&& (numeroEmprestaveis == quantidadeEmprestavelEmprestada.size())) {
				Calendar dataAtual = Calendar.getInstance();

				// Inicializa vetores
				ArrayList<Calendar> datasDevolucao = new ArrayList<Calendar>();
				ArrayList<EmprestavelVO> emprestaveis = new ArrayList<EmprestavelVO>();
				ArrayList<Integer> quantidadesEmprestavel = new ArrayList<Integer>();

				// Percorre os emprestaveis
				for (int x = 0; x < numeroEmprestaveis; x++) {
					// Verifica se o emprestavel, data e quantidade não são nulos
					if ((emprestavel.get(x) != null) && (dataDevolucaoProposta.get(x) != null)
							&& (quantidadeEmprestavelEmprestada.get(x) != null)) {
						// Verifica se existe quantidade de emprestavel proposta suficiente para ser
						// emprestado
						if (emprestavel.get(x).getNumeroExemplares() >= quantidadeEmprestavelEmprestada.get(x)) {
							// Verifica se a data de devolução proposta não é no passado
							if (dataDevolucaoProposta.get(x).after(dataAtual)) {
								// Verifica se a quantidade de emprestavel proposta é maior que 0
								if (quantidadeEmprestavelEmprestada.get(x) > 0) {
									datasDevolucao.add(dataDevolucaoProposta.get(x));
									emprestaveis.add(emprestavel.get(x));
									quantidadesEmprestavel.add(quantidadeEmprestavelEmprestada.get(x));

									// Atualiza alguns atributos do emprestavel
									// Número de exemplares
									emprestavel.get(x).setNumeroExemplares(emprestavel.get(x).getNumeroExemplares()
											- quantidadeEmprestavelEmprestada.get(x));
									// Número de empréstimos
									emprestavel.get(x)
											.setNumeroEmprestimos(emprestavel.get(x).getNumeroEmprestimos() + 1);

									// Atualiza o faturamento
									EmprestimoVO.setFaturamento(
											EmprestimoVO.getFaturamento() + (emprestavel.get(x).getValorAluguel()
													* quantidadeEmprestavelEmprestada.get(x)));
								} else {
									System.out.println("Quantidade proposta do emprestavel \""
											+ emprestavel.get(x).getTitulo() + "\" nao pode ser menor que 1!\n");
								}
							} else {
								System.out.println("Data de devolucao do emprestavel \""
										+ emprestavel.get(x).getTitulo() + "\" nao pode ser no passado!\n");
							}
						} else {
							System.out.println("Emprestavel \"" + emprestavel.get(x).getTitulo()
									+ "\" nao possui quantidade suficiente! Temos apenas "
									+ emprestavel.get(x).getNumeroExemplares() + " unidades desse emprestavel!\n");
						}
					} else {
						System.out.println("Emprestavel, data ou quantidade  nao podem ser nulos!\n");
					}
				}

				// Insere somente emprestáveis válidos
				if (!emprestaveis.isEmpty()) {
					emprestimo.setDataDevolucaoEmprestavel(datasDevolucao);
					emprestimo.setEmprestavel(emprestaveis);
					emprestimo.setQuantidadeEmprestavel(quantidadesEmprestavel);
				} else {
					System.out.println("Sem emprestaveis validos!");
				}
			} else {
				System.out.println("Vetores possuem tamanhos diferentes!");
			}
		} else {
			System.out.println("Alguns valores sao vazios!");
		}
	}

	public void devolver(EmprestimoVO emprestimo, ArrayList<EmprestavelVO> emprestavel,
			ArrayList<Integer> quantidadeDevolucaoEmprestavel) {
		// Verifica se os dados não são nulos/vazios
		if ((emprestimo != null) && (!emprestavel.isEmpty() && (!quantidadeDevolucaoEmprestavel.isEmpty()))) {
			int numeroEmprestaveis = emprestavel.size();
			Calendar dataAtual = Calendar.getInstance();

			// Verifica se os vetores possuem o mesmo tamanho
			if (numeroEmprestaveis == quantidadeDevolucaoEmprestavel.size()) {
				// Insere os atributos que já existem no empréstimo
				ArrayList<Calendar> datasDevolucao = emprestimo.getDataDevolucaoEmprestavel();
				ArrayList<EmprestavelVO> emprestaveis = emprestimo.getEmprestavel();
				ArrayList<Integer> quantidadesEmprestavel = emprestimo.getQuantidadeEmprestavel();

				int posicaoEmprestavel = -1;
				int quantidadeEmprestaveisQueSobrou;
				int adicionaisMonetarios;
				int diferencaDias;
				int quantidadeEmprestavelEmprestadoAnteriormente;
				long diferencaMilissegundos;
				Calendar dataDevolucaoEmprestavelEmprestadoAnteriormente;
				// Percorre os emprestaveis
				for (int x = 0; x < numeroEmprestaveis; x++) {
					// Verifica se o emprestavel e a data de devolução não são nulos
					if ((emprestavel.get(x) != null) && (quantidadeDevolucaoEmprestavel.get(x) != null)) {
						if (quantidadeDevolucaoEmprestavel.get(x) >= 1) {
							// Obtém a posição do emprestável no vetor de emprestaveis
							for (int i = 0; i < numeroEmprestaveis; i++) {
								if (emprestaveis.get(i).getTitulo().equals(emprestavel.get(x).getTitulo())) {
									posicaoEmprestavel = i;
									break;
								}
							}

							// Faz as modificações quando alguma posição é encontrada
							if (posicaoEmprestavel == -1) {
								System.out.println("Emprestavel nao emprestado anteriormente!");
							} else {
								quantidadeEmprestavelEmprestadoAnteriormente = quantidadesEmprestavel
										.get(posicaoEmprestavel);
								dataDevolucaoEmprestavelEmprestadoAnteriormente = datasDevolucao
										.get(posicaoEmprestavel);

								// Verifica se a quantidade a ser devolvida é menor ou igual a quantidade de
								// emprestaveis que foram emprestados anteriormente
								if (quantidadeDevolucaoEmprestavel
										.get(x) <= quantidadeEmprestavelEmprestadoAnteriormente) {
									// Repõe o emprestável
									emprestavel.get(x).setNumeroExemplares(emprestavel.get(x).getNumeroExemplares()
											+ quantidadeDevolucaoEmprestavel.get(x));

									// Obtém a quantidade de emprestaveis que sobrou após a devolução
									quantidadeEmprestaveisQueSobrou = quantidadesEmprestavel.get(posicaoEmprestavel)
											- quantidadeDevolucaoEmprestavel.get(x);

									// Se sobraram emprestáveis então atualiza a quantidade no vetor de quantidades
									if (quantidadeEmprestaveisQueSobrou != 0) {
										quantidadesEmprestavel.set(posicaoEmprestavel, quantidadeEmprestaveisQueSobrou);
									} else {
										// Se não sobraram emprestáveis então remove essa posição dos vetores
										datasDevolucao.remove(posicaoEmprestavel);
										emprestaveis.remove(posicaoEmprestavel);
										quantidadesEmprestavel.remove(posicaoEmprestavel);
									}

									// Cálculo de adicionais e multa se existirem
									adicionaisMonetarios = 0;
									// A cada 10 dias de empréstimo há um adicional de 2% do valor de empréstimo do
									// emprestável no valor final

									// http://burnignorance.com/java-web-development-tips/calculating-difference-between-two-dates-using-java/
									diferencaMilissegundos = 0;
									diferencaDias = 0;

									// Get the difference between two dates in milliseconds
									// diferença entre data de empréstimo e data de devolução
									diferencaMilissegundos = dataAtual.getTimeInMillis()
											- emprestimo.getDataEmprestimo().getTimeInMillis();

									// Get difference between two dates in days
									diferencaDias = (int) diferencaMilissegundos / (24 * 60 * 60 * 1000);

									// Adiciona os dias no atributo do emprestavel, dias alugado
									emprestavel.get(x).setNumeroDiasAlugado(
											emprestavel.get(x).getNumeroDiasAlugado() + diferencaDias);

									// Calcula os ciclos de 10 dias de empréstimo
									adicionaisMonetarios = (int) (diferencaDias) / 10;

									// Atualiza o faturamento com os adicionais
									EmprestimoVO.setFaturamento(EmprestimoVO.getFaturamento()
											+ (emprestavel.get(x).getValorAluguel() * adicionaisMonetarios * 0.02f));

									// Verifica se há multa
									// A data de devolução efetiva ocorre depois da data de devolução proposta
									if (dataAtual.after(dataDevolucaoEmprestavelEmprestadoAnteriormente)) {
										// A multa será de 5% do valor de empréstimo do emprestavel e se repetirá a
										// cada 3 dias até a data de devolução

										adicionaisMonetarios = 0;

										// difereça entre o dia de devolução proposto e o dia de devolução atual
										diferencaMilissegundos = dataAtual.getTimeInMillis()
												- dataDevolucaoEmprestavelEmprestadoAnteriormente.getTimeInMillis();

										// Get difference between two dates in days
										diferencaDias = (int) diferencaMilissegundos / (24 * 60 * 60 * 1000);

										// Calcula os ciclos de 3 dias de multa
										adicionaisMonetarios = (int) (diferencaDias) / 3;

										// Atualiza o faturamento com a multa
										EmprestimoVO.setFaturamento(
												EmprestimoVO.getFaturamento() + (emprestavel.get(x).getValorAluguel()
														* adicionaisMonetarios * 0.05f));
									}
								} else {
									System.out.println("Voce nao tem essa quantidade de emprestaveis para devolver\n");
								}
							}
						} else {
							System.out.println("Nao e possivel devolver 0 unidades do emprestavel!");
						}

					} else {
						System.out.println("Emprestavel nao pode ser nulo!\n");
					}
				}

				// Insere os emprestáveis que sobraram
				emprestimo.setDataDevolucaoEmprestavel(datasDevolucao);
				emprestimo.setEmprestavel(emprestaveis);
				emprestimo.setQuantidadeEmprestavel(quantidadesEmprestavel);
			} else {
				System.out.println("Vetores possuem tamanhos diferentes!");
			}
		} else {
			System.out.println("Alguns valores sao vazios!");
		}
	}

	public ArrayList<EmprestimoVO> gerarRelatorio(Calendar dataInicio, Calendar dataFim) {
		if ((dataInicio != null) && (dataFim != null)) {
			ArrayList<EmprestimoVO> emprestimos = emprestimoDAO.listar();
			ArrayList<EmprestimoVO> emprestimosValidos = new ArrayList<EmprestimoVO>();
			int numeroEmprestimos = emprestimos.size();

			// Obtém os empréstimos válidos
			for (int i = 0; i < numeroEmprestimos; i++) {
				if (emprestimos.get(i).getDataEmprestimo().after(dataInicio)
						&& emprestimos.get(i).getDataEmprestimo().before(dataFim)) {
					emprestimosValidos.add(emprestimos.get(i));
				}
			}

			return emprestimosValidos;
		}

		throw new InvalidParameterException();
	}

	public ArrayList<EmprestimoVO> gerarRelatorioCliente(ClienteVO cliente, Calendar dataInicio, Calendar dataFim) {
		if ((cliente != null) && (dataInicio != null) && (dataFim != null)) {
			ArrayList<EmprestimoVO> emprestimos = emprestimoDAO.listar();
			ArrayList<EmprestimoVO> emprestimosValidos = new ArrayList<EmprestimoVO>();
			int numeroEmprestimos = emprestimos.size();

			// Obtém os empréstimos válidos
			for (int i = 0; i < numeroEmprestimos; i++) {
				if (emprestimos.get(i).getCliente().getCpf().equals(cliente.getCpf())
						&& emprestimos.get(i).getDataEmprestimo().after(dataInicio)
						&& emprestimos.get(i).getDataEmprestimo().before(dataFim)) {
					emprestimosValidos.add(emprestimos.get(i));
				}
			}

			return emprestimosValidos;
		}

		throw new InvalidParameterException();
	}
}
