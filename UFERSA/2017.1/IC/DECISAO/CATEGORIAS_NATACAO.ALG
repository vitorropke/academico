Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Se��o de Declara��es das vari�veis 
idade:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite a sua idade: ")
leia(idade)
se (idade<=10) entao
   escreva("Tu far�s parte da categoria infantil")
fimse
se ((idade>=11) e (idade<=15)) entao
   escreva("Tu far�s parte da categoria infanto")
fimse
se ((idade>=16) e (idade<=18)) entao
   escreva("Tu far�s parte da categoria juvenil")
fimse
se (idade>18) entao
   escreva("Tu far�s parte da categoria adulto")
fimse
Fimalgoritmo