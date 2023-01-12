Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Seção de Declarações das variáveis 
idade:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite a sua idade: ")
leia(idade)
se (idade<=10) entao
   escreva("Tu farás parte da categoria infantil")
fimse
se ((idade>=11) e (idade<=15)) entao
   escreva("Tu farás parte da categoria infanto")
fimse
se ((idade>=16) e (idade<=18)) entao
   escreva("Tu farás parte da categoria juvenil")
fimse
se (idade>18) entao
   escreva("Tu farás parte da categoria adulto")
fimse
Fimalgoritmo