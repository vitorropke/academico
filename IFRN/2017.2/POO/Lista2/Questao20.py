n=int(input("Digite quantos números da série de Fibonacci deve aparecer: "))
contador=1
anterior=0
actual=1
while contador<=n:
    print(actual)
    posterior = anterior
    anterior=actual
    actual=anterior+posterior
    contador+=1
