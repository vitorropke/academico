Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 01/09/2017
Var
// Se��o de Declara��es das vari�veis 
a:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreval("Digite um n�mero: ")
leia(a)
se (a<0) entao
   escreval("N�mero inv�lido! Imposs�vel de calcular a ra�z!")
fimse
enquanto (a > 0) faca
     escreval("A ra�z deste n�mero �", raizq(a))
     escreval("Digite outro n�mero: ")
     leia(a)
     se (a < 0) entao
        escreval("N�mero inv�lido! Imposs�vel de calcular a ra�z!")
     fimse
fimenquanto
Fimalgoritmo