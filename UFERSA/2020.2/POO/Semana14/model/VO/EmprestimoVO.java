package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Calendar;

public class EmprestimoVO implements Serializable {
	private static final long serialVersionUID = 1L;

	// Variáveis
	private static long contadorId = 0;
	private static float faturamento = 0;
	private long idEmprestimo;
	private Calendar dataEmprestimo;
	private ArrayList<Calendar> dataDevolucaoEmprestavel = new ArrayList<Calendar>();
	private ArrayList<EmprestavelVO> emprestavel = new ArrayList<EmprestavelVO>();
	private ArrayList<Integer> quantidadeEmprestavel = new ArrayList<Integer>();
	private ClienteVO cliente;

	// Construtores
	public EmprestimoVO() {
		Calendar dataAtual = Calendar.getInstance();

		setIdEmprestimo(contadorId++);
		setDataEmprestimo(dataAtual);
	}

	// toString
	@Override
	public String toString() {
		String emprestimo = "";
		String faturamentoDoisDecimais = String.format("%.02f", faturamento);

		emprestimo = "\nId:\t\t\t\t" + idEmprestimo;
		emprestimo += "\nFaturamento:\t\t\tR$" + faturamentoDoisDecimais;
		emprestimo += "\nData de emprestimo:\t\t";

		if (dataEmprestimo != null) {
			emprestimo += dataEmprestimo.getTime();
		} else {
			emprestimo += "Nao definida";
		}

		emprestimo += "\n-----------------------------------------------------------------";
		emprestimo += "\nData de devolucao de emprestaveis:\n";

		if (!dataDevolucaoEmprestavel.isEmpty()) {
			int numeroDatasDevolucao = dataDevolucaoEmprestavel.size();

			for (int x = 0; x < numeroDatasDevolucao; x++) {
				emprestimo += "\t\t\t\t" + dataDevolucaoEmprestavel.get(x).getTime() + "\n";
			}
		} else {
			emprestimo += "\t\t\t\tSem emprestaveis\n";
		}

		emprestimo += "\n-----------------------------------------------------------------";
		emprestimo += "\nEmprestaveis:\n";

		if (!emprestavel.isEmpty()) {
			int numeroEmprestaveis = emprestavel.size();

			for (int x = 0; x < numeroEmprestaveis; x++) {
				emprestimo += emprestavel.get(x).toString();
				emprestimo += "\n-------------------------------";
			}
		} else {
			emprestimo += "\t\t\t\tSem emprestaveis\n";
		}

		emprestimo += "\n-----------------------------------------------------------------";
		emprestimo += "\nQuantidade do emprestavel:\n";

		if (!quantidadeEmprestavel.isEmpty()) {
			int numeroEmprestaveis = quantidadeEmprestavel.size();

			for (int x = 0; x < numeroEmprestaveis; x++) {
				emprestimo += "\t\t\t\t" + quantidadeEmprestavel.get(x) + "\n";
			}
		} else {
			emprestimo += "\t\t\t\tSem quantidades de emprestavel\n";
		}

		emprestimo += "\n-----------------------------------------------------------------";
		emprestimo += "\nCliente:\n";

		if (cliente != null) {
			emprestimo += cliente.toString();
		} else {
			emprestimo += "\t\t\t\tSem cliente\n";
		}

		return emprestimo;
	}

	// Getters e setters
	public static float getFaturamento() {
		return faturamento;
	}

	public static void setFaturamento(float faturamento) {
		if (faturamento >= 0) {
			EmprestimoVO.faturamento = faturamento;
		} else {
			System.out.println("Faturamento nao pode ser negativo!");
		}
	}

	public long getIdEmprestimo() {
		return idEmprestimo;
	}

	public void setIdEmprestimo(long idEmprestimo) {
		if (idEmprestimo < 0) {
			System.out.println("Id nao pode ser negativo!");
		} else {
			this.idEmprestimo = idEmprestimo;
		}
	}

	public Calendar getDataEmprestimo() {
		return dataEmprestimo;
	}

