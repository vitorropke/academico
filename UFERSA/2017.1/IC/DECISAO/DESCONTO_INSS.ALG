Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 18/08/2017
Var
// Se��o de Declara��es das vari�veis 
salario:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite o seu sal�rio: ")
leia(salario)
se (salario<=600) entao
   escreval("Tu est�is isento do INSS. Seu sal�rio �", salario," reais")
fimse
se ((salario>600) e (salario<=1200)) entao
   escreval("Tu obteves um desconto de 20% em vosso sal�rio. Agora seu sal�rio �", salario*(80/100)," reais")
fimse
se ((salario>1200) e (salario<=2000)) entao
   escreval("Tu obteves um desconto de 25% em vosso sal�rio. Agora seu sal�rio �", salario*(75/100)," reais")
fimse
se (salario>2000) entao
   escreval("Tu obteves um desconto de 30% em vosso sal�rio. Agora seu sal�rio �", salario*(70/100)," reais")
fimse
Fimalgoritmo