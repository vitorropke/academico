a)
expr	-> 	+ expr expr { print('+') }
	|	- expr expr { print('-') }
	|	term

term	->	0 { print('0') }
	|	1 { print('1') }
	|	...
	|	9 { print('9') }
-------------------------------------------------------------------------------------------------------------

b) Sem necessidade de adequação
-------------------------------------------------------------------------------------------------------------

c) Não exatamente igual ao arquivo.
void expr()
{
	if( lookahead == '+' )
	{
		match('+'); expr(); expr();
	}
	else if( lookahead == '-' )
	{
		match('-'); expr(); expr();
	}
	else if( isdigit(lookahead) )
	{
		switch( lookahead )
		{
			case '0'; match( '0' ); break;
			case '1'; match( '1' ); break;
			case '2'; match( '2' ); break;
			case '3'; match( '3' ); break;
			case '4'; match( '4' ); break;
			case '5'; match( '5' ); break;
			case '6'; match( '6' ); break;
			case '7'; match( '7' ); break;
			case '8'; match( '8' ); break;
			case '9'; match( '9' ); break;
			default: print( "Syntax ERROR" );
		}
	}
}
-------------------------------------------------------------------------------------------------------------

d)
Mudanças feitas somente no arquivo 'parser.cpp', dentro de 'void Parser::Expr()' e 'void Parser::Term()':

Linhas referentes ao arquivo original, feito pelo professor.

Linha 10: '// expr -> term oper' removido.
Linha 11: 'Term();' removido.
Linhas 12, 13 e 30: 'while (true){}' removido.
Linha 14: '// oper -> + term { print(+) } oper' modificado para '// expr -> + expr expr { print(+) }'.
Linha 18: 'Term();' modificado para 'Expr();'.
Linha 19: 'Expr();' adicionado. 'cout << '+'' deslocado para a linha seguinte.
Linha 21: '// oper -> - term { print(-) } oper' modificado para '// expr -> - expr expr { print(-) }'
Linha 25: 'Term();' modificado para 'Expr();'.
Linha 26: 'Expr();' adicionado. 'cout << '-'' deslocado para a linha seguinte.
Linha 28:
'
// expr -> term
else if (isdigit(lookahead))
{
	Term();
}
' adicionado.
'// produção vazia' deslocado para linhas seguintes.
Linhas 35, 36 e 39: 'if (isdigit(lookahead)){}' removido.
Linhas 37 e 38: 'cout << lookahead;' > e 'Match(lookahead);' redução de uma tabulação em cada linha.
Linhas 40 e 41: 'else throw SyntaxError{};' removido.
