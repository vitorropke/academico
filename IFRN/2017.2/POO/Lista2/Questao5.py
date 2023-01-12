numero=float(input("Digite um número: "))
maior=numero

for x in range(9):
    numero=float(input("Digite um número: "))
    if numero>maior:
        maior=numero

print(maior)
