Algoritmo "semnome"

Var
   i,r,n: inteiro


Funcao fatorial(): inteiro
Var
   res:inteiro

Inicio
   para i de n ate 1 passo -1 faca
      se (i = n) entao
         res <- n * (i - 1)
      fimse
      se (i < n) e (i <> 1)  entao
         res <- res * (i - 1)
      fimse
   fimpara
   retorne res
Fimfuncao

Inicio
   escreval("Digite um n�mero: ")
   leia(n)
   r<-fatorial
   escreval("Fatorial deste n�mero � ",r)


Fimalgoritmo