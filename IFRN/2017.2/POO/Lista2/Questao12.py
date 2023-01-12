numero=int(input("Digite um número: "))
div=0
for x in range(1,numero+1):
    if numero%x==0:
        div+=1

if div<=2:
    print("O número é primo.")
else:
    print("O número não é primo.")
