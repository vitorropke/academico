lado_1=float(input("Digite o valor de um lado do triângulo: "))
lado_2=float(input("Digite o valor de um lado do triângulo: "))
lado_3=float(input("Digite o valor de um lado do triângulo: "))

maior_lado=lado_1

if lado_2>maior_lado:
    maior_lado=lado_2
if lado_3>maior_lado:
    maior_lado=lado_3

if maior_lado==lado_1:
    hipotenusa=(lado_2**2+lado_3**2)**0.5
    if hipotenusa==lado_1:
        print("Este é um triângulo retângulo.")
    else:
        print("Este não é um triângulo retângulo.")

if maior_lado==lado_2:
    hipotenusa=(lado_1**2+lado_3**2)**0.5
    if hipotenusa==lado_2:
        print("Este é um triângulo retângulo.")
    else:
        print("Este não é um triângulo retângulo.")

if maior_lado==lado_3:
    hipotenusa=(lado_2**2+lado_1**2)**0.5
    if hipotenusa==lado_3:
        print("Este é um triângulo retângulo.")
    else:
        print("Este não é um triângulo retângulo.")
