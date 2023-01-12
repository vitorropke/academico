Algoritmo "semnome"

Var
impar:vetor[0..10] de inteiro
i,n,soma:inteiro

Inicio
para i de 1 ate 10 faca
     escreva("Digite o ",i,"º número: ")
     leia(n)
     se n%2=1 entao
        soma<-soma+n
     fimse
fimpara
escreval("A soma dos números ímpares é: ",soma)

Fimalgoritmo