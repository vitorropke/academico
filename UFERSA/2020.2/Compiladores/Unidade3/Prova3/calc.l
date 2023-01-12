%{ 
/* analisador léxico para uma calculadora */
/* com suporte a definição de variáveis */
#include "parser.h"
%}

%option yylineno
%option noyywrap

digito		[0-9]
letra_		[a-zA-Z_]
pontdig		{digito}*"."?{digito}+
digpont		{digito}+"."

decisao		if
imprime		print
funcoes		pow|sqrt
numero		{pontdig}|{digpont}
id			{letra_}({letra_}|{digito})*
tudo		\".*\"

%%

[\t ]+		{ ; /* ignora espaço em branco */ }
{decisao}	{ return IF; }
{imprime}	{ return PRINT; }
{funcoes}	{ return FUNC; }
{numero}	{ yylval.num = atof(yytext); return NUM; }
{id}		{ strcpy(yylval.id, yytext); return ID; }
{tudo}		{ strcpy(yylval.id, yytext); return ALL; }
.|\n		{ return yytext[0]; }

%%
