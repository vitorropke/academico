Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 12/10/2017
Var
   x,y:real

Procedimento adicao
Var
Inicio
   escreval(x+y)

Fimprocedimento

Procedimento subtracao
Var
Inicio
   escreval(x-y)

Fimprocedimento

Procedimento multiplicacao
Var
Inicio
   escreval(x*y)

Fimprocedimento

Procedimento divisao
Var
Inicio
   escreval(x/y)

Fimprocedimento

Procedimento fim
Var
Inicio
   escreval("Escolhestes terminar! Tenha um bom dia")

Fimprocedimento

Procedimento menu
Var
   opcao:inteiro
Inicio
   escreval("Digite 1 para adic�o!")
   escreval("Digite 2 para subtra��o!")
   escreval("Digite 3 para multiplica��o!")
   escreval("Digite 4 para divis�o!")
   escreval("Digite 5 para fim do programa!")
   escreval("O que desejas fazer? Digite aqui: ")
   leia(opcao)
   escolha opcao
   caso 1
      adicao
   caso 2
      subtracao
   caso 3
      multiplicacao
   caso 4
      divisao
   caso 5
      fim
   fimescolha

Fimprocedimento

Inicio
   escreval("Digite um n�mero: ")
   leia(x)
   escreval("Digite um n�mero: ")
   leia(y)
   menu

Fimalgoritmo