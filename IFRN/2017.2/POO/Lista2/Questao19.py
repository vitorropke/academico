nota=float(input("Digite a nota: "))
menor=nota
maior=nota
cont_nota=0
soma_nota=0
while nota>=0:
    if nota>maior:
        maior=nota
    if nota<menor:
        menor=nota
    cont_nota+=1
    soma_nota+=nota
    nota=float(input("Digite a nota: "))

media=soma_nota/cont_nota

print("Foram digitadas {} notas.".format(cont_nota))
print("Maior nota: ", maior)
print("Menor nota: ", menor)
print("Média da turma: ", media)
