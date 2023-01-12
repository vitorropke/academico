nota1 = int(input("Digite a nota1: "))
nota2 = int(input("Digite a nota2: "))

media = (nota1 + nota2)/2

if (30 <= media <70):
	print("Sua média foi {}. Está em recuperação!". format(media))

elif (media >= 70):
        print("Parabens!!! Sua média foi {}. Está Aprovado!". format(media))

else:
        print("Fracassou mizeravelmente!!! Sua média foi {}. Está REPROVADO!!". format(media))
