Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 18/08/2017
Var
// Se��o de Declara��es das vari�veis 
n1, n2, n3:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite o primeiro n�mero: ")
leia(n1)
escreva("Digite o segundo n�mero: ")
leia(n2)
escreva("Digite o terceiro n�mero: ")
leia(n3)
se ((n1=n2) e (n2=n3)) entao
   escreval("Sequ�ncia decrescente �: ",n1,n2,n3)
fimse
se (((n1=n2) e (n2>n3)) ou ((n1>n2) e (n2>n3)) ou ((n1>n2) e (n2=n3))) entao
   escreval("Sequ�ncia decrescente �: ",n1,n2,n3)
fimse
se (((n1=n3) e (n3>n2)) ou ((n1>n3) e (n3>n2)) ou ((n1>n3) e (n3=n2))) entao
   escreval("Sequ�ncia decrescente �: ",n1,n3,n2)
fimse
se (((n2=n1) e (n1>n3)) ou ((n2>n1) e (n1>n3)) ou ((n2>n1) e (n1=n3))) entao
   escreval("Sequ�ncia decrescente �: ",n2,n1,n3)
fimse
se (((n2=n3) e (n3>n1)) ou ((n2>n3) e (n3>n1)) ou ((n2>n3) e (n3=n1))) entao
   escreval("Sequ�ncia decrescente �: ",n2,n3,n1)
fimse
se (((n3=n1) e (n1>n2)) ou ((n3>n1) e (n1>n2)) ou ((n3>n1) e (n1=n2))) entao
   escreval("Sequ�ncia decrescente �: ",n3,n1,n2)
fimse
se (((n3=n2) e (n2>n1)) ou ((n3>n2) e (n2>n1)) ou ((n3>n2) e (n2=n1))) entao
   escreval("Sequ�ncia decrescente �: ",n3,n2,n1)
fimse
Fimalgoritmo