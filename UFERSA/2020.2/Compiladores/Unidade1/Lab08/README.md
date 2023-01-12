Alterações

lexer.cpp
	Add Linha 15: id_table["float"] = Id{ Tag::TYPE, "float" };
	Add Linha 52 até 85:

		// se detectar um ponto então pode ser float
		if (peek == '.')
		{
			peek = fin.get();

			// garante que existe um dígito após o ponto
			if (isdigit(peek))
			{
				float f = 0;
				int digit = 0;
				
				while (isdigit(peek))
				{
					// converte caractere 'n' para o dígito numérico n
					int n = peek - '0';
					f = 10 * f + n;
					digit++;
					peek = fin.get();
				}
				
				// desloca a vírgula para esquerda até ficar no formato 0.x
				// e soma com a parte inteira
				f = f * 1 / (10 * digit);
				f = v + f;

				// retorna o token NUM
				token.n = Num{f};
				return &token.n;
			}
			else
			{
				peek = '.';
			}
		}

lexer.h
	Modificado Linha 23: float value;
	Add Linha 26: Num(float v) : Token(Tag::NUM), value(v) {}

parser.cpp
	Add Linha 107 até 116:
		// stmt -> fact;
		case Tag::NUM:
			Fact();
			if(!Match(';'))
			{
				stringstream ss;
				ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
				throw SyntaxError { scanner.Lineno(), ss.str() };
			} 
			break;
	
	Add Linha 140 até 160:
		// fact -> num
		else if (lookahead->tag == Tag::NUM)
		{
			cout << lookahead->toString() << ':';

			/*
				Gambiarra aqui porque não consegui passar o tipo através de parâmetro
				nem por tabela de símbolos
			*/
			// Verifica se a string possui um ponto. Se tiver é um 'float', senão é um 'int'.
			if (lookahead->toString().find('.') != std::string::npos)
			{
				cout << "float; ";
			}
			else
			{
				cout << "int; ";
			}

			Match(Tag::NUM);
		}
