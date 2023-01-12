a = bool(input("Digite um valor a: "))
b = bool(input("Digite um valor b: "))
c = bool(input("Digite um valor c: "))

if (((a or b and c) or a)):
	print("VERDADEIRO!")
else:
        print("FALSO")
