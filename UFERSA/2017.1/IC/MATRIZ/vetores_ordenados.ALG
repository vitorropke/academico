Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2017
Var
   // Seção de Declarações das variáveis
   vet: vetor [1..10] de inteiro
   i, x, aux: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...
   para i de 1 ate 10 faca
      escreva ("Digite um valor para a posição ", i , " do vetor: ")
      leia (vet[i])
   fimpara
   escreva ("Números na ordem em que foram digitados: ")
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