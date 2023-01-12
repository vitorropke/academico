class Cliente {
	// Variáveis
	private String	nome;
	private String	cpf;
	private String	endereco;
	private String	email;
	private String	telefone;
	private Livro[]	livro;
	private Disco[]	disco;

	// Construtores
	public Cliente(String nome, String cpf, String endereco) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
	}
	public Cliente(String nome, String cpf, String endereco, String email) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
		setEmail(email);
	}
	public Cliente(String nome, String cpf, String endereco, String email,
			String telefone) {
		setNome(nome);
		setCpf(cpf);
		setEndereco(endereco);
		setEmail(email);
		setTelefone(telefone);
	}

	public String toString() {
		String cliente = "";

		cliente = "Nome:     " + nome;
		cliente += "\nCPF:      " + cpf;
		cliente += "\nEndereco: " + endereco;
		cliente += "\nEmail:    " + email;
		cliente += "\nTelefone: " + telefone;
		cliente += "\nLivro:    ";

		if (livro != null) {
			for (int x = 0; x < livro.length; x++) {
				cliente += "\n\n" + livro[x].toString();
			}
			cliente += "\n";
		} else {
			cliente += "Sem livros";
		}

		cliente += "\nDisco:    ";

		if (disco != null) {
			for (int x = 0; x < disco.length; x++) {
				cliente += "\n\n" + disco[x].toString();
			}
			cliente += "\n";
		} else {
			cliente += "Sem discos";
		}
		
		return cliente;
	}

	// Getters e Setters
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if ((nome != null) && (nome != "")) {
			this.nome = nome;
		} else {
			System.out.println("Nome nao pode ser vazio!");
		}
	}
	
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		if ((cpf != null) && (cpf != "")) {
			if ((cpf.length() >= 11) && (cpf.length() <= 14)) {
				// CPF deve ter tamanho entre 11 e 14
				if (cpf.length() > 11) {
					// Se o CPF tem mais de 11 dígitos
					cpf = cpf.replaceAll("\\D+","");
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

	public String getEndereco() {
		return endereco;
	}
	public void setEndereco(String endereco) {
		if ((endereco != null) && (endereco != "")) {
			this.endereco = endereco;
		} else {
			System.out.println("Endereco nao pode ser vazio!");
		}
	}
	
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		if ((email != null) && (email != "")) {
			if (Validador.isEmail(email)) {
				this.email = email;
			} else {
				System.out.println("Email invalido!");
			}
		} else {
			System.out.println("Email nao pode ser vazio!");
		}
	}

	public String getTelefone() {
		return telefone;
	}
	public void setTelefone(String telefone) {
		if ((telefone != null) && (telefone != "")) {
			if ((telefone.length() >= 10) && (telefone.length() <= 16)) {
				telefone = telefone.replaceAll("\\D+","");
				// Reduz o telefone, removendo tudo que não é dígito

				if (telefone.indexOf('0') == 0) {
					// Se o telefone possui o primeiro digito sendo 0
					telefone = telefone.substring(1);
					// Remove-se esse 0 no início

					if((telefone.length() == 10) || (telefone.length() == 11)) {
						// Se o telefone possui 10 ou 11 dígitos após a redução
						this.telefone = telefone;
					} else {
						System.out.println("Telefone invalido!");
					}
				} else {
					// Se o telefone não possui o primeiro digito sendo 0
					if((telefone.length() == 10) || (telefone.length() == 11)) {
						// Se o telefone possui 10 ou 11 dígitos após a redução
						this.telefone = telefone;
					} else {
						System.out.println("Telefone invalido!");
					}
				}
			} else {
				System.out.println("Telefone invalido!");
			}
		} else {
			System.out.println("Telefone nao pode ser vazio!");
		}
	}

	public Livro[] getLivro() {
		if (this.livro == null) {
			return null;
		}

		Livro[] livros = new Livro[this.livro.length];

		for (int x = 0; x < this.livro.length; x++) {
			livros[x] = this.livro[x];
		}

		return livros;
	}
	public void setLivro(Livro[] livro) {
		this.livro = livro;
	}
	
	public Disco[] getDisco() {
		if (this.disco == null) {
			return null;
		}

		Disco[] discos = new Disco[this.disco.length];

		for (int x = 0; x < this.disco.length; x++) {
			discos[x] = this.disco[x];
		}

		return discos;
	}
	public void setDisco(Disco[] disco) {
		this.disco = disco;
	}

	/*
	// Métodos
	public void cadastrar(Cliente cliente) {
		// adiciona o cliente ao "banco de dados"
	}
	
	public void alterar(Cliente cliente) {
		// altera os atributos do cliente no "banco de dados"
	}
	*/
	public void deletar(Cliente cliente) {
		// apaga o cliente do "banco de dados"
		
		cliente.nome = null;
		cliente.cpf = null;
		cliente.endereco = null;
		cliente.email = null;
		cliente.telefone = null;
		cliente.livro = null;
		cliente.disco = null;
	}
	/*
	public Cliente[] pesquisarNome(String nome) {
		return Cliente;
	}
	
	public Cliente pesquisarCpf(String cpf) {
		return Cliente;
	}
	*/
}
