Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Se��o de Declara��es das vari�veis 
codigo:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite o c�digo do alimento: ")
leia(codigo)
se (codigo=1) entao
   escreva("Este � um alimento n�o-perec�vel")
fimse
se ((codigo>=2) e (codigo<=4)) entao
   escreva("Este � um alimento perec�vel")
fimse
se ((codigo=5) ou (codigo=6)) entao
   escreva("Este � um produto de vestu�rio")
fimse
se (codigo=7) entao
   escreva("Este � um produto de higiene pessoal")
fimse
se ((codigo>=8) e (codigo<=15)) entao
   escreva("Estes s�o produtos de limpeza e utens�lios dom�sticos")
fimse
se ((codigo>15) ou (codigo<1)) entao
   escreva("Este produto � inv�lido")
fimse
Fimalgoritmo