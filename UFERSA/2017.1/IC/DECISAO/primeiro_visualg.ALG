Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 04/08/2017
Var
// Se��o de Declara��es das vari�veis 
n1, n2, n3, media: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva ("Digite a primeira nota: ")
Leia(n1)
escreva ("Digite a segunda nota: ")
Leia(n2)
escreva ("Digite a terceira nota: ")
Leia(n3)
media<-(n1+n2+n3)/3
escreval("media=", media)
se (media>7) entao
   escreva("Voc� foi aprovado")
fimse
se ((media>3) e (media<7)) entao
   escreva("Voc� est� em recupera��o")
fimse
se (media<3) entao
     escreva("Voc� reprovou!! Fracassado")
fimse
Fimalgoritmo
