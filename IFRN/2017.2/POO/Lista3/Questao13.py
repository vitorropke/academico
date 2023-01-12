num_pessoas=int(input("Digite o número de pessoas: "))

nome=[0 for x in range(num_pessoas)]
idade=[0 for x in range(num_pessoas)]
altura=[0 for x in range(num_pessoas)]
massa=[0 for x in range(num_pessoas)]
imc=[0 for x in range(num_pessoas)]
soma_anormal=0

for x in range(num_pessoas):
    nome[x]=input("Digite o nome da pessoa: ")
    idade[x]=int(input("Digite a idade da pessoa: "))
    altura[x]=float(input("Digite a altura da pessoa: "))
    massa[x]=float(input("Digite a massa da pessoa: "))
    imc[x]=massa[x]/altura[x]**2
    if imc[x]<18.5 or imc[x]>23:
        soma_anormal+=1

print("NOME | IDADE | ALTURA | MASSA | IMC | CATEGORIA DE PESO")
for x in range(num_pessoas):
    print(nome[x], " ", idade[x], "   ", altura[x], "   ", massa[x], " %.2f" %imc[x], end='   ')
    if imc[x]<18.5:
        print("Abaixo do peso")
    elif imc[x]>=18.5 and imc[x]<23:
        print("Normal")
    elif imc[x]>=23 and imc[x]<25:
        print("Sobrepeso")
    elif imc[x]>=25 and imc[x]<30:
        print("Obesidade moderada")
    else:
        print("Obesidade severa")

print("Percentual de pessoas fora do peso: ", soma_anormal/num_pessoas*100, "%")
