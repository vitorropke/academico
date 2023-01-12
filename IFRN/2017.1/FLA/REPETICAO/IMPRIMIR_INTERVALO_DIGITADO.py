n=int(input("Digite um valor: "))
m=int(input("Digite outro valor: "))

if (n<m):
        for x in range(n,m+1):
                if (n>0 and m>0):
                        print(x,end=' ')
else:
        for x in range(n,m-1,-1):
                if (n>0 and m>0):
                        print(x,end=' ')
if (n<0 or m<0):
        print("O número digitado deve ser positivo. O algoritmo não será execultado.")
#SE N>M CONTAGEM REGRESSIVA
