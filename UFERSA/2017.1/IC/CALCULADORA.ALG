Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
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
   escreval("Digite 1 para adicão!")
   escreval("Digite 2 para subtração!")
   escreval("Digite 3 para multiplicação!")
   escreval("Digite 4 para divisão!")
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
   escreval("Digite um número: ")
   leia(x)
   escreval("Digite um número: ")
   leia(y)
   menu

Fimalgoritmo