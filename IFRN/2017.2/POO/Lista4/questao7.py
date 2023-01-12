import questão6

n=int(input("Quantos números primos desejas que apareça? "))
numero=1
parador=0

while parador<n:
    if questão6.primo(numero):
        print(numero)
        parador+=1
    numero+=1
