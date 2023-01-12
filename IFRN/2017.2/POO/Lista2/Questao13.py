x=int(input("Digite um número: "))
div=0
for numeros in range(1,x):
    for divisores in range(1,numeros+1):
        if numeros%divisores==0:
            div+=1
    if div<=2:
        print(numeros)
    div=0
