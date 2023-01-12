nome = input("Digite seu nome: ")
genero = input("Digite seu gênero (F/M): ")

if (genero == "F"):
    estado_civil = input("Você é casada? (s/n): ")
    if (estado_civil == "s"):
        print("Seu nome é {} e seu estado civil é casada".format(nome))
    else:
        print("Seu nome é {} e seu estado civil é solteira".format(nome))
	
else:
        idade = input("Digite sua idade: ")
        print("Seu nome é {} e sua idade é {}".format(nome, idade))
