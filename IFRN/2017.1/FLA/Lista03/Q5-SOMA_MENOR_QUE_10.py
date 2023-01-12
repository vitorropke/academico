soma=0

for x in range(5):
    x=int(input('Digite um número: '))
    if (x<10):
        soma=soma+x
    
print('O somatório é: {}'.format(soma))
