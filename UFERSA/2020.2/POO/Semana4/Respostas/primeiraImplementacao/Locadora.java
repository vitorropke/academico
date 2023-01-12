class Locadora {
	public static void main(String[] args) {
		Livro livro1 = new Livro();
		Disco disco1 = new Disco();
		Cliente cliente = new Cliente();
		Usuario usuario = new Usuario();
		Funcionario funcionario = new Funcionario();
		Gerente gerente = new Gerente();
		Emprestimo emprestimo = new Emprestimo();

		emprestimo.setFaturamento(10000000);
		System.out.println(emprestimo.getFaturamento());

		livro1.setTitulo("o chao");
		livro1.setGenero("romance");
		livro1.setAnoLancamento(2022);
		
		System.out.println(livro1.getTitulo());
		System.out.println(livro1.getGenero());

	}
}
