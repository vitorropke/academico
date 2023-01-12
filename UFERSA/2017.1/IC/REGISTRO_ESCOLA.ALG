Algoritmo "semnome"

Tipo
escola=registro
matricula:inteiro
nome:caractere
n1,n2,n3,media:real
fimregistro

Var
// Seção de Declarações das variáveis 
aluno:vetor[0..34] de escola
i:inteiro
mediaf,n4:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
para i de 1 ate 2 faca
     escreval("Digite a matrícula do aluno: ")
     leia(aluno[i].matricula)
     escreval("Digite o nome do aluno: ")
     leia(aluno[i].nome)
     escreval("Digite a primeira nota: ")
     leia(aluno[i].n1)
     escreval("Digite a segunda nota: ")
     leia(aluno[i].n2)
     escreval("Digite a terceira nota: ")
     leia(aluno[i].n3)
     aluno[i].media<-(aluno[i].n1*2+aluno[i].n2*3+aluno[i].n3*4)/9
fimpara

para i de 1 ate 2 faca
     se aluno[i].media>=7 entao
        escreval("O indivíduo ",aluno[i].nome," está aprovado")
     fimse
     se aluno[i].media<3 entao
          escreval("O aluno ",aluno[i].nome," está reprovado")
     fimse
     se ((aluno[i].media>=3.5) e (aluno[i].media<7)) entao
        escreval("O indivíduo ",aluno[i].nome," está em recuperação. Precisa fazer a quarta prova")
        escreval("Digite a nota da quarta prova: ")
        leia(n4)
        mediaf<-(n4*7+aluno[i].media*3)/10
        se mediaf>=5 entao
           escreval("O aluno ",aluno[i].nome," está aprovado")
        senao
             escreval("O aluno",aluno[i].nome," está reprovado")
        fimse
     fimse
fimpara

Fimalgoritmo