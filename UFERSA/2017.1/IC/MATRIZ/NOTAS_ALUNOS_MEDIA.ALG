Algoritmo "semnome"

Tipo

func=registro
mat: inteiro
nome: caractere
n1, n2, n3, n4: real
media, mediaf: real
fimregistro

Var

aluno: vetor [0..34] de func
i: inteiro

Inicio

para i de 1 ate 2 faca
     escreva ("Digite a matrícula: ")
     leia (aluno[i].mat)
     escreva ("Digite o nome do aluno: ")
     leia (aluno[i].nome)
     escreva ("Digite a primeira nota: ")
     leia (aluno[i].n1)
     escreva ("Digite a segunda nota: ")
     leia (aluno[i].n2)
     escreva ("Digite a terceira nota: ")
     leia (aluno[i].n3)
fimpara

para i de 1 ate 2 faca
     aluno[i].media <- ((aluno[i].n1*2)+(aluno[i].n2*3)+(aluno[i].n3*4))/9
fimpara

para i de 1 ate 2 faca
     se (aluno[i].media >= 7) entao
        escreval ("O aluno ",aluno[i].nome," foi aprovado",aluno[i].media)
     fimse
     se (aluno[i].media <3.5) entao
        escreval ("O aluno ",aluno[i].nome" foi reprovado",aluno[i].media)
     fimse
     se ((aluno[i].media < 7) e (aluno[i].media >= 3.5)) entao
        escreval ("Recuperação. O aluno ",aluno[i].nome, " terá que fazer a quarta prova",aluno[i].media)
        escreval ("Digite a nota da quarta prova: ")
        leia (aluno[i].n4)
        aluno[i].mediaf <- ((aluno[i].media*7)+(aluno[i].n4*4))/11
        se (aluno[i].mediaf >= 5) entao
           escreval ("O aluno ",aluno[i].nome," foi aprovado!",aluno[i].mediaf)
        fimse
        se (aluno[i].mediaf < 5) entao
           escreval ("O aluno ",aluno[i].nome" foi reprovado",aluno[i].mediaf)
        fimse
     fimse
fimpara

Fimalgoritmo