class Cliente {
	// Variáveis
	private String nome, cpf, endereco, email, telefone;
	private Livro livro[];
	private Disco disco[];

	// Getters e Setters
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if (nome != null && nome != "") {
			this.nome = nome;
		} else {
			System.out.println("Nome nao pode ser vazio!");
		}
	}
	
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		if (cpf != null && cpf != "") {
			this.cpf = cpf;
		} else {
			System.out.println("CPF nao pode ser vazio!");
		}
	}

	public String getEndereco() {
		return endereco;
	}
	public void setEndereco(String endereco) {
		if (endereco != null && endereco != "") {
			this.endereco = endereco;
		} else {
			System.out.println("Endereco nao pode ser vazio!");
		}
	}
	
	public String getEmail() {
		return email;
	}
	public void setcpf(String email) {
		if (email != null && email != "") {
			this.email = email;
		} else {
			System.out.println("Email nao pode ser vazio!");
		}
	}

	public String getTelefone() {
		return telefone;
	}
	public void setTelefone(String telefone) {
		if (telefone != null && telefone != "") {
			this.telefone = telefone;
		} else {
			System.out.println("Telefone nao pode ser vazio!");
		}
	}

	/*
	public Livro[] getLivro() {
		Livro[] livro = new Livro[this.livro.length()];



		return livro;
	}
	public void setLivro(Livro[] livro) {
		for (int x = 0; x < livro.lenth(); x++) {
			this.livro[x] = livro[x];
		}
	}

	public Disco[] getDisco() {
		Livro[] disco = new Livro[this.disco.length()];



		return disco;
	}
	public void setDisco(Livro[] disco) {
		for (int x = 0; x < disco.lenth(); x++) {
			this.disco[x] = disco[x];
		}
	}
	*/

	/*
	// Métodos
	public void cadastrar(Cliente cliente) {
		// adiciona o cliente ao "banco de dados"
	}
	
	public void alterar(Cliente cliente) {
		// altera os atributos do cliente no "banco de dados"
	}
	
	public void deletar(Cliente cliente) {
		// apaga o cliente do "banco de dados"
		
		cliente.nome = null;
		cliente.cpf = null;
		cliente.endereco = null;
		cliente.email = null;
		cliente.telefone = null;
		cliente.livro[] = null;
		cliente.disco[] = null;
	}

	public Cliente[] pesquisarNome(String nome) {
		return Cliente;
	}
	
	public Cliente pesquisarCpf(String cpf) {
		return Cliente;
	}
	*/
}
