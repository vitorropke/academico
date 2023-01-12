Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 01/09/2017
Var
// Seção de Declarações das variáveis 
a:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreval("Digite um número: ")
leia(a)
se (a<0) entao
   escreval("Número inválido! Impossível de calcular a raíz!")
fimse
enquanto (a > 0) faca
     escreval("A raíz deste número é", raizq(a))
     escreval("Digite outro número: ")
     leia(a)
     se (a < 0) entao
        escreval("Número inválido! Impossível de calcular a raíz!")
     fimse
fimenquanto
Fimalgoritmo