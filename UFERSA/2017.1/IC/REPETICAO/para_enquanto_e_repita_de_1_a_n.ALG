Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 01/09/2017
Var
   // Seção de Declarações das variáveis
   n, i:inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...
   escreva("Digite um número aê brother: ")
   leia(n)
   escreval("USANDO O PARA")
   para i de 1 ate n faca
      escreval(i)
   fimpara
   escreval("USANDO O ENQUANTO")
   i<-1
   enquanto (n>=i) faca
      escreval(i)
      i<-i+1
   fimenquanto
   escreval("USANDO O REPITA")
   i<-1
   repita
         escreval(i)
         i <- i+1
   ate (i>n)


Fimalgoritmo