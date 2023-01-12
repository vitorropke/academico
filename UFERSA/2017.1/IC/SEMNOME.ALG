Algoritmo "semnome"

Tipo
saude=registro
nome,sexo:caractere
altura,peso,imc:real
cpf:inteiro
fimregistro


Var
pessoas: vetor[0..50] de saude
i:inteiro
bus:caractere

Inicio
para i de 1 ate 2 faca
     escreval("Digite o nome do indivíduo: ")
     leia(pessoas[i].nome)
     escreval("Digite a altura do indivíduo: ")
     leia(pessoas[i].altura)
     escreval("Digite o peso do indivíduo: ")
     leia(pessoas[i].peso)
     escreval("Digite o CPF do indivíduo: ")
     leia(pessoas[i].cpf)
     escreval("Digite o sexo do indivíduo: ")
     leia(pessoas[i].sexo)
     pessoas[i].imc<-pessoas[i].peso/(pessoas[i].altura**2)
fimpara
escreval("Digite o CPF do indivíduo que desejas consultar: ")
leia(bus)

para i de 1 ate 2 faca
     se bus=pessoas[i].cpf entao
        escreval("O nome do indivíduo é: ",pessoas[i].nome)
        escreval("A altura do indivíduo é: ",pessoas[i].altura)
        escreval("O peso do indivíduo é: ",pessoas[i].peso)
        escreval("O CPF do indivíduo é: ",pessoas[i].cpf)
        escreval("O sexo do indivíduo é: ",pessoas[i].sexo)
        escreval("O IMC do indivíduo é",pessoas[i].imc)
     fimse
fimpara

Fimalgoritmo