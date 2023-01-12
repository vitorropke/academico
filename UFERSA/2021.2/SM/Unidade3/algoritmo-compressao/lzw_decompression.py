with open("raizes.txt", 'r') as arquivo_raizes:
	raizes = arquivo_raizes.read()
	dicionario = []

	for i, raiz in enumerate(raizes):
		# as raízes estão nos caracteres pares da 'string'
		if (i % 2) == 0:
			dicionario.append(raiz)

with open("sequencia_codificada.txt", 'r') as arquivo_sequencia_codificada:
	string_sequencia_codificada = arquivo_sequencia_codificada.read()
	sequencia_codificada = []

	codigo_atual = ""
	for i in string_sequencia_codificada:
		if i == ' ':
			sequencia_codificada.append(int(codigo_atual))
			codigo_atual = ""
		else:
			codigo_atual += i

	sequencia_codificada.append(int(codigo_atual))

print(f"Sequência codificada:  {sequencia_codificada}")
print(f"Dicionário antes da descompressão: {dicionario}")

# texto descomprimido recebe o primeiro caractere
indice_prefixo = sequencia_codificada[0]
texto_descomprimido = dicionario[indice_prefixo]

# itera a partir do segundo valor da sequência
for codigo_atual in sequencia_codificada[1:]:
	prefixo = dicionario[indice_prefixo]

	# se o código atual estiver no dicionário
	if codigo_atual < len(dicionario):
		texto_descomprimido += dicionario[codigo_atual]
		caractere = dicionario[codigo_atual][0]
		dicionario.append(prefixo + caractere)
	else:
		caractere = dicionario[indice_prefixo][0]
		texto_descomprimido += prefixo + caractere
		dicionario.append(prefixo + caractere)

	indice_prefixo = codigo_atual

	print(f"\nÍndice do prefixo atual:   {indice_prefixo}")
	print(f"Caractere atual:           {caractere}")
	print(f"Texto descomprimido atual: {texto_descomprimido}")
	print(f"Dicionário atual:          {dicionario}\n")

print(texto_descomprimido)

with open("texto_descomprimido.txt", 'w') as arquivo_saida:
	arquivo_saida.write(texto_descomprimido)
