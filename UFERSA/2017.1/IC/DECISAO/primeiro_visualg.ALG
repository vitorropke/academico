Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 04/08/2017
Var
// Seção de Declarações das variáveis 
n1, n2, n3, media: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva ("Digite a primeira nota: ")
Leia(n1)
escreva ("Digite a segunda nota: ")
Leia(n2)
escreva ("Digite a terceira nota: ")
Leia(n3)
media<-(n1+n2+n3)/3
escreval("media=", media)
se (media>7) entao
   escreva("Você foi aprovado")
fimse
se ((media>3) e (media<7)) entao
   escreva("Você está em recuperação")
fimse
se (media<3) entao
     escreva("Você reprovou!! Fracassado")
fimse
Fimalgoritmo
