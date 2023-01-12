nota1 = float(input("Digite sua 1ª nota: "))
nota2 = float(input("Digite sua 2ª nota: "))

MÉDIA = (nota1*2 + nota2*3)/5

if (MÉDIA < 30):
	print("Média: {} - REPROVADO".format(MÉDIA))
	
elif (30 <= MÉDIA < 60):
	print("Média: {} - RECUPERAÇÃO".format(MÉDIA))
	
elif (MÉDIA >= 60):
    print("Média: {} - APROVADO".format(MÉDIA))
    print("Média: {:.2f} - APROVADO".format(MÉDIA))
    print("Média: %f - APROVADO" % MÉDIA)
