#include <iostream>
#include "error.h"
#include "parser.h"

using std::cout;

void Parser::Program()
{
	// program -> math
	if (!Match(Tag::MATH))
	{
		throw SyntaxError(scanner.Lineno(), "\'math' esperado");
	}

	// program -> block
	Block();
}

void Parser::Block()
{
	// block -> { decls stmts }
	if (!Match('{'))
	{
		throw SyntaxError(scanner.Lineno(), "\'{\' esperado");
	}

	// nova tabela de símbolos para o bloco
	// ------------------------------------
	SymTable * saved = symtable;
	symtable = new SymTable(symtable);
	// ------------------------------------

	Decls();
	Stmts();
	
	if (!Match('}'))
	{
		throw SyntaxError(scanner.Lineno(), "\'}\' esperado");
	}
	
	// tabela do escopo envolvente volta a ser a tabela ativa
	// ------------------------------------------------------
	delete symtable;
	symtable = saved;
	// ------------------------------------------------------
}

void Parser::Decls()
{
	// decls -> decl decls
	//        | empty
	// decl  -> type id;

	while (lookahead->tag == Tag::TYPE)
	{
		string type {lookahead->toString()};
		Match(Tag::TYPE);

		string name {lookahead->toString()};
		Match(Tag::ID);

		Symbol s { name, type };
		
		// insere variável na tabela de símbolos
		if(!symtable->Insert(name, s))
		{
			// a inserção falha quando a variável já está na tabela
			stringstream ss;
			ss << "variável \"" << name << "\" já definida";
			throw SyntaxError(scanner.Lineno(), ss.str());
		}

		if(!Match(';'))
		{
			stringstream ss;
			ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
			throw SyntaxError { scanner.Lineno(), "esperado ;" };
		}
	}
}

void Parser::Stmts()
{
	// stmts -> stmt stmts
	//        | empty
	// stmt  -> block
	//        | expr;
	
	while(true)
	{
		switch(lookahead->tag)
		{
			// stmt -> block
			case '{':
				Block();
				break;
			// stmt -> expr; { print('\n') }
			case '(':
				Expr();
				if(!Match(';'))
				{
					stringstream ss;
					ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
					throw SyntaxError { scanner.Lineno(), ss.str() };
				}
				cout << '\n';
				break;
			// stmt -> expr; { print('\n') }
			case Tag::ID:
				Expr();
				if(!Match(';'))
				{
					stringstream ss;
					ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
					throw SyntaxError { scanner.Lineno(), ss.str() };
				}
				cout << '\n';
				break;
			// stmt -> expr; { print('\n') }
			case Tag::NUM:
				Expr();
				if(!Match(';'))
				{
					stringstream ss;
					ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
					throw SyntaxError { scanner.Lineno(), ss.str() };
				}
				cout << '\n';
				break;
			// stmts -> empty
			default: return;
		}
	}
}

void Parser::Expr()
{
	// expr -> term add
	Term();
	while (true)
	{
		// add -> + term { print('+') } add
		if (lookahead->tag == '+')
		{
			Match('+');
			Term();
			cout << '+';
		}
		// add -> - term { print('-') } add
		else if (lookahead->tag == '-')
		{
			Match('-');
			Term();
			cout << '-';
		}
		// add -> empty
		else return;
	}
}

void Parser::Term()
{
	// term -> factor mult
	Factor();
	while (true)
	{
		// mult -> * factor { print('*') } mult
		if (lookahead->tag == '*')
		{
			Match('*');
			Factor();
			cout << '*';
		} 
		// mult -> / factor { print('/') } mult
		else if (lookahead->tag == '/')
		{
			Match('/');
			Factor();
			cout << '/';
		}
		// mult -> empty
		else return;
	}
}

void Parser::Factor()
{
	// factor -> (expr)
    if (lookahead->tag == '(')
    {
        Match('(');
        Expr();
        if(!Match(')'))
            throw SyntaxError{ scanner.Lineno(), "\')\' esperado" };
    }
	// factor -> { print('(') } id { print(')') }
	else if (lookahead->tag == Tag::ID)
	{
		// verifica tipo da variável na tabela de símbolos
		Symbol * s = symtable->Find(lookahead->toString());
		if (!s)
		{
			stringstream ss;
			ss << "variável \"" << lookahead->toString() << "\" não declarada";
			throw SyntaxError{ scanner.Lineno(), ss.str() };
		}
		cout << '(' << s->var << ':' << s->type << ')';
		Match(Tag::ID);
	}
	// factor -> { print('(') } num { print(')') }
	else if (lookahead->tag == Tag::NUM)
	{
		cout << '(' << lookahead->toString() << ')';
		
		Match(Tag::NUM);
	}
	else
	{
		stringstream ss;
		ss << '\'' << lookahead->toString() << "\' inválido na expressão";
		throw SyntaxError{ scanner.Lineno(), ss.str() };
	}
}

bool Parser::Match(int tag)
{
	if (tag == lookahead->tag)
	{
		lookahead = scanner.Scan();
		return true;
	}

	return false;
}

Parser::Parser()
{
	lookahead = scanner.Scan();
	symtable = nullptr; 
}

void Parser::Start()
{
	Program();
}
