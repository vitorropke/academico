num_1=int(input("Digite um número: "))
num_2=int(input("Digite outro número: "))

mdc=num_1
while num_1 % mdc != 0 or num_2 % mdc != 0: 
  mdc = mdc - 1

print("MDC: ", mdc)

if num_1 > num_2:
    maior = num_1
else:
    maior = num_2

while True:
    if maior % num_1 == 0 and maior % num_2 == 0:
        print("MMC: ", maior)
        break
    else:
        maior += 1
