Algoritmo "semnome"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Se��o de Declara��es das vari�veis 
numero:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Digite um n�mero inteiro e positivo de tr�s digitos: ")
leia(numero)
escreval ("N�mero invertido: ", (numero%10*100)+(numero\10%10*10)+(numero\10\10))
Fimalgoritmo