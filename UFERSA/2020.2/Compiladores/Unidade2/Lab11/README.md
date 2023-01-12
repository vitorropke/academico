Sem modificações

O material fornecido no SIGAA e no GitHub já estavam resolvidos. O spoiler já foi dado.

Mas eu entendi que, vendo o formato do "do while":

do_while stmt (expr)

--------------before--------------		do {
stmt										stmt;
(expr)
calcula 'expr' e armazena em 'n'		}
ifTrue n goto before					while(n == true);

O programa entra no "do" e executa o "stmt" sem passar por condicionais.
No final, existe uma condição que calcula "expr" que, se for verdade,
retornará para uma linha antes do "stmt", que é onde fica o "before".
Se for falsa, sai do "do_while" e prossegue com o resto do programa.

O "if":

if (expr) stmt

calcula 'expr' e armazena em 'n'		if (n == true) {
ifFalse n goto after
stmt										stmt;
--------------after--------------		}

O programa passa por uma condicional que calcula "expr" que se for
verdadeira, executa "stmt", sai do "if" e prossegue com o resto do
programa. Se for falsa, vai para "after", sai do "if" e prossegue
com o resto do programa, sem executar "stmt".

O "while" seria:

while (expr) stmt			(Aqui fica um pouco mais difícil de demonstrar com o código real lado a lado)

--------------before--------------
calcula 'expr' e armazena em 'n'		while (n == true) {
ifFalse n goto after
stmt										stmt;
goto before								}
--------------after---------------

A primeira parte do "while" funciona como a primeira parte do "if" e o
final do "while" funciona como o final de "do_while" mas sem a condicional.

O programa passa por uma condicional que calcula "expr" que se for
verdadeira, executa "stmt", e retorna para a linha onde tem "before".
Se for falsa, vai para "after", sai do "while" e prossegue com o resto
do programa, sem executar "stmt".

