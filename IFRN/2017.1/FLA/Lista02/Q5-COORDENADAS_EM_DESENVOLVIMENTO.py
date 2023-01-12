Ax = float(input("Digite as coordenadas de Ax: "))
Ay = float(input("Digite as coordenadas de Ay: "))
Bx = float(input("Digite as coordenadas de Bx: "))
By = float(input("Digite as coordenadas de By: "))

Dab=(((Ax-Bx)**2+(Ay-By)**2)*1/2)

a_círculo=3.14*((Dab/2)**2)
a_quadrado=(Dab**2)*(Dab**2)

if (Dab>3):
	print("A distância entre os pontos é {}.".format(Dab))
	print("É um círculo de área {}".format(a_círculo))

elif (Dab<3):
	if ((Ax==Bx) and (Ay==By)):
		print("A distância é zero! Precisa calcular nada!")
	else:
		print("A distância entre os pontos é {}.".format(Dab))
		print("É quadrado de área {}".format(a_quadrado))
	
