Algoritmo "semnome"

Var
   valor,result:real
   temp:inteiro

Funcao calculo_d():real
Var
   prest:real
Inicio
   prest<-valor+(valor*(5/100)*temp)
   retorne prest
Fimfuncao

Inicio
   escreva("Digite o valor da dívida: R$")
   leia(valor)
   escreva("Digite o tempo de atraso em dias. Deve ser menor que 30 dias: ")
   leia(temp)
   escreval("O valor da prestação foi de R$",calculo_d)


Fimalgoritmo