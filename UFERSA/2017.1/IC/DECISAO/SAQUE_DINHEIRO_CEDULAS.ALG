Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Seção de Declarações das variáveis 
saque:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite o valor a ser sacado: ")
leia(saque)
escreval("Número de cédulas de R$100: ",saque\100)
saque <- saque - saque\100*100
escreval ("Número de cédulas de R$50: ",saque\50)
saque <- saque%50
escreval("Número de cédulas de R$20: ",saque\20)
saque <- saque%20
escreval("Número de cédulas de R$10: ",saque\10)
saque <- saque%10
escreval("Número de cédulas de R$5: ",saque\5)
saque <- saque%5
escreval("Número de cédulas de R$2: ",saque\2)
saque <- saque%2
Fimalgoritmo