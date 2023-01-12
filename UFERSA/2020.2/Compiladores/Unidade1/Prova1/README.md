1) Gramática corrigida

	program	→	math block

	block	→	{ decls stmts }

	decls	→	decl decls
			|	ϵ

	decl	→	type id;

	stmts	→	stmt stmts
			|	ϵ

	stmt	→	block
			|	expr;

	expr	→	term add

	add		→	+ term add
			|	– term add
			|	ϵ

	term	→	factor mult

	mult	→	* factor mult
			|	/ factor mult
			|	ϵ

	factor	→	(expr)
			|	num
			|	id

2) Esquema de tradução

	program	→	math block

	block	→	{ decls stmts }

	decls	→	decl decls
			|	ϵ

	decl	→	type id;

	stmts	→	stmt stmts
			|	ϵ

	stmt	→	block
			|	expr; { print('\n') }

	expr	→	term add

	add		→	+ term { print('+') } add
			|	– term { print('-') } add
			|	ϵ

	term	→	factor mult

	mult	→	* factor { print('*') } mult
			|	/ factor { print('/') } mult
			|	ϵ

	factor	→	(expr)
			|	{ print('(') } num { print(')') }
			|	{ print('(') } id { print(')') }
