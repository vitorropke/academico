class Gerente {
	// Variáveis
	private String login, senha, nome, cpf, endereco, email, telefone;

	// Getters e Setters
	public String getLogin() {
		return login;
	}
	public void setLogin(String login) {
		if (login != null && login != "") {
			this.login = login;
		} else {
			System.out.println("Login nao pode ser vazio!");
		}
	}
	
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		if (senha != null && senha != "") {
			this.senha = senha;
		} else {
			System.out.println("Senha nao pode ser vazia!");
		}
	}
	
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

	// Métodos
	/*
	public void cadastrar(Gerente gerente) {
		// adiciona o gerente ao "banco de dados"
	}

	public void alterar(Gerente gerente) {
		// altera os atributos do gerente no "banco de dados"
	}

	public void deletar(Gerente gerente) {
		// remove o gerente do "banco de dados"
		gerente.login = null;
		gerente.senha = null;
		gerente.nome = null;
		gerente.cpf = null;
		gerente.endereco = null;
		gerente.email = null;
		gerente.telefone = null;
	}
	*/
}
