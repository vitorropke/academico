a=int(input('Digite um número: '))
par=0
impar=0

lista_par=[]
lista_impar=[]

while (a>=0):
    if (a%2==0):
        par=par+1
        lista_par=lista_par+[a]
    a=int(input('Digite um número: '))
    if (a%2==1):
        impar=impar+1
        lista_impar=lista_impar+[a]
    
print('Números pares: {} e números ímpares: {}'.format(par, impar))
print('Os números pares foram {} e os números ímpares foram {}'.format(lista_par, lista_impar))
