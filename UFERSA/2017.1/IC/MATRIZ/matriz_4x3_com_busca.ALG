Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 22/09/2017
Var
   // Se��o de Declara��es das vari�veis
   numeros: vetor[1..4, 1..3] de inteiro
   i, j, buscar: inteiro
   achou: logico

Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
   para i de 1 ate 4 faca
      para j de 1 ate 3 faca
         escreva ("Digite o valor para a posi��o [", i, ",", j, "]: ")
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
      escreval ("O n�mero se encontra na matriz.")
   senao
      escreval ("O n�mero N�O se encontra na matriz.")
   fimse
Fimalgoritmo