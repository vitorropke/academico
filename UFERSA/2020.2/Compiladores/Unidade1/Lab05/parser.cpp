#include "parser.h"
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

void Parser::Expr()
{
	// expr -> + expr expr { print(+) }
	if (lookahead == '+')
	{
		Match('+');
		Expr();
		Expr();
		cout << '+';
	}
	// expr -> - expr expr { print(-) }
	else if (lookahead == '-')
	{
		Match('-');
		Expr();
		Expr();
		cout << '-';
	}
	// expr -> term
	else if (isdigit(lookahead))
	{
		Term();
	}
	// produção vazia
	else return;
}

void Parser::Term()
{
	cout << lookahead;
	Match(lookahead);
}

void Parser::Match(char t)
{
	if (t == lookahead)
		lookahead = cin.get();
	else
		throw SyntaxError{};
}

Parser::Parser()
{
	lookahead = 0; 
}

void Parser::Start()
{
	lookahead = cin.get();
	Expr();
	if (lookahead != '\n')
		throw SyntaxError{};
}