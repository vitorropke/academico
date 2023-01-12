Alterações

parser.cpp

	Linha 113: // agora o salto de linha é um token e o final da entrada
	Linha 115 foi para 114: if (lookahead->tag != '\n')
	Linha 121: cout << "\nTradução bem sucedida";

lexer.cpp

	Linha 27: // ignora espaços em branco e tabulações. Retorna token quando tem nova linha '\n'
	Linhas 33 até 38: 

			// quebra de linha
			Token eol {'\n'};

			// retorna o token do '\n'
			token.t = eol;
			return &token.t;
