Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2017
Var
   // Seção de Declarações das variáveis
   numeros: vetor[1..3, 1..3] de inteiro
   i, j, soma: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...
   para i de 1 ate 3 faca
      para j de 1 ate 3 faca
         escreva ("Digite o valor para a posição [", i, ",", j, "]: ")
         leia (numeros[i, j])
      fimpara
   fimpara
   para i de 1 ate 3 faca
      soma <- 0
      para j de 1 ate 3 faca
         escreva (numeros[i, j])
         soma <- soma + numeros [i, j]
      fimpara
      escreval (" Soma da Linha ",i," =", soma)
   fimpara


Fimalgoritmo