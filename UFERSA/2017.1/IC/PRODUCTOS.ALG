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
   // Seção de Comandos, procedimento, funções, operadores, etc...
   para i de 1 ate 2 faca:
      escreval("Digite o código do produto: ")
      leia(produto[i].prod_cod)
      escreval("Digite o nome do produto: ")
      leia(produto[i].nome)
      escreval("Digite o preço do produto: ")
      leia(produto[i].preco)
   fimpara
   escreval("Código Produto Preço")
   para i de 1 ate 2 faca:
      escreva(produto[i].prod_cod)
      escreva(produto[i].nome)
      escreva(produto[i].preco)
      escreval()
   fimpara
   escreva("Digite o código de um produto: ")
   leia(cod_digitado)
   para i de 0 ATÉ 100 faca:
      se (produto[i].prod_cod == cod_digitado) entao:
         escreva("O produto é um ",produto[i].nome, " que custa ",produto[i].preco)
      fimse
   fimpara
Fimalgoritmo