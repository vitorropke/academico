Algoritmo "semnome"

Var
   i, j, cont: inteiro
   matriz: vetor[1..5,1..5] de inteiro

Inicio

   para i de 1 ate 5 faca:
      para j de 1 ate 5 faca:
         escreval("Digite um número")
         leia(matriz[i,j])
      fimpara
   fimpara
   cont<-0
   para i de 1 ate 5 faca:
      para j de 1 ate 5 faca:
         se (matriz[i,j] mod 2 = 0 ) entao
            cont<-cont+1
         fimse
      fimpara
   fimpara
   escreval("Foram ",cont," números pares")


Fimalgoritmo