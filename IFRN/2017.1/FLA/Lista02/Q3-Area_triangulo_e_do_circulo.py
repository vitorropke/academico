base_do_triangulo = float(input("Digite o valor da base do triângulo: "))
altura_do_triangulo = float(input("Digite o valor da altura do triângulo: "))
raio_do_circulo = float(input("Digite o valor do raio do círculo: "))

area_do_triangulo = (base_do_triangulo*altura_do_triangulo)/2
area_do_circulo = 3.14159265359*(raio_do_circulo**2)

print("Área do triângulo é {}".format(area_do_triangulo))
print("Área do círculo é {}".format(area_do_circulo))

if (area_do_triangulo > area_do_circulo):
	print("Área do triângulo é maior que a área do círculo")

elif (area_do_circulo > area_do_triangulo):
	print("Área do círculo é maior que a área do triângulo")

else:
	print("A área do círculo e do triângulo são iguais")
