Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2017
Var
   // Se��o de Declara��es das vari�veis
   vet: vetor [1..10] de inteiro
   i, x, aux: inteiro

Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
   para i de 1 ate 10 faca
      escreva ("Digite um valor para a posi��o ", i , " do vetor: ")
      leia (vet[i])
   fimpara
   escreva ("N�meros na ordem em que foram digitados: ")
   para i de 1 ate 9 faca
      para x de i+1 ate 10 faca
         se vet[x] < vet[i] entao
            aux <- vet[x]
            vet[x] <- vet[i]
            vet[i] <- aux
         fimse
      fimpara
   fimpara
   para i de 1 ate 10 faca
      escreval(vet[i])
   fimpara

Fimalgoritmo