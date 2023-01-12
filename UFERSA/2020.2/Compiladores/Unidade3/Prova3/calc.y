%{
/* analisador sintático para uma calculadora */
/* com suporte a definição de variáveis */
/* e também a instruções (if e print) */
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::cout;

/* protótipos das funções especiais */
int yylex(void);
int yyparse(void);
void yyerror(const char *);
float pow(float a, unsigned int b);
float sqrt(float a);

/* tabela de símbolos */
unordered_map<string,double> variables;
%}

%union {
	double num;
	char id[16];
	char func[5];
}

%token <id> ID
%token <num> NUM
%token <id> FUNC
%token <id> PRINT
%token <id> IF
%token <id> ALL

%type <id> parametros
%type <num> calc
%type <num> expr

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

math: math calc '\n'
	| calc '\n'
	;

calc: expr
	| IF expr expr			{ if ($2) ($$ = $3); }
	;

expr: expr '+' expr				{ $$ = $1 + $3; }
	| expr '-' expr				{ $$ = $1 - $3; }
	| expr '*' expr				{ $$ = $1 * $3; }
	| expr '/' expr				{ if ($3 == 0) (yyerror("Não é possível dividir por zero")); else ($$ = $1 / $3); }
	| expr '>' expr				{ if ($1 > $3) ($$ = true); else ($$ = false); }
	| expr '<' expr				{ if ($1 < $3) ($$ = true); else ($$ = false); }
	| expr '>''=' expr			{ if ($1 >= $4) ($$ = true); else ($$ = false); }
	| expr '<''=' expr			{ if ($1 <= $4) ($$ = true); else ($$ = false); }
	| expr '=''=' expr			{ if ($1 == $4) ($$ = true); else ($$ = false); }
	| expr '!''=' expr			{ if ($1 != $4) ($$ = true); else ($$ = false); }
	| '(' expr ')'				{ $$ = $2; }
	| '-' expr %prec UMINUS		{ $$ = - $2; }
	| FUNC'(' expr ',' expr ')'	{ $$ = pow($3, $5); }
	| FUNC'(' expr ')'			{ $$ = sqrt($3); }
	| ID '=' expr				{ variables[$1] = $3; }
	| ID						{ $$ = variables[$1]; }
	| NUM
	| PRINT'('parametros')'		{ cout << '\n'; }
	;

parametros:	ALL				{
								int i = 1;

								while ($1[i] != '\\' && $1[i + 1] != '\"')
								{
									cout << $1[i];
									i++;
 								}
								
								cout << $1[i];
							}
	|		expr			{ cout << $1; }
	|		parametros ALL	{ cout << $2; }
	|		parametros expr	{ cout << $2; }
	|		ALL','			{
								int i = 1;
								
								while ($1[i] != '\\' && $1[i + 1] != '\"')
								{
									cout << $1[i];
									i++;
 								}
								
								cout << $1[i];
							}
	|		expr','			{ cout << $1; }
	;

%%

/* definido pelo analisador léxico */
extern FILE * yyin;

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}

		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	extern int yylineno;
	extern char * yytext;

	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
	cout << "Erro (" << s << "): símbolo \"" << yytext << "\" (linha " << yylineno << ")\n";
}

// https://stackoverflow.com/questions/26860574/pow-implementation-in-cmath-and-efficient-replacement
float pow(float a, unsigned int b)
{
	float resultado;

	if (b == 0)
	{
		return 1;
	}

	resultado = pow(a, b / 2);

	if ((b % 2) == 0)
	{
		return resultado * resultado;
	}
	else
	{
		return a * resultado * resultado;
	}
}

// https://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi
float sqrt(float a)
{
	union
	{
		int i;
		float a;
	} u;
	u.a = a;
	u.i = (1<<29) + (u.i >> 1) - (1<<22);

	// Two Babylonian Steps (simplified from:)
	// u.a = 0.5f * (u.a + a/u.a);
	// u.a = 0.5f * (u.a + a/u.a);
	u.a = u.a + a / u.a;
	u.a = 0.25f * u.a + a / u.a;

	return u.a;
}
