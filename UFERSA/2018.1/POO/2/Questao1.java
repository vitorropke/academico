class Aluno{
	String nome;
	int idade;
	float altura;
	
	public Aluno(){
		
	}
	
	public Aluno(String nome, int idade, float altura){
		this.nome = nome;
		
		if(idade >= 0 && idade < 200){
			this.idade = idade;
		}
		else{
			this.idade = 0;
		}
		
		if(altura > 0 && altura < 3){
			this.altura = altura;
		}
		else{
			this.altura = 1;
		}
	}
	
	public void mostrarNome(){
		System.out.println("Nome: " + nome);
	}
	
	public void mostrarIdade(){
		System.out.println("Idade: " + idade + " anos");
	}
	
	public void mostrarAltura(){
		System.out.println("Altura: " + altura + " metros");
	}
	
	public String toString(){
		String saida;
		
		saida = "Nome: " + nome +
				"\nIdade: " + idade +
				"\nAltura: " + altura;
		
		return saida;
	}
}