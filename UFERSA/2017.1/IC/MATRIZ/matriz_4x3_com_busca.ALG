Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2017
Var
   // Seção de Declarações das variáveis
   numeros: vetor[1..4, 1..3] de inteiro
   i, j, buscar: inteiro
   achou: logico

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...
   para i de 1 ate 4 faca
      para j de 1 ate 3 faca
         escreva ("Digite o valor para a posição [", i, ",", j, "]: ")
         leia (numeros[i, j])
      fimpara
   fimpara
   escreval("Digite um valor para ser buscado na matriz: ")
   leia (buscar)
   achou <- falso
   para i de 1 ate 4 faca
      para j de 1 ate 3 faca
         se (numeros[i,j] = buscar) entao
            achou <- verdadeiro
         fimse
      fimpara
   fimpara
   se (achou = verdadeiro) entao
      escreval ("O número se encontra na matriz.")
   senao
      escreval ("O número NÃO se encontra na matriz.")
   fimse
Fimalgoritmo