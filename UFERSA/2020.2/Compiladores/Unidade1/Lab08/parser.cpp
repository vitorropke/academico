#include "parser.h"
#include "error.h"
#include <iostream>
#include <sstream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

void Parser::Program()
{
    // program -> block
    Block();
}

void Parser::Block()
{
    // block -> { decls stmts } 
    if (!Match('{'))
        throw SyntaxError(scanner.Lineno(), "\'{\' esperado");
    else
        cout << "{ ";    


    // nova tabela de símbolos para o bloco
    // ------------------------------------
    SymTable * saved = symtable;
    symtable = new SymTable(symtable);
    // ------------------------------------

    Decls();
    Stmts();

    if (!Match('}'))
        throw SyntaxError(scanner.Lineno(), "\'}\' esperado");
    else
        cout << "} ";
    

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
    //        | fact;
    
    while(true)
    {
        switch(lookahead->tag)
        {
            // stmt -> block
            case '{': 
                Block(); 
                break;
            // stmt -> fact; 
            case Tag::ID: 
                Fact();
                if(!Match(';'))
                {
                    stringstream ss;
                    ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
                    throw SyntaxError { scanner.Lineno(), ss.str() };
                } 
                break;
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
            // stmts -> empty
            default: return;
        }
    }   
}


void Parser::Fact()
{
    // fact -> id
    if (lookahead->tag == Tag::ID)
    {
        // verifica tipo da variável na tabela de símbolos
        Symbol * s = symtable->Find(lookahead->toString());
        if (!s)
        {
            stringstream ss;
            ss << "variável \"" << lookahead->toString() << "\" não declarada";
            throw SyntaxError{ scanner.Lineno(), ss.str() };
        }
        cout << s->var << ':' << s->type << "; ";
        Match(Tag::ID);
    }
    // fact -> num
    else if (lookahead->tag == Tag::NUM)
    {
        cout << lookahead->toString() << ':';

        /*
            Gambiarra aqui porque não consegui passar o tipo através de atributo
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
