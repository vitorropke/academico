soma=0

for i in range(5):
    x=int(input('Digite um número: '))
    if (x%2==0):
        soma=soma+x
    
print('O somatório é: {}'.format(soma))