	public void setDataEmprestimo(Calendar dataEmprestimo) {
		if (dataEmprestimo != null) {
			// Obtêm a data atual
			Calendar dataAtual = Calendar.getInstance();

			if (dataEmprestimo.after(dataAtual)) {
				System.out.println("Data de emprestimo nao pode ser no futuro!");
			} else {
				this.dataEmprestimo = dataEmprestimo;
			}
		} else {
			System.out.println("Data de emprestimo nao pode ser vazia!");
		}
	}

	public ArrayList<Calendar> getDataDevolucaoEmprestavel() {
		return dataDevolucaoEmprestavel;
	}

	public void setDataDevolucaoEmprestavel(ArrayList<Calendar> dataDevolucaoEmprestavel) {
		if (!dataDevolucaoEmprestavel.isEmpty()) {
			// Obtêm a data atual
			Calendar dataAtual = Calendar.getInstance();
			ArrayList<Calendar> datasValidas = new ArrayList<Calendar>();
			int numeroDatasDevolucao = dataDevolucaoEmprestavel.size();

			// Insere somente datas válidas
			for (int x = 0; x < numeroDatasDevolucao; x++) {
				if ((dataDevolucaoEmprestavel.get(x) != null)) {
					if (dataDevolucaoEmprestavel.get(x).after(dataAtual)) {
						datasValidas.add(dataDevolucaoEmprestavel.get(x));
					} else {
						System.out.println("Data de devolucao so pode ser no futuro!");
					}
				} else {
					System.out.println("Data nao pode ser vazia!");
				}
			}

			// Se existirem datas válidas, adicione-as
			if (!datasValidas.isEmpty()) {
				this.dataDevolucaoEmprestavel = datasValidas;
			} else {
				System.out.println("Sem datas validas!");
			}
		} else {
			System.out.println("Datas de devolucao nao podem ser vazias!");
		}
	}

	public ArrayList<EmprestavelVO> getEmprestavel() {
		return emprestavel;
	}

	public void setEmprestavel(ArrayList<EmprestavelVO> emprestavel) {
		if (!emprestavel.isEmpty()) {
			ArrayList<EmprestavelVO> emprestaveisValidos = new ArrayList<EmprestavelVO>();
			int numeroEmpestaveisValidos = emprestavel.size();

			// Insere somente emprestáveis válidos
			for (int x = 0; x < numeroEmpestaveisValidos; x++) {
				if (emprestavel.get(x) != null) {
					emprestaveisValidos.add(emprestavel.get(x));
				} else {
					System.out.println("Emprestavel nao pode ser vazio!");
				}
			}

			// Se existirem emprestáveis válidos, adicione-os
			if (!emprestaveisValidos.isEmpty()) {
				this.emprestavel = emprestaveisValidos;
			} else {
				System.out.println("Sem emprestaveis validos!");
			}
		} else {
			System.out.println("Emprestaveis nao podem ser vazios!");
		}
	}

	public ArrayList<Integer> getQuantidadeEmprestavel() {
		return quantidadeEmprestavel;
	}

	public void setQuantidadeEmprestavel(ArrayList<Integer> quantidadeEmprestavel) {
		if (!quantidadeEmprestavel.isEmpty()) {
			ArrayList<Integer> quantidadesValidas = new ArrayList<Integer>();
			int numeroQuantidadesEmprestavel = quantidadeEmprestavel.size();

			// Insere somente quantidades válidas
			for (int x = 0; x < numeroQuantidadesEmprestavel; x++) {
				if (quantidadeEmprestavel.get(x) > 0) {
					quantidadesValidas.add(quantidadeEmprestavel.get(x));
				} else {
					System.out.println("Quantidade so pode ser maior que 0!");
				}
			}

			// Se existirem quantidades válidas, adicione-as
			if (!quantidadesValidas.isEmpty()) {
				this.quantidadeEmprestavel = quantidadesValidas;
			} else {
				System.out.println("Sem quantidades validas!");
			}
		} else {
			System.out.println("Quantidades nao podem ser vazias!");
		}
	}

	public ClienteVO getCliente() {
		return cliente;
	}

	public void setCliente(ClienteVO cliente) {
		if (cliente != null) {
			this.cliente = cliente;
		} else {
			System.out.println("Cliente nao pode ser vazio!");
		}
	}
}
