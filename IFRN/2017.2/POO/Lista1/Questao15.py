lado_1=float(input("Digite o valor do lado do triângulo: "))
lado_2=float(input("Digite o valor do lado do triângulo: "))
lado_3=float(input("Digite o valor do lado do triângulo: "))

if lado_1==lado_2==lado_3:
    print("Este triângulo é equilátero.")
elif lado_1==lado_2!=lado_3 or lado_1==lado_3!=lado_2 or lado_3==lado_2!=lado_1:
    print("Este triângulo é isósceles.")
else:
    print("Este triângulo é escaleno.")
