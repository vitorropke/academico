Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Se��o de Declara��es das vari�veis 
media, n1, n2, n3, media_final, recuperacao:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite a sua primeira nota: ")
leia(n1)
escreva("Digite a sua segunda nota: ")
leia(n2)
escreva("Digite a sua terceira nota: ")
leia(n3)
media<-((n1*2)+(n2*3)+(n3*4))/9
escreval("Sua m�dia � ",media)
se (media>=7) entao
   escreva("Tu est�is aprovado.")
fimse
se (media<3.5) entao
   escreva("Tu est�is reprovado.")
fimse
se ((media>=3.5) e (media<7)) entao
   escreval("Tu est�is em recupera��o. Deves fazer a quarta prova")
   escreva("Digite sua nota da 4�prova: ")
   leia(recuperacao)
   media_final<-((media*7)+(recuperacao*3))/10
   se (media_final>=7) entao
      escreva("Tu est�is aprovado com m�dia ",media_final)
   fimse
   se (media_final<7) entao
      escreva("Tu est�is reprovado com m�dia ",media_final)
   fimse
fimse
Fimalgoritmo