Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 18/08/2017
Var
// Seção de Declarações das variáveis 
n1, n2, n3:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite o primeiro número: ")
leia(n1)
escreva("Digite o segundo número: ")
leia(n2)
escreva("Digite o terceiro número: ")
leia(n3)
se ((n1=n2) e (n2=n3)) entao
   escreval("Sequência decrescente é: ",n1,n2,n3)
fimse
se (((n1=n2) e (n2>n3)) ou ((n1>n2) e (n2>n3)) ou ((n1>n2) e (n2=n3))) entao
   escreval("Sequência decrescente é: ",n1,n2,n3)
fimse
se (((n1=n3) e (n3>n2)) ou ((n1>n3) e (n3>n2)) ou ((n1>n3) e (n3=n2))) entao
   escreval("Sequência decrescente é: ",n1,n3,n2)
fimse
se (((n2=n1) e (n1>n3)) ou ((n2>n1) e (n1>n3)) ou ((n2>n1) e (n1=n3))) entao
   escreval("Sequência decrescente é: ",n2,n1,n3)
fimse
se (((n2=n3) e (n3>n1)) ou ((n2>n3) e (n3>n1)) ou ((n2>n3) e (n3=n1))) entao
   escreval("Sequência decrescente é: ",n2,n3,n1)
fimse
se (((n3=n1) e (n1>n2)) ou ((n3>n1) e (n1>n2)) ou ((n3>n1) e (n1=n2))) entao
   escreval("Sequência decrescente é: ",n3,n1,n2)
fimse
se (((n3=n2) e (n2>n1)) ou ((n3>n2) e (n2>n1)) ou ((n3>n2) e (n2=n1))) entao
   escreval("Sequência decrescente é: ",n3,n2,n1)
fimse
Fimalgoritmo