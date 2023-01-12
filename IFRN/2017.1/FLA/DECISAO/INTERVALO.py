Início = float(input("Digite o início: "))
Fim = float(input("Digite o fim: "))
Valor = float(input("Digite um valor: "))

if (Início < Valor < Fim):
	print("O valor digitado está dentro do intervalo!")
	
elif (Valor < Início < Fim):
	print("O valor digitado está fora do intervalo! Valor menor que o intervalo!")

elif (Valor > Fim > Início):
	print("O valor digitado está fora do intervalo! Valor maior que o intervalo!")

elif (Início > Valor > Fim):
        print("O valor digitado está dentro do intervalo!")

elif (Valor < Início > Fim):
        print("O valor digitado está fora do intervalo! Valor menor que o intervalo!")

elif (Valor > Fim < Início):
        print("O valor digitado está fora do intervalo! Valor maior que o intervalo!")

else:
        print("Você não saiu do canto!")
