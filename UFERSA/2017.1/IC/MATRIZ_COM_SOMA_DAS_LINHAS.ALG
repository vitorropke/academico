Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 12/10/2017
Var
// Seção de Declarações das variáveis 
a,soma: vetor[1..3,1..3] de real
i,j:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
para i de 1 ate 3 faca
     para j de 1 ate 3 faca
        escreval("Digite um número: ")
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