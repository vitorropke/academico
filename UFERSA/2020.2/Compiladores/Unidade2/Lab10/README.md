Alterações feitas somente no arquivo ast.cpp

Add linha 73 até 106:
Add linha 126 até 159:
Add linha 179 até 212:

	// se um for bool e o outro for int
    if (expr1->Type() == "bool" && expr2->Type() == "int")
    {
        if (expr2->token->lexeme != "0")
        {
            expr2->type = ExprType::BOOL;
            expr2->token->tag = Tag::TRUE;
            expr2->token->lexeme = "true";
        }
        else
        {
            expr2->type = ExprType::BOOL;
            expr2->token->tag = Tag::FALSE;
            expr2->token->lexeme = "false";
        }
    }
    // se um for int e o outro for bool
    else if (expr1->Type() == "int" && expr2->Type() == "bool")
    {
        if (expr1->token->lexeme != "0")
        {
            expr1->type = ExprType::BOOL;
            expr1->token->tag = Tag::TRUE;
            expr1->token->lexeme = "true";
        }
        else
        {
            expr1->type = ExprType::BOOL;
            expr1->token->tag = Tag::FALSE;
            expr1->token->lexeme = "false";
        }
    }
    // se um for não-int e o outro for bool
    else

O bloco:

	{
        stringstream ss;
        ss << "\'" << token->lexeme << "\' usado com operandos não booleanos ("
        << expr1->Name() << ":" << expr1->Type() << ") ("
        << expr2->Name() << ":" << expr2->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }

    ou

    {
        stringstream ss;
        ss << "\'" << token->lexeme << "\' usado com operandos de tipos diferentes ("
        << expr1->Name() << ":" << expr1->Type() << ") ("
        << expr2->Name() << ":" << expr2->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }

nas linhas 107 até 113;
	linhas 160 até 166 e
	linhas 213 até 219,

foram deslocadas 1 tabulação para direita.
