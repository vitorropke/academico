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
     escreval("Digite o nome do indiv�duo: ")
     leia(pessoas[i].nome)
     escreval("Digite a altura do indiv�duo: ")
     leia(pessoas[i].altura)
     escreval("Digite o peso do indiv�duo: ")
     leia(pessoas[i].peso)
     escreval("Digite o CPF do indiv�duo: ")
     leia(pessoas[i].cpf)
     escreval("Digite o sexo do indiv�duo: ")
     leia(pessoas[i].sexo)
     pessoas[i].imc<-pessoas[i].peso/(pessoas[i].altura**2)
fimpara
escreval("Digite o CPF do indiv�duo que desejas consultar: ")
leia(bus)

para i de 1 ate 2 faca
     se bus=pessoas[i].cpf entao
        escreval("O nome do indiv�duo �: ",pessoas[i].nome)
        escreval("A altura do indiv�duo �: ",pessoas[i].altura)
        escreval("O peso do indiv�duo �: ",pessoas[i].peso)
        escreval("O CPF do indiv�duo �: ",pessoas[i].cpf)
        escreval("O sexo do indiv�duo �: ",pessoas[i].sexo)
        escreval("O IMC do indiv�duo �",pessoas[i].imc)
     fimse
fimpara

Fimalgoritmo