n=int(input('Digite um número inteiro: '))
m='* '

for x in range(1, n+1):
    print(m*x)

for x in range(n-1, 0, -1):
    print(m*x)
