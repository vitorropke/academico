Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 01/09/2017
Var
   // Se��o de Declara��es das vari�veis
   n, i:inteiro

Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
   escreva("Digite um n�mero a� brother: ")
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