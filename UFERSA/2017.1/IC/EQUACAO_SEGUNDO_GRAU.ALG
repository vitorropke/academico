Algoritmo "semnome"

Var
a, b, c, delta, x1, x2: real

Funcao calcula_delta(): real
Var
Inicio
delta <- b*b-4*a*c
retorne delta

Fimfuncao

Inicio
escreva ("Informe o valor de A: ")
leia(a)
escreva ("Informe o valor de B: ")
leia (b)
escreva ("Informe o valor de C: ")
leia (c)
delta <- calcula_delta()
se (delta < 0) entao
   escreva ("Esta equação não possui raízes reais.")
senao
     se (delta = 0) entao
        x1 <- (-b + raizq(delta))/(2*a)
        escreva ("Esta equação possui apenas uma raiz: ", x1)
     senao
          x1 <- (-b + raizq(delta))/(2*a)
          x2 <- (-b - raizq(delta))/(2*a)
          escreva ("Esta equação possui duas raízes: ", x1, " e ", x2)
     fimse
fimse

Fimalgoritmo