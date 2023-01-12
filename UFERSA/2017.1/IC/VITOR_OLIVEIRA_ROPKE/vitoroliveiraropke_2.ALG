Algoritmo "semnome"

Tipo
   alt=registro
      nome:caractere
      altura:real
   Fimregistro

Var
   na: vetor[1..15] de alt
   i:inteiro
   t_alt,media:real
   opcao:inteiro

Procedimento menu
Var

Inicio
   escreval("Digite 1 para cadastrar os 15 registros!")
   escreval("Digite 2 para apresentar os registros das pessoas que sejam menores ou iguais a 1.6m")
   escreval("Digite 3 para apresentar os registros das pessoas que sejam maiores que 1.6m")
   escreval("Digite 4 para apresentar os registros das pessoas que sejam maiores que 1.6m e menores que 2m")
   escreval("Digite 5 para apresentar a média de todas as alturas armazenadas")
   escreval("Digite 6 para sair do programa")
   escreva("Digite o que desejas fazer: ")
   leia(opcao)
   escreval()
   escolha opcao
   caso 1
      para i de 1 ate 15 faca
         escreval("Digite o nome do ",i,"º indivíduo: ")
         leia(na[i].nome)
         escreval("Digite a altura do ",i,"º indivíduo: ")
         leia(na[i].altura)
         t_alt<-t_alt+na[i].altura
      fimpara
   caso 2
      escreval("Indivíduos com altura menor ou igual a 1.6m")
      para i de 1 ate 15 faca
         se (na[i].altura<=1.6) entao
            escreva("Nome: ",na[i].nome)
            escreval(" Altura:",na[i].altura)
         fimse
      fimpara
   caso 3
      escreval("Indivíduos com altura maior que 1.6m")
      para i de 1 ate 15 faca
         se (na[i].altura>1.6) entao
            escreva("Nome: ",na[i].nome)
            escreval(" Altura:",na[i].altura)
         fimse
      fimpara
   caso 4
      escreval("Indivíduos com altura maior que 1.6m e menor que 2m")
      para i de 1 ate 15 faca
         se ((na[i].altura>1.6) e (na[i].altura<2)) entao
            escreva("Nome: ",na[i].nome)
            escreval(" Altura:",na[i].altura)
         fimse
      fimpara
   caso 5
      media<-t_alt/15
      escreval("A altura média de todos é ",media,"m")
   caso 6
      escreval("Acabou por aqui meu caro(minha cara)!!")
   fimescolha

Fimprocedimento

Inicio
   enquanto opcao<>6 faca
      menu
      escreval()
   fimenquanto


Fimalgoritmo