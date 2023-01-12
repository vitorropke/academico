Algoritmo "semnome"

tipo

func=registro
mat: inteiro
nome: caractere
salBruto, INSS, salLiq: real
fimregistro

Var

funcionario: vetor [0..80] de func
i: inteiro

Inicio

para i de 1 ate 2 faca
     escreva ("Digite a matrícula do funcionário: ")
     leia (funcionario[i].mat)
     escreva ("Digite o nome do funcionário: ")
     leia (funcionario[i].nome)
     escreva ("Digite o salário do funcionário: ")
     leia (funcionario[i].salBruto)
fimpara

para i de 1 ate 2 faca
funcionario[i].INSS <- funcionario[i].salBruto * 0.11
funcionario[i].salLiq <- funcionario[i].salBruto - funcionario[i].INSS
fimpara

escreval ("Matrícula Nome SalBruto INSS SalLiq")
para i de 1 ate 2 faca
     escreva (funcionario[i].mat)
     escreva (funcionario[i].nome)
     escreva (funcionario[i].salBruto)
     escreva (funcionario[i].INSS)
     escreva (funcionario[i].salLiq)
     escreval
fimpara

Fimalgoritmo