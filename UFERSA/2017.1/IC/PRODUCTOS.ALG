Algoritmo "semnome"

tipo
   super=registro
      prod_cod: inteiro
      nome: caractere
      preco: real
   fimregistro

Var
   produto: vetor [1..2] de super
   i: inteiro
   cod_digitado: inteiro


Inicio
   // Se��o de Comandos, procedimento, fun��es, operadores, etc...
   para i de 1 ate 2 faca:
      escreval("Digite o c�digo do produto: ")
      leia(produto[i].prod_cod)
      escreval("Digite o nome do produto: ")
      leia(produto[i].nome)
      escreval("Digite o pre�o do produto: ")
      leia(produto[i].preco)
   fimpara
   escreval("C�digo Produto Pre�o")
   para i de 1 ate 2 faca:
      escreva(produto[i].prod_cod)
      escreva(produto[i].nome)
      escreva(produto[i].preco)
      escreval()
   fimpara
   escreva("Digite o c�digo de um produto: ")
   leia(cod_digitado)
   para i de 0 AT� 100 faca:
      se (produto[i].prod_cod == cod_digitado) entao:
         escreva("O produto � um ",produto[i].nome, " que custa ",produto[i].preco)
      fimse
   fimpara
Fimalgoritmo