Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Se��o de Declara��es das vari�veis 
saque:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite o valor a ser sacado: ")
leia(saque)
escreval("N�mero de c�dulas de R$100: ",saque\100)
saque <- saque - saque\100*100
escreval ("N�mero de c�dulas de R$50: ",saque\50)
saque <- saque%50
escreval("N�mero de c�dulas de R$20: ",saque\20)
saque <- saque%20
escreval("N�mero de c�dulas de R$10: ",saque\10)
saque <- saque%10
escreval("N�mero de c�dulas de R$5: ",saque\5)
saque <- saque%5
escreval("N�mero de c�dulas de R$2: ",saque\2)
saque <- saque%2
Fimalgoritmo