n=int(input("Digite aqui um número: "))
for x in range(0,n):
    if(n>0):
        print(x+1,end=' ')
if(n<0):
    print("O numero digitado deve ser positivo. O algoritmo não será execultado.")
