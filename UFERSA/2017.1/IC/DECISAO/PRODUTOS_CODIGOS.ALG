Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Seção de Declarações das variáveis 
codigo:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite o código do alimento: ")
leia(codigo)
se (codigo=1) entao
   escreva("Este é um alimento não-perecível")
fimse
se ((codigo>=2) e (codigo<=4)) entao
   escreva("Este é um alimento perecível")
fimse
se ((codigo=5) ou (codigo=6)) entao
   escreva("Este é um produto de vestuário")
fimse
se (codigo=7) entao
   escreva("Este é um produto de higiene pessoal")
fimse
se ((codigo>=8) e (codigo<=15)) entao
   escreva("Estes são produtos de limpeza e utensílios domésticos")
fimse
se ((codigo>15) ou (codigo<1)) entao
   escreva("Este produto é inválido")
fimse
Fimalgoritmo