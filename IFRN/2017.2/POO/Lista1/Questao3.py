#a
x=float(input("Digite um valor para x: "))

print("f(x)=x/3")
print("f({})={}/3".format(x,x))
print("f({})={}".format(x,x/3))
print()

#b
print("f(x)=4(x+3)")
print("f({})=4({}+3)".format(x,x))
print("f({})={}".format(x,4*(x+3)))
print()

#c
print("f(x)=((4+(5x²)/(x+8))^1/2")
print("f({})=((4+(5*{}²)/({}+8))^1/2".format(x,x,x))
resposta=4+(5*x**2)
reposta=resposta/(x+8)
resposta=resposta**0.5
print("f({})={}".format(x, resposta))
print()

#d
print("f(x)=x³+4x²+16x+12")
print("f({})={}³+3*{}²+16*{}+12".format(x,x,x,x))
print("f({})={}".format(x, x**3+3*x**2+16*x+12))
