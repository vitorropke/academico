import time

alfabeto = [0 for x in range(2)]

#Entrada de dados para o alfabeto de no máximo 2 itens inteiros
#Primeiro item
while True:
	try:
		alfabeto[0] = int(input("Informe o primeiro valor inteiro do alfabeto: "))

	#Exceção caso o usuário não informe valores válidos
	except ValueError:
		print("Você deve informar um valor inteiro. Tente novamente.\n")
	else:
		break

#Segundo item
while True:
	try:
		alfabeto[1] = int(input("Informe o segundo valor inteiro do alfabeto: "))

		#Se o segundo item for igual ao primeiro
		while(alfabeto[0] == alfabeto[1]):
			print("O elemento não pode ser igual ao primeiro. Tente novamente.\n")
			alfabeto[1] = int(input("Informe o segundo valor inteiro do alfabeto: "))
	
	#Exceção caso o usuário não informe valores válidos
	except ValueError:
		print("Você deve informar um valor inteiro. Tente novamente.\n")
	else:
		break

print()

#Entrada de dados para o número de estados. Será o número de linhas da matriz de estados
while True:
	try:
		numeroEstados = int(input("\nDigite o número de estados que você irá colocar: "))
		
		#Se o número de estados informado não for maior que zero
		while(numeroEstados <= 0):
			print("Você deve informar um valor maior que zero.\n")
			numeroEstados = int(input("Digite o número de estados que você irá colocar: "))
	
	#Exceção caso o usuário não informe valores válidos
	except ValueError:
		print("Você deve informar um valor inteiro. Tente novamente.\n")
	else:
		break

print()

#Entrada do estado inicial e final
while True:
	try:
		estadoInicial = int(input("Digite o estado inicial: "))

		#Se o estadoInicial for menor que 0 ou maior que o número de estados
		while(estadoInicial < 0 or estadoInicial > numeroEstados):
			print("Você deve informar um estado entre 0 e {}.\n".format(numeroEstados))
			estadoInicial = int(input("Digite o estado inicial: "))
	
	#Exceção caso o usuário não informe valores válidos
	except ValueError:
		print("Você deve informar um valor inteiro. Tente novamente.\n")
	else:
		break

while True:
	try:
		estadoFinal = int(input("Digite o estado final(aceitação): "))

		#Se o estadoInicial for menor que 0 ou maior que o número de estados
		while(estadoFinal < 0 or estadoFinal > numeroEstados):
			print("Você deve informar um estado entre 0 e {}.\n".format(numeroEstados))
			estadoFinal = int(input("Digite o estado final(aceitação): "))
	
	#Exceção caso o usuário não informe valores válidos
	except ValueError:
		print("Você deve informar um valor inteiro. Tente novamente.\n")
	else:
		break

print()

linhas = numeroEstados+1
colunas = 2
estados = [[0 for x in range(colunas)] for y in range(linhas)]

#Entrada dos caminhos do autômato. Para onde ir quando tenho um determinado valor. Para qual estado devo ir se receber um valor x do alfabeto.
for x in range(linhas):
	for y in range(colunas):
		while True:
			try:
				estados[x][y] = int(input("Digite o estado de destino. Estado atual: Q{}, valor: {}: ".format(x, alfabeto[y])))

				#Se o estado inserido for menor que 0 ou maior que o número de estados
				while(estados[x][y] < 0 or estados[x][y] > numeroEstados):
					print("Você deve informar um estado entre 0 e {}.\n".format(numeroEstados))
					estados[x][y] = int(input("Digite o estado de destino. Estado atual: Q{}, valor: {}: ".format(x, alfabeto[y])))
			
			#Exceção caso o usuário não informe valores válidos
			except ValueError:
				print("Você deve informar um valor inteiro. Tente novamente.\n")
			else:
				break

print()

#Impressão do autômato
print("\nAutômato implementado\n")
for x in range(linhas):
	for y in range(colunas):
		print("Estado: Q{}, valor: {} --> Destino: Q{}".format(x,y, estados[x][y]))

print()

#Entrada da cadeia
loop = True
while(loop == True):
	while True:
		try:
			tamanhoDaCadeia = int(input("Digite o tamanho da cadeia: "))

			#Se o tamanho da cadeia for menor que 0
			while(tamanhoDaCadeia <= 0):
				print("Digite um valor maior que zero.\n")
				tamanhoDaCadeia = int(input("Digite o tamanho da cadeia: "))
		
		#Exceção caso o usuário não informe valores válidos
		except ValueError:
			print("Você deve informar um valor inteiro. Tente novamente.\n")
		else:
			break
	
	cadeia = [0 for x in range(tamanhoDaCadeia)]

	#Entrada dos valores da cadeia para cada posição
	for x in range(tamanhoDaCadeia):
		while True:
			try:
				cadeia[x] = int(input("Digite um número que consta no alfabeto para a posição {} da cadeia: ".format(x+1)))

				#Se algum elemento da cadeia for diferente dos valores do alfabeto
				while(cadeia[x] != alfabeto[0] and cadeia[x] != alfabeto[1]):
					print("Você deve informar um valor que conste no alfabeto.\n")
					cadeia[x] = int(input("Digite um número que consta no alfabeto para a posição {} da cadeia: ".format(x+1)))
			
			#Exceção caso o usuário não informe valores válidos	
			except ValueError:
				print("Você deve informar um valor inteiro. Tente novamente.\n")
			else:
				break
	
	print()

	#Teste de aceitação da cadeia
	estadoAtual = estadoInicial
	for x in range(tamanhoDaCadeia):

		#Se o valor atual da cadeia for igual ao valor que existe no alfabeto
		if(cadeia[x] == alfabeto[0]):

			#Estado atual recebe o próximo estado de acordo com o estadoAtual e o alfabeto[0]. Matrix[x][y] x=linha(estado) e y=coluna(alfabeto)
			estadoAtual = estados[estadoAtual][0]
		else:
			estadoAtual = estados[estadoAtual][1]
		print("Estado atual: Q{}".format(estadoAtual))
		time.sleep(1)
	
	if(estadoAtual == estadoFinal):
		print("\nCadeia aceita!\n")
	else:
		print("\nCadeia não aceita!\n")
	
	while True:
		try:
			loop = int(input("Deseja inserir outra cadeia? Digite 1 para sim e 0 para não: "))

			#Se o usuário digitar um número diferente de 0 ou 1
			while(loop != 0 and loop != 1):
				print("Você deve informar o valor 0 ou 1.\n")
				loop = int(input("Deseja inserir outra cadeia? Digite 1 para sim e 0 para não: "))
		
		#Exceção caso o usuário não informe valores válidos	
		except ValueError:
			print("Você deve informar um valor inteiro. Tente novamente.\n")
		else:
			break
	
	print()

print("\nFim do programa!\n")