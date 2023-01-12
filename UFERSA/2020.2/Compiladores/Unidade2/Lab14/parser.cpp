#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
            case IF: cout << "IF\n"; break;
            case THEN: cout << "THEN\n"; break;
            case ELSE: cout << "ELSE\n"; break;
            case WHILE: cout << "WHILE\n"; break;
            case ID: cout << "ID: " << scanner.YYText() << "\n"; break;
            case NUM: cout << "NUM: " << scanner.YYText() << "\n"; break;
            case RELOP: cout << "RELOP: " << scanner.YYText() << "\n";; break;
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
        }
    }
}
