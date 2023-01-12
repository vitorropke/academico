a=float(input("Digite o valor de a: "))
b=float(input("Digite o valor de b: "))
c=float(input("Digite o valor de c: "))

delta=b**2-4*a*c

if delta<0:
    print("Não existem raízes reais.")
elif delta==0:
    print("Equação possui apenas uma raíz")
    print(-b/(2*a))
else:
    print("Equação possui duas raízes")
    print("X1=", (-b+(delta**0.5))/(2*a))
    print("X2=", (-b-(delta**0.5))/(2*a))
