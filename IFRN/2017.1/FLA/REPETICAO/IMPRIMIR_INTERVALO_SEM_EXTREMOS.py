n=int(input("Digite um valor: "))
m=int(input("Digite um valor: "))

if (n>m):
        a=n
        n=m
        m=a
for x in range(n+1,m):
        if (n>0 and m>0):
                print(x,end=' ')
if (n<0 or m<0):
        print("O valor digitado deve ser positivo. O algoritmo não será execultado.")
#SE N<M CONTAGEM PROGRESSIVA
