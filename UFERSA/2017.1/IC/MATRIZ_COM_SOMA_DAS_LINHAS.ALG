Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 12/10/2017
Var
// Se��o de Declara��es das vari�veis 
a,soma: vetor[1..3,1..3] de real
i,j:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
para i de 1 ate 3 faca
     para j de 1 ate 3 faca
        escreval("Digite um n�mero: ")
        leia(a[i,j])
        soma[i]<-soma[i]+a[i,j]
     fimpara
fimpara
para i de 1 ate 3 faca
     para j de 1 ate 3 faca
          escreva(a[i,j])
     fimpara
     escreval(" Soma da linha = ",soma[i])
fimpara

Fimalgoritmo