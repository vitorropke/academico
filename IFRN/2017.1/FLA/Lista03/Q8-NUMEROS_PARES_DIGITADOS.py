total=0

valor=int(input('Quantos números desejas digitar?: '))

for i in range(valor):
    x=int(input('Digite um número: '))
    if (x%2==0):
        total=total+1

print('Foi/Foram {} número(s) par(es)'.format(total))
