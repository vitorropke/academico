numero_1=[0 for x in range(10)]
numero_2=[0 for x in range(10)]

for x in range(10):
    numero_1[x]=float(input("Digite um número para vetor 1: "))
print()
for x in range(10):
    numero_2[x]=float(input("Digite um número para vetor 2: "))

print("Soma dos vetores: ")
for x in range(10):
    print(numero_1[x]+numero_2[x])
