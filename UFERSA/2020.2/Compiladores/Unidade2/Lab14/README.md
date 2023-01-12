lexer.l

		Linha 13: id	    (_)*{letra}({letra}|{digito}|(_))*
	Add	Linha 15: string	(\")({id}|{num}|{barras})*(\")
	Add	Linha 16: barras	(((\\)(\\))|((\\)(\")))*
	Add	Linha 23: while	return WHILE;
	Add	Linha 26: {string}	return STRING;
		Linha 29: "=="	return RELOP; 
		Linha 30: "!="	return RELOP; 

tokens.h

	Linha 2: enum {IF=1, THEN, ELSE, WHILE, STRING, ID, NUM, RELOP}; 

parser.cpp

	Add	Linha 17: case WHILE: cout << "WHILE\n"; break;
	Add Linha 21 até 44:
	
		case STRING:
			std::string texto = scanner.YYText();
			int tamanhoTexto = texto.size();

			cout << "STRING: ";

			for (int i = 1; i < tamanhoTexto - 1; i++) {
				if ((texto.at(i) == '\\') && (texto.at(i + 1) == '\\'))
				{
					cout << '\\';
					i+=1;
				} 
				else if ((texto.at(i) == '\\') && (texto.at(i + 1) == '\"'))
				{
					cout << '\"';
					i+=1;
				}
				else
				{
					cout << texto.at(i);
				}
			}

			cout << "\n"; break;

