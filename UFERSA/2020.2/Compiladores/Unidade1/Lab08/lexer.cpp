#include "lexer.h"
#include <fstream>
#include <sstream>
using std::stringstream;

extern std::ifstream fin;

// construtor 
Lexer::Lexer()
{
	// insere palavras-reservadas na tabela de id's
	id_table["int"] = Id{ Tag::TYPE, "int" };
	id_table["char"] = Id{ Tag::TYPE, "char" };
	id_table["bool"] = Id{ Tag::TYPE, "bool" };
	id_table["float"] = Id{ Tag::TYPE, "float" };

	// inicia leitura da entrada
	peek = fin.get();
}

// retorna número da linha atual
int Lexer::Lineno()
{
	return line;
}

// retorna tokens para o analisador sintático
Token * Lexer::Scan()
{
	// ignora espaços em branco, tabulações e novas linhas
	while (isspace(peek))
	{
		if (peek == '\n')
			line += 1;
		peek = fin.get();
	}

	// retorna números
	if (isdigit(peek))
	{
		int v = 0;

		do
		{
			// converte caractere 'n' para o dígito numérico n
			int n = peek - '0';
			v = 10 * v + n;
			peek = fin.get();
		}
 		while (isdigit(peek));
		
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
		
		// retorna o token NUM
		token.n = Num{v};
		return &token.n;
	}

	// retorna palavras-chave e identificadores
	if (isalpha(peek))
	{
		stringstream ss;
		do 
		{
			ss << peek;
			peek = fin.get();
		} 
		while (isalpha(peek));

		string s = ss.str();
		auto pos = id_table.find(s);

		// se o lexema já está na tabela
		if (pos != id_table.end())
		{
			// retorna o token associado
			token.i = pos->second;
			return &token.i;
		}

		// se o lexema ainda não está na tabela
		Id new_id {Tag::ID, s};
		id_table[s] = new_id;

		// retorna o token ID
		token.i = new_id;
		return &token.i;
	}

	// operadores (e caracteres não alphanuméricos isolados)
	Token op {peek};
	peek = ' ';

	// retorna o token 
	token.t = op;
	return &token.t;
}
