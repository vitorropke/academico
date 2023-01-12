with open("entrada.txt", 'r') as arquivo_entrada:
	entrada = arquivo_entrada.read()

with open("raizes.txt", 'w') as arquivo_saida:
	saida = ""
	dicionario = []

	# encontra todos os caracteres diferentes e insere esses caracteres no dicionário e na saída
	for caractere_entrada in entrada:
		caractere_encontrado_saida = False

		for i, caractere_saida in enumerate(saida):
			# É feita a comparação somente nos caracteres pares da saída.
			# Isso serve para deixar passar possíveis barras de espaços que vem da entrada
			if ((i % 2) == 0) and (caractere_saida == caractere_entrada):
				caractere_encontrado_saida = True
				break

		if not caractere_encontrado_saida:
			saida += caractere_entrada + ' '
			dicionario.append(caractere_entrada)

	# remove o espaço que ficou no final
	saida = saida[:-1]

	arquivo_saida.write(saida)

print(f"Dicionário antes da compressão: {dicionario}")
prefixo = ""
sequencia_codificada = []
for caractere_atual in entrada:
	combinacao_atual = prefixo + caractere_atual

	if combinacao_atual in dicionario:
		prefixo = combinacao_atual
	else:
		dicionario.append(combinacao_atual)

		# texto comprimido recebe a posição do prefixo no dicionário
		sequencia_codificada.append(dicionario.index(prefixo))

		prefixo = caractere_atual

	print(f"\nCaractere atual:  {caractere_atual}")
	print(f"Sequência atual:  {sequencia_codificada}")
	print(f"Dicionário atual: {dicionario}")

# texto comprimido recebe a última combinação atual
sequencia_codificada.append(dicionario.index(prefixo))

print(f"\nSequência final:  {sequencia_codificada}")
print(f"Dicionário final: {dicionario}")

with open("sequencia_codificada.txt", 'w') as arquivo_saida:
	saida = ""

	for i in sequencia_codificada:
		saida += str(i) + ' '

	# remove o espaço que ficou no final
	saida = saida[:-1]

	arquivo_saida.write(saida)
