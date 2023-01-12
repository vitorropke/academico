Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 18/08/2017
Var
// Seção de Declarações das variáveis 
salario:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite o seu salário: ")
leia(salario)
se (salario<=600) entao
   escreval("Tu estáis isento do INSS. Seu salário é", salario," reais")
fimse
se ((salario>600) e (salario<=1200)) entao
   escreval("Tu obteves um desconto de 20% em vosso salário. Agora seu salário é", salario*(80/100)," reais")
fimse
se ((salario>1200) e (salario<=2000)) entao
   escreval("Tu obteves um desconto de 25% em vosso salário. Agora seu salário é", salario*(75/100)," reais")
fimse
se (salario>2000) entao
   escreval("Tu obteves um desconto de 30% em vosso salário. Agora seu salário é", salario*(70/100)," reais")
fimse
Fimalgoritmo