%{
// Faz contagem de caracteres, tags e linhas de um arquivo html, e mostra sua hierarquia
#include <iostream>
#include <fstream>
using namespace std;

unsigned charCount = 0, tagCount = 0, lineCount = 0, tabCount = 0, charParagraphCount = 0;
%}

%option noyywrap

doctype		"<!DOCTYPE html>"
comentario	"<!--"*"-->"
tags		html|head|style|title|body|h1|h2|h3|h4|h5|h6|p|b|i|table|tr|th|td|ul|li|br|img|a
abreTag		<{tags}(" ".+=\".+\")?>
fechaTag	"</"{tags}>
text		[^\n{doctype}{comentario}{abreTag}{fechaTag}]
eol			\n

%%

{abreTag}	{
				// Incrementa o contador de tags
				tagCount++;

				// Imprime as tabulações e as '|', baseado na identação (hierarquia)
				for (int x = 0; x < tabCount; x++) {
					cout << '|' << "\t";
				}

				// Detecta se a tag não é 'br' nem 'img'
				// Elas não necessitam de identação
				if (((YYText()[1] != 'b') || (YYText()[2] != 'r')) &&
					((YYText()[1] != 'i') || (YYText()[2] != 'm') || (YYText()[3] != 'g')))
				{
					tabCount++;
				}

				cout << "+--" << YYText() << "\n";
			}
{fechaTag}	{
				// Imprime a quantidade de caracteres do parágrafo se este tiver caracteres
				if (charParagraphCount != 0)
				{
					// Se a tag não for 'style'
					if ((YYText()[2] != 's') || (YYText()[3] != 't') ||
						(YYText()[4] != 'y') || (YYText()[5] != 'l') ||
						(YYText()[6] != 'e'))
					{
						// Imprime as tabulações e as '|', baseado na identação (hierarquia)
						for (int x = 0; x < tabCount; x++) {
							cout << '|' << "\t";
						}
						cout << "+--Texto[" << charParagraphCount << "]\n";

						// Incrementa o contador de caracteres e reseta o contador de 
						// caracteres de parágrafo
						charCount += charParagraphCount;
						charParagraphCount = 0;
					}
					else
					{
						charParagraphCount = 0;
					}
				}

				// Decrementa a tabulação ao fechar a tag
				tabCount--;

				// Imprime as tabulações e as '|', baseado na identação (hierarquia)
				for (int x = 0; x < tabCount; x++) {
					cout << '|' << "\t";
				}

				cout << "+--" << YYText() << "\n";
			}
{text}		{ charParagraphCount++; }
{eol}		{ lineCount++; }
.			{ }

%%

int main(int argc, char ** argv)
{
	yyFlexLexer lexer;  // lexer lê da entrada padrão (teclado)
	ifstream fin;

	if (argc > 1)
	{
		fin.open(argv[1]);
		if (!fin.is_open())
		{
			cout << "Arquivo " << argv[1] << " não pode ser aberto!\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			// altera entrada para arquivo aberto
			lexer.switch_streams(&fin);
		}
	}

	lexer.yylex();

	cout	<< "\nTags HTML: " << tagCount << "\n"
			<< "Linhas: " << lineCount << "\n"
			<< "Caracteres: " << charCount << "\n";

	fin.close();
	return 0;
}
