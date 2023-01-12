package br.edu.ufersa.ropke.locadoramaven.model.VO;

import java.io.Serializable;
import java.util.ArrayList;

public abstract class PessoaVO implements Serializable {
	private static final long serialVersionUID = 1L;

	// Variáveis
	private String nome;
	private String cpf;
	private ArrayList<String> endereco = new ArrayList<String>();
	private ArrayList<String> email = new ArrayList<String>();
	private ArrayList<String> telefone = new ArrayList<String>();

	// Construtores
	public PessoaVO() {
	}

	public PessoaVO(String nome, String cpf, ArrayList<String> endereco) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
	}

	public PessoaVO(String nome, String cpf, ArrayList<String> endereco, ArrayList<String> email) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
		setEmail(email);
	}

	public PessoaVO(String nome, String cpf, ArrayList<String> endereco, ArrayList<String> email,
			ArrayList<String> telefone) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
		setEmail(email);
		setTelefone(telefone);
	}

	// toString
	@Override
	public String toString() {
		String pessoa = "";

		pessoa = "\nNome:\t\t" + nome;
		pessoa += "\nCPF:\t\t" + cpf;
		pessoa += "\n----------------------------------------------";
		pessoa += "\nEnderecos:\n";

		if (!endereco.isEmpty()) {
			int numeroEnderecos = endereco.size();

			for (int x = 0; x < numeroEnderecos; x++) {
				pessoa += "\t\t" + endereco.get(x) + "\n";
			}
		} else {
			pessoa += "\t\tSem enderecos\n";
		}

		pessoa += "\n----------------------------------------------";
		pessoa += "\nEmails:\n";

		if (!email.isEmpty()) {
			int numeroEmails = email.size();

			for (int x = 0; x < numeroEmails; x++) {
				pessoa += "\t\t" + email.get(x) + "\n";
			}
		} else {
			pessoa += "\t\tSem emails\n";
		}

		pessoa += "\n----------------------------------------------";
		pessoa += "\nTelefones:\n";

		if (!telefone.isEmpty()) {
			int numeroTelefones = telefone.size();

			for (int x = 0; x < numeroTelefones; x++) {
				pessoa += "\t\t(";

				pessoa += telefone.get(x).substring(0, 2) + ") ";

				if (telefone.get(x).length() == 11) {
					pessoa += telefone.get(x).substring(2, 7);
					pessoa += '-' + telefone.get(x).substring(7, 11);
				} else {
					pessoa += telefone.get(x).substring(2, 6);
					pessoa += '-' + telefone.get(x).substring(6, 10);
				}

				pessoa += "\n";
			}
		} else {
			pessoa += "\t\tSem telefones\n";
		}

		return pessoa;
	}

	// Getters e setters
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if ((nome != null) && (!nome.isBlank())) {
			this.nome = nome;
		} else {
			System.out.println("Nome nao pode ser vazio!");
		}
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		if ((cpf != null) && (!cpf.isBlank())) {
			if ((cpf.length() >= 11) && (cpf.length() <= 14)) {
				// CPF deve ter tamanho entre 11 e 14
				if (cpf.length() > 11) {
					// Se o CPF tem mais de 11 dígitos
					cpf = cpf.replaceAll("\\D+", "");
					// Reduz o CPF, removendo tudo que não é dígito

					if (Validador.isCpf(cpf)) {
						// Verifica o CPF
						this.cpf = cpf;
					} else {
						System.out.println("CPF invalido!");
					}
				} else {
					// Se o CPF não tem mais de 11 dígitos vai para o verificador
					if (Validador.isCpf(cpf)) {
						// Verifica o CPF
						this.cpf = cpf;
					} else {
						System.out.println("CPF invalido!");
					}
				}
			} else {
				System.out.println("CPF invalido!");
			}
		} else {
			System.out.println("CPF nao pode ser vazio!");
		}
	}

	public ArrayList<String> getEndereco() {
		return endereco;
	}

	public void setEndereco(ArrayList<String> endereco) {
		if (!endereco.isEmpty()) {
			ArrayList<String> enderecosValidos = new ArrayList<String>();
			int numeroEnderecos = endereco.size();

			// Insere somente endereços válidos
			for (int x = 0; x < numeroEnderecos; x++) {
				if ((endereco.get(x) != null) && (!endereco.get(x).isBlank())) {
					enderecosValidos.add(endereco.get(x));
				} else {
					System.out.println("Endereco nao pode ser vazio!");
				}
			}

			// Se existirem endereços válidos, adicione-os
			if (!enderecosValidos.isEmpty()) {
				this.endereco = enderecosValidos;
			} else {
				System.out.println("Sem enderecos validos!");
			}
		} else {
			System.out.println("Enderecos nao podem ser vazios!");
		}
	}

	public ArrayList<String> getEmail() {
		return email;
	}

	public void setEmail(ArrayList<String> email) {
		if (!email.isEmpty()) {
			ArrayList<String> emailsValidos = new ArrayList<String>();
			int numeroEmails = email.size();

			// Insere somente emails válidos
			for (int x = 0; x < numeroEmails; x++) {
				if ((email.get(x) != null) && (!email.get(x).isBlank()) && Validador.isEmail(email.get(x))) {
					emailsValidos.add(email.get(x));
				} else {
					System.out.println("Email nao pode ser vazio!");
				}
			}

			// Se existirem emails válidos, adicione-os
			if (!emailsValidos.isEmpty()) {
				this.email = emailsValidos;
			} else {
				System.out.println("Sem emails validos!");
			}
		} else {
			System.out.println("Emails nao podem ser vazios!");
		}
	}

	public ArrayList<String> getTelefone() {
		return telefone;
	}

	public void setTelefone(ArrayList<String> telefone) {
		if (!telefone.isEmpty()) {
			ArrayList<String> telefonesValidos = new ArrayList<String>();
			String telefoneAtual;
			int numeroTelefones = telefone.size();

			// Insere somente telefones válidos
			for (int x = 0; x < numeroTelefones; x++) {
				if ((telefone.get(x) != null) && (!telefone.get(x).isBlank())) {
					telefoneAtual = Validador.telefoneValido(telefone.get(x));

					if (!telefoneAtual.isBlank()) {
						telefonesValidos.add(telefoneAtual);
					} else {
						System.out.println("Telefone invalido!");
					}
				} else {
					System.out.println("Telefone nao pode ser vazio!");
				}
			}

			// Se existirem telefones válidos, adicione-os
			if (!telefonesValidos.isEmpty()) {
				this.telefone = telefonesValidos;
			} else {
				System.out.println("Sem telefones validos!");
			}
		} else {
			System.out.println("Telefones nao podem ser vazios!");
		}
	}
}
