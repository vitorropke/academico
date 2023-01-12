numero=float(input("Digite um número: "))
maior=numero
menor=numero
soma=numero

for x in range(19):
    numero=float(input("Digite um número: "))
    if numero>maior:
        maior=numero
    if numero<menor:
        menor=numero
    soma+=numero

print("Maior: ", maior)
print("Menor: ", menor)
print("Media: ", soma/20)
